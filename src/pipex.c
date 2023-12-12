/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:12 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/12 14:13:29 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	int	fd_file;
	int	fd[2];
	int	id;

	if (argc == 5)
	{
		if (access(argv[1], R_OK) == -1)
			return (0); //TODO Make error message
		pipe(fd);
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
			if (execve() == -1)
				return (0); //TODO Make an error message
		}
	}
	else
		return (0); //TODO Make error message
	return (0);
}
