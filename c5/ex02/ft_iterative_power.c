/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:17:27 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 11:11:24 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power == 0)
	{
		if (nb >= 0)
			return (1);
		else
			return (-1);
	}
	if (power < 0)
		return (0);
	power += 1;
	result = 1;
	while (--power)
		result *= nb;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_iterative_power(-20, 0));
	return 0;
}
*/
