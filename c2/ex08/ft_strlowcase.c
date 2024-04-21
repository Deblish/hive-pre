/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:09:43 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/21 14:44:50 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

char	*ft_strlowcase(char	*str)
{
	char	*original;

	original = str;
	while (*str)
	{
		if (*str < '[' && *str > '@')
			*str += 32;
		str++;
	}
	return (original);
}
/*
int main (void)
{
	char str[50] = "ASASASasasaAFLFLFLadadaaddad";

	//char *str2;
	//str2 = "asasasas";//string literal, read only?

	char *ptr;
	ptr = ft_strlowcase(str);

	//printf("%s", ptr);
	write(1, ptr, 50);
	return 0;
}
*/
