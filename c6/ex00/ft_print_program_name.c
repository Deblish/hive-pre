/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:30:45 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/28 19:06:58 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 1)
	{
		str = argv[0];
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
