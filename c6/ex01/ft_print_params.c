/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:32:02 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/28 19:21:21 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
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
	return (0);
}
