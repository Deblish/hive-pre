/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkomarof <jkomarof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:42:23 by jkomarof          #+#    #+#             */
/*   Updated: 2024/02/25 14:43:58 by jkomarof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**args(int argc, char **argv, int *nargs);
void	gen(int **locked, int size);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	**board;
	int	size;

	board = args(argc, argv, &size);
	if (board != NULL)
	{
		gen(board, size);
	}
	else
		ft_putstr("Error\n");
}
