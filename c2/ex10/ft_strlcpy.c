/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:34:56 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/21 18:43:18 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*src)
	{
		if (size)
		{
			*dest++ = *src++;
			size--;
			i++;
		}
		else
		{
			i++;
			src++;
		}
	}
	*dest++ = '\0';
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/*
int	main(void)
{
	int strlcpy;
	char destination[25];
	char *source;

	source = "ohhhhh this is cooler hehe"; //twenty one considering the null

	strlcpy = ft_strlcpy(destination, source, 5);
	
	ft_putstr(""); ////////
	ft_putstr(source);
	ft_putstr("\n");
	ft_putstr(destination);
	ft_putstr("\n");
	printf("%i characteres were tried\n", strlcpy);
	
	int i = 0;
	while(i < strlcpy)
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
