/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:18:20 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/22 20:36:08 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
/*
int main(void)
{
	char d[50] = "abcdefghi";
	char s[] = "123456789";
	char *ptr = ft_strcat(d, s);
	write(1, &d, 50);
	return 0;
}
*/
