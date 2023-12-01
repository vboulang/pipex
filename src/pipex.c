/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:34:12 by vboulang          #+#    #+#             */
/*   Updated: 2023/12/01 16:49:49 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		if(access(argv[1], F_OK) != 0)
			return (0);
		
		(void)argv;
		//TODO check/open files?
		//TODO open infile
		//TODO execute first command reading from infile and output to pipe
			//TODO execute done in a child with execve
		//TODO execute second command from pipe to outfile
	}
	else
		return (0);
	return (0);
}
