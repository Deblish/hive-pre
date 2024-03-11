/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:40:34 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/21 11:48:40 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*original;

	original = dest;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n)
	{
		*dest++ = '\0';
		n--;
	}
	return (original);
}
/*
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char *strncpy;
	char destination[10];
	char *source;

	source = "oh this is coooooool"; //twenty one considering the null

	strncpy = ft_strncpy(destination, source, 10);
	
	ft_putstr(source);
	ft_putstr("\n");
	ft_putstr(destination);
	ft_putstr("\n");
	int i = 0;
	while(i < 12)
	{
		char j = i + '0';
		write(1, &j, 1);
		write(1, " : ", 1);
		write(1, &destination[i], 1);
		write(1, "\n", 1);
		//printf("%c", destination[i]);
		i++;
	}

	return (0);
}
*/
