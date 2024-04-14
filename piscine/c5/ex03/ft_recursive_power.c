/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:14:01 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 11:14:21 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power != 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else if (power < 0)
		return (0);
	else if (nb < 0)
		return (-1);
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_recursive_power(-1, 0));
	return 0;
}*/
