/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:24:54 by vboulang          #+#    #+#             */
/*   Updated: 2023/10/24 16:57:23 by vboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!haystack || !needle)
		return (NULL);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i] && needle[j]
				&& haystack[i] == needle[j] && i < n)
			{
				if (!needle[j + 1])
					return ((char *)haystack + (i - j));
				i++;
				j++;
			}
		}
		i = i - j + 1;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n%s\n", strnstr(av[1], av[2], 10), ft_strnstr(av[1], av[2], 10));
}*/
