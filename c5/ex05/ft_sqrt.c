/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:50:12 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 12:57:17 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	root;

	if (nb == 1)
		return (1);
	root = 0;
	while (root <= nb / 2 && root < 46341)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	int x;
	x = 24;
	printf("%i", ft_sqrt(x));
}
*/
