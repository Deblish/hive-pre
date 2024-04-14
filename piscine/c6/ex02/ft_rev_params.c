/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:44:02 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/28 19:25:30 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*args;
	int		i;

	if (argc > 0)
	{
		i = argc - 1;
		while (i)
		{
			args = argv[i];
			while (*args)
			{
				write(1, args, 1);
				args++;
			}
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
