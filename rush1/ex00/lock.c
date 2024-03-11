/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkomarof <jkomarof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:42:14 by jkomarof          #+#    #+#             */
/*   Updated: 2024/02/25 15:11:23 by jkomarof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	lock_hori(int ***table, int **board, int size, int i)
{
	int	j;

	if (board[0][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][j][i] = j + 1;
	}
	else if (board[0][i] == 1)
		table[1][0][i] = size;
	if (board[1][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][size - j - 1][i] = j + 1;
	}
	else if (board[1][i] == 1)
		table[1][size - 1][i] = size;
}

void	lock_vert(int ***table, int **board, int size, int i)
{
	int	j;

	if (board[2][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][i][j] = j + 1;
	}
	else if (board[2][i] == 1)
		table[1][i][0] = size;
	if (board[3][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][i][size - j - 1] = j + 1;
	}
	else if (board[3][i] == 1)
		table[1][i][size - 1] = size;
}

void	assemble(int ***table, int **board, int size, int i)
{
	int	j;

	j = -1;
	table[2][i] = malloc(sizeof(int) * size);
	while (++j < size)
	{
		table[2][i][j] = board[i][j];
	}
}

void	lock(int ***table, int **board, int size)
{
	int	i;

	table[2] = malloc(sizeof (int *) * 4);
	i = -1;
	while (++i < 4)
	{
		lock_hori(table, board, size, i);
		lock_vert(table, board, size, i);
		assemble(table, board, size, i);
	}
}
