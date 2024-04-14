/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:36:56 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/22 15:26:13 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char	*dest, char	*src, unsigned int nb)
{
	char	*original;

	original = dest;
	while (*dest)
		dest++;
	while (*src && nb)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (original);
}
/*
int main(void)
{
	char d[50] = "abcdefghi";
	char s[] = "123456789";
	char *ptr = ft_strncat(d, s, 4);
	write(1, &d, 50);
	return 0;
}
*/
