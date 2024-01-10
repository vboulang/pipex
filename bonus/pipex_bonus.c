/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:12 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/10 16:45:26 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	*test_path(char **paths, char *str)
{
	int		i;
	char	*correct_path;

	i = 0;
	while (paths[i])
	{
		correct_path = ft_strjoin(paths[i], "/");
		correct_path = ft_strjoin(correct_path, str);
		if (access(correct_path, X_OK) == 0)
			return (correct_path);
		else
			free(correct_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *str)
{
	int		i;
	int		path_not_found;
	char	**paths_to_split;
	char	**paths;
	char	*correct_path;

	i = 0;
	path_not_found = 1;
	while (envp[i] && path_not_found)
	{
		if (!ft_strnstr(envp[i], "PATH", 4))
			i++;
		else
			path_not_found = 0;
	}
	paths_to_split = ft_split(envp[i], '=');
	paths = ft_split(paths_to_split[1], ':');
	correct_path = test_path(paths, str);
	if (!correct_path)
		return (NULL);
	else
		return (correct_path);
}

int	dupfct(int *fd, int fd_file, int nb)
{
	if (nb == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (-1);
		if (dup2(fd_file, STDIN_FILENO) == -1)
			return (-1);
	}
	else
	{
		if (dup2(fd_file, STDOUT_FILENO) == -1)
			return (-1);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (-1);
	}
	return (0);
}

int	to_open(t_cmd cmd, char **argv)
{
	int	fd;

	if (cmd.pnb == 0)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open(argv[cmd.max + 3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (fd);
}

void	free_all(t_cmd cmd)
{
	int	i;
	
	if (cmd.cmd)
	{
		i = 0;
		while(cmd.cmd[i])
		{
			free(cmd.cmd[i]);
			cmd.cmd[i] = NULL;
			i++;
		}
		free(cmd.cmd);
		cmd.cmd = NULL;
	}
	if (cmd.path)
	{
		free(cmd.path);
		cmd.path = NULL;
	}
}

void	child(t_cmd cmd, char **argv, char **envp)
{
	int	fd_file;

	if (cmd.pnb == cmd.max)
	{
		fd_file = to_open(cmd, argv);
		if (fd_file == -1)
			perror("File cannot be opened. ");
		else if (dup2(fd_file, STDOUT_FILENO) == -1)
			perror("Problems with files. ");
		close(fd_file);
	}
	else
	{
		if (dup2(cmd.fd[1], STDOUT_FILENO) == -1)
			perror("Problems with files. ");
	}
	close(cmd.fd[0]);
	close(cmd.fd[1]);
	cmd.cmd = ft_split(argv[cmd.pnb + 2], ' ');
	cmd.path = get_path(envp, cmd.cmd[0]);
	if (!cmd.path)
		perror("Command not found. ");
	execve(cmd.path, cmd.cmd, NULL);
	perror("Execution failed. ");
	free_all(cmd);
	exit(0);
}

int	change_parent_input(int fd_file)
{
	if (dup2(fd_file, STDIN_FILENO) == -1)
		return (-1);
	close(fd_file);
	return (0);
}

void	pipex(t_cmd cmd, char **argv, char **envp)
{
	int	pid;
	int	status;
	int	fd_file;
	
	fd_file = to_open(cmd, argv);
	if (fd_file == -1)
		perror("File cannot be opened. ");
	if(change_parent_input(fd_file) == -1)
		perror("Problems with files. ");
	while (cmd.pnb++ <= cmd.max)
	{
		dprintf(2, "%i", cmd.pnb);
		pipe(cmd.fd);
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed.");
			close(cmd.fd[0]);
		}
		if (pid == 0)
			child(cmd, argv, envp);
		else
			change_parent_input(cmd.fd[0]);
		close(cmd.fd[1]);
		waitpid(pid, &status, 0);
		//cmd.pnb += 1;
	}
}

void	initialize_struct(t_cmd *cmd, int argc)
{
	cmd->pnb = -1;
	cmd->max = argc - 4;
	cmd->cmd = NULL;
	cmd->path = NULL;
	
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;

	if (argc >= 5)
	{
		initialize_struct(&cmd, argc);
		if (access(argv[1], R_OK) == -1)
			perror("Can't open file. ");
		pipex(cmd, argv, envp);
	}
	else
		return (printf("Wrong number of argument.\n"));
	return (0);
}
