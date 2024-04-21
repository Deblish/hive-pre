/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:57:36 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 14:08:29 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 1;
	while (++i <= nb / 2)
		if (nb % i == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		while (ft_is_prime(nb) != 1)
			nb++;
	return (nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%i", ft_find_next_prime(2147483647));
	return 0;
}
*/
