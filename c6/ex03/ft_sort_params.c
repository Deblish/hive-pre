/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:38:46 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/28 19:58:55 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char	*s1, char	*s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_print(int argc, char **argv)
{
	int		i;
	char	*args;

	if (argc > 0)
	{
		i = 1;
		while (i < argc)
		{
			args = argv[i];
			while (*args)
			{
				write(1, args, 1);
				args++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc > 1)
	{
		j = 1;
		while (j < argc)
		{
			i = 1;
			while (i < argc - 1)
			{
				while (ft_strcmp(argv[i], argv[i + 1]) > 0)
					ft_swap(&argv[i], &argv[i + 1]);
				i++;
			}
			j++;
		}
		ft_print(argc, argv);
	}
	return (0);
}
