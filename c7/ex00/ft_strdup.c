/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:33:54 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/29 20:57:29 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	char	*result;

	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest < src)
		return (0);
	result = dest;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *str;
	str = ft_strdup("duplicate");
	printf("%s", str);
}
*/
