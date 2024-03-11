/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:43:57 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/23 09:24:19 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char	*str, char	*to_find)
{
	char	*haystack;
	char	*needle;

	if (!*to_find)
		return (str);
	while (*str)
	{
		haystack = str;
		needle = to_find;
		while (*haystack == *needle && *needle)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return (str);
		str++;
	}
	return ((void *)0);
}
/*
int	main (void)
{
	char	*str;
	str = ft_strstr("pppo", "ppo");
	printf("%s", str);
}
*/
