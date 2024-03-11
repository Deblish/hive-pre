/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:18:56 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 11:08:02 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	n = nb + 1;
	while (--n)
		if (n != 1)
			nb *= (n - 1);
	return (nb);
}
/*
#include <stdio.h>
int main (void)
{
	int a;
	a = ft_iterative_factorial(13);
	printf("%i", a);
}
*/
