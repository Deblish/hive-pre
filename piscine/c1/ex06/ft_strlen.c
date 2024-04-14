/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:02:53 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/18 17:36:14 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str)
	{
		strlen++;
		str++;
	}
	return (strlen);
}
//int main (void)
//{
//	int	len;
//	char	*str;
//
//	str = "hi";
//	len = ft_strlen(str);
//	printf("%i", len);
//	return 0;
//}
