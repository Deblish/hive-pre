/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsolanki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:23:33 by tsolanki          #+#    #+#             */
/*   Updated: 2024/02/18 12:16:57 by tsolanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	column;
	int	row;

	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			if (row == 1 && column == 1)
				ft_putchar('/');
			else if ((row == 1 && column == x) || (row == y && column == 1))
				ft_putchar(92);
			else if (row == y && column == x)
				ft_putchar('/');
			else if (row == 1 || row == y || column == 1 || column == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
