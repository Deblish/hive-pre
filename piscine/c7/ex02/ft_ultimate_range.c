/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:57:40 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 10:42:12 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*array;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(size * sizeof(int));
	if (array != NULL)
	{
		i = 0;
		while (i < size)
		{
			array[i] = min + i;
			i++;
		}
		*range = array;
		return (size);
	}
	else
		return (-1);
}
/*
#include <stdio.h>
int	main(void)
{
	int **b;
	int saved;
	int i;
	saved = ft_ultimate_range(b, ' ', '~');
	printf("%i\n", saved);
	i = 0;
	int *a;
	a = *b;
	//printf("%p", a);
	while (i < saved)
	{
		printf("%i\n", *a);
		//printf("%p", (void *)a);
		a++;
		i++;
	}
	return 0;
}
*/
