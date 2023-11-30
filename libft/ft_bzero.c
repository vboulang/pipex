/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:15:56 by vboulang          #+#    #+#             */
/*   Updated: 2023/10/24 16:59:49 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*b;

	i = 0;
	b = s;
	if (!b)
		return ;
	if (n > 0)
	{
		while (i < n)
		{
			b[i] = '\0';
			i++;
		}
	}
}
