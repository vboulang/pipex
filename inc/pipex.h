/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:08 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/09 14:18:09 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/inc/libft.h"

typedef struct s_cmd
{
	char	*path;
	char	**cmd;
	int		pnb;
	int		fd[2];
}	t_cmd;

int	main(int argc, char **argv, char **envp);

#endif