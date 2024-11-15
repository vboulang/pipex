/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:08 by vboulang          #+#    #+#             */
/*   Updated: 2024/01/23 15:34:21 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
	int		max;
	int		infile_ok;
}	t_cmd;

//Struct related functions (located in cmd_struct_bonus.c)
void	initialize_struct(t_cmd *cmd, int argc);
void	free_all(t_cmd cmd);
void	free_and_exit(t_cmd cmd, int status);

//Pipex main functions (in pipex_bonus.c)
int		main(int argc, char **argv, char **envp);
void	child(t_cmd cmd, char **argv, char **envp);
void	pipex(t_cmd cmd, char **argv, char **envp);
void	to_execute(t_cmd cmd, char **argv, char **envp);
void	execution(t_cmd cmd, char **argv, char **envp);

//Path related functions (in path_bonus.c)
char	*test_path(char **paths, char *str);
char	*get_path(char **envp, char *str);

//Fd related functions (in file_handling_bonus.c)
int		change_parent_input(int fd);
int		to_open(t_cmd cmd, char **argv);
void	parent(t_cmd *cmd);

#endif