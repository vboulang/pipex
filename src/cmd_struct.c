/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:05:29 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/23 14:17:45 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_all(t_cmd cmd)
{
	int	i;

	if (cmd.cmd)
	{
		i = 0;
		while (cmd.cmd[i])
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

void	free_and_exit(t_cmd cmd, int status)
{
	free_all(cmd);
	exit(status);
}

void	initialize_struct(t_cmd *cmd)
{
	cmd->pnb = 0;
	cmd->cmd = NULL;
	cmd->path = NULL;
	cmd->infile_ok = 0;
}
