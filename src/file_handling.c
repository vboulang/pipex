/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:01:47 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/11 15:21:44 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	change_parent_input(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	to_open(t_cmd cmd, char **argv)
{
	int	fd;

	if (cmd.pnb == 0)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (fd);
}
