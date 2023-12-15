/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:12 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/15 17:18:00 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


char	*get_path(char **envp, char *str)
{
	int	i;
	int	path_not_found;
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
	i = 0;
	while (paths[i])
	{
		correct_path = ft_strjoin(paths[i], "/");
		correct_path = ft_strjoin(correct_path, str);
		if(access(correct_path, X_OK) == 0)
			return (correct_path);
		else
			free(correct_path);
		i++;
	}
	free(correct_path);
	return(NULL);//TODO message incorrect command
}

int	dupfct(int *fd, int fd_file, int nb)
{
	if (nb == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (-1); //TODO Make error message
		if (dup2(fd_file, STDIN_FILENO) == -1)
			return (-1); //TODO Make error message
	}
	else
	{
		if (dup2(fd_file, STDOUT_FILENO) == -1)
			return (-1); //TODO Make error message
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (-1); //TODO Make error message
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_file;
	int		fd[2];
	int		id;
	t_cmd	cmd;

	if (argc == 5)
	{
		cmd.pnb = 0;
		if (access(argv[1], R_OK) == -1)
			return (0); //TODO Make error message
		pipe(fd);
		while(cmd.pnb < argc-3)
		{
			id = fork();
			if (id == -1)
				return (printf("fork failed")); //TODO Make error message
			if (id == 0)
			{
				if (cmd.pnb == 0)
					fd_file = open(argv[1], O_RDONLY);
				else
					fd_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
				if (fd_file == -1)
					return (printf("open failed")); //TODO Make error message
				if (dupfct(fd, fd_file, cmd.pnb) == -1)
					return (printf("failed dup")); //TODO Make error message and change if comparison to match error returned
				close(fd[0]);
				close(fd[1]);
				close(fd_file);
				cmd.cmd = ft_split(argv[cmd.pnb + 2], ' ');
				cmd.path = get_path(envp, cmd.cmd[0]);
				if (!cmd.path)
					return(printf("path not found"));
				if (execve(cmd.path, cmd.cmd, NULL) == -1)
					return (printf("failed command")); //TODO Make an error message
			}
			cmd.pnb += 1;
		}
	}
	else
		return (printf("Nope\n")); //TODO Make error message
	return (0);
}
