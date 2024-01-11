/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:17:07 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/11 14:32:42 by vboulang         ###   ########.fr       */
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
