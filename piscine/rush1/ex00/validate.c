/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkomarof <jkomarof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:13:16 by jkomarof          #+#    #+#             */
/*   Updated: 2024/02/25 15:23:14 by jkomarof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_rush01_out(int ***table, int size);

void	check_valid_up(int ***table, int size, int i, int *error)
{
	int	j;
	int	n;
	int	s;

	if (table[2][0][i] != 1 && table[2][0][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *error == 0 && s != size)
		{
			if (table[0][j][i] > s)
			{
				n++;
				s = table[0][j][i];
			}
		}
		if (table[2][0][i] != n)
			*error = 1;
	}
}

void	check_valid_down(int ***table, int size, int i, int *error)
{
	int	j;
	int	n;
	int	s;

	if (table[2][1][i] != 1 && table[2][1][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *error == 0 && s != size)
		{
			if (table[0][size - j - 1][i] > s)
			{
				n++;
				s = table[0][size - j - 1][i];
			}
		}
		if (table[2][1][i] != n)
			*error = 1;
	}
}

void	check_valid_left(int ***table, int size, int i, int *error)
{
	int	j;
	int	n;
	int	s;

	if (table[2][2][i] != 1 && table[2][2][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *error == 0 && s != size)
		{
			if (table[0][i][j] > s)
			{
				n++;
				s = table[0][i][j];
			}
		}
		if (table[2][2][i] != n)
			*error = 1;
	}
}

void	check_valid_right(int ***table, int size, int i, int *error)
{
	int	j;
	int	n;
	int	s;

	if (table[2][3][i] != 1 && table[2][3][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *error == 0 && s != size)
		{
			if (table[0][i][size - j - 1] > s)
			{
				n++;
				s = table[0][i][size - j - 1];
			}
		}
		if (table[2][3][i] != n)
			*error = 1;
	}
}

int	check_valid(int ***table, int size)
{
	int	i;
	int	error;

	i = -1;
	error = 0;
	while (++i < size && error == 0)
	{
		check_valid_up(table, size, i, &error);
		check_valid_down(table, size, i, &error);
		check_valid_left(table, size, i, &error);
		check_valid_right(table, size, i, &error);
	}
	if (error == 0)
	{
		ft_rush01_out(table, size);
		free(table);
		return (1);
	}
	return (0);
}
