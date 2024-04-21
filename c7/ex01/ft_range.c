/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:57:01 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/29 18:40:56 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*array;
	int	i;

	if (min >= max)
		return (0);
	else
	{
		range = max - min;
		array = (int *)malloc(range * sizeof(int));
		i = 0;
		while (i < range)
		{
			array[i] = min + i;
			i++;
		}
		return (array);
	}
}
/*
#include <stdio.h>
int main (void)
{
	int i;
	int *a;
	a = ft_range(1, 10);
	i = 0;
	while(i < 9)
	{
		printf("%i", a[i]);
		i++;
	}
}
*/
