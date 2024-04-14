/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:17:56 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/20 12:56:27 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
/*
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
*/

char	*ft_strcpy(char *dest, char *src)
{
	char	*original;

	original = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (original);
}

/*
int	main(void)
{
	char *strcpy;
	char destination[50];
	char *source;

	source = "oh this is coooooool";

	int i = 0;
	
	//char *original;
	//original = source;
	//while(*source)
	//{
	//	destination[i] = '\0';
	//	i++;
	//	source++;
	//}
	//source = original;

	strcpy = ft_strcpy(destination, source);
	
	ft_putstr(source);
	ft_putstr("\n");
	ft_putstr(destination);

	return (0);
}
*/
