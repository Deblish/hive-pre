/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:14:46 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 11:09:51 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	res *= ft_recursive_factorial(res - 1);
	return (res);
}
/*
#include <stdio.h>
int	main (void)
{
	printf("%i", ft_recursive_factorial(13));
	return 0;
}
*/
