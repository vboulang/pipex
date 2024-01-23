/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:17:07 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/23 15:35:21 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	to_open(t_cmd cmd, char **argv)
{
	int	fd;

	if (cmd.pnb == 0)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open(argv[cmd.max + 3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (fd);
}

int	change_parent_input(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	close(fd);
	return (0);
}

void	parent(t_cmd *cmd)
{
	cmd->infile_ok = 0;
	if (change_parent_input(cmd->fd[0]) == -1)
		perror("Could not change input file descriptor. ");
}
