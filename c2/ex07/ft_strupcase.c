/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:27:02 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/21 14:43:28 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

char	*ft_strupcase(char	*str)
{
	char	*original;

	original = str;
	while (*str)
	{
		if (*str < '{' && *str > '`')
			*str -= 32;
		str++;
	}
	return (original);
}
/*
int main (void)
{
	char str[50] = "abcdefghijklmnopqrstuvwxyz";
	
	//char *str2;
	//str2 = "asasasas";//string literal, read only?

	char *ptr;
	ptr = ft_strupcase(str);

	//printf("%s", ptr);
	write(1, ptr, 50);
	return 0;
}
*/
