/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:23:50 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/29 18:27:42 by aapadill         ###   ########.fr       */
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

char	*ft_strcat(char	*dest, char	*src)
{
	char	*original;

	original = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (original);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	int		i;
	char	*dest;

	if (size < 1)
		return ((char *)malloc(sizeof(char)));
	total = 0;
	i = -1;
	while (++i < size)
		total += ft_strlen(strs[i]);
	total += (ft_strlen(sep) * (size - 1));
	dest = (char *) malloc((total + 1) * sizeof(char));
	dest[0] = 0;
	i = -1;
	while (++i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i != (size - 1))
			ft_strcat(dest, sep);
	}
	ft_strcat(dest, "\0");
	return (dest);
}
/*
#include <stdio.h>
int main (void)
{
	char *strs[3];
	char *meta;
	char *str1;
	char *str2;
	char *str3;

	str1 = "hi";
	str2 = "there";
	str3 = "people";

	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;

	//printf("%i", ft_strlen(strs[2]));
	meta = ft_strjoin(3, strs, "*------*");
	printf("%s", meta);
	return 0;
}
*/
