/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:57:41 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/27 11:16:43 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_isspace(char *str)
{
	while ((*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f' || *str == 32) && str)
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	char	*start;
	char	*end;
	int		sign;
	int		integer;

	start = ft_isspace(str);
	sign = 1;
	while (*start == '+' || *start == '-')
	{
		if (*start == '-')
			sign *= -1;
		start++;
	}
	end = start;
	while (*end && (*end >= '0' && *end <= '9'))
		end++;
	integer = 0;
	while (*start && start != end)
	{
		integer = integer * 10 + *start - '0';
		start++;
	}
	integer = integer * sign;
	return (integer);
}
/*
#include <stdio.h>
int	main (void)
{
	int	i;
	
	i = ft_atoi("   -1 ---+--+1234ab567");
	printf("%i", i);
	return 0;
}
*/
