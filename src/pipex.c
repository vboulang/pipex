/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:12 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/14 18:52:10 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_path(char **envp, char *str)
{
	int	i;
	int	path_not_found;
	
	i = 0;
	path_not_found = 1;
	while (envp[i] && path_not_found)
	{
		if (!ft_strnstr(envp[i], "PATH", 4))
			i++;
		else
			path_not_found = 0;
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_file;
	int		fd[2];
	int		id;
	char	*path;
	char	**cmd;

	if (argc == 5)
	{
		if (access(argv[1], R_OK) == -1)
			return (0); //TODO Make error message
		pipe(fd);

		//START LOOP
		//while()
		id = fork();
		if (id == -1)
			return (0); //TODO Make error message
		if (id == 0)
		{
			fd_file = open(argv[1], O_RDONLY);
			if (fd_file == -1)
				return (0); //TODO Make error message
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				return (0); //TODO Make error message
			if (dup2(fd_file, STDIN_FILENO) == -1)
				return (0); //TODO Make error message
			close(fd[0]);
			close(fd[1]);
			close(fd_file);
			path = get_path(envp, argv[2]); //TODO check if good path, access X_OK
			cmd = ft_split(argv[2], ' ');
			if (execve(path, cmd, NULL) == -1)
				return (0); //TODO Make an error message
		}
		//END LOOP
		id = fork();
		if (id == -1)
			return (0); //TODO Make error message
		if (id == 0)
		{
			fd_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
			if (fd_file == -1)
				return (0); //TODO Make error message
			if (dup2(fd_file, STDOUT_FILENO) == -1)
				return (0); //TODO Make error message
			if (dup2(fd[0], STDIN_FILENO) == -1)
				return (0); //TODO Make error message
			close(fd[0]);
			close(fd[1]);
			close(fd_file);
			path = get_path(envp, argv[2]); //TODO check if good path, access X_OK
			cmd = ft_split(argv[2], ' ');
			if (execve(path, cmd, NULL) == -1)
				return (0); //TODO Make an error message
		}
	}
	else
		return (0); //TODO Make error message
	return (0);
}
