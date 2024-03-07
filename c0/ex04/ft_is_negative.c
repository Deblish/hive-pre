/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:05:20 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/15 21:06:56 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	number_is;

	if (n >= 0)
	{
		number_is = 'P';
		write(1, &number_is, 1);
	}
	else
	{
		number_is = 'N';
		write(1, &number_is, 1);
	}
}
