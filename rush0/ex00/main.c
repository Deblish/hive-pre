/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsolanki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:01:03 by tsolanki          #+#    #+#             */
/*   Updated: 2024/02/18 13:31:38 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_putchar(char c);
void rush(int x, int y);

void	ft_putstr(char *str)
{
	while	(*str != 0)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_string_to_int(char *str)
{	
	int integer = 0;
	while	(*str != 0)
	{
		integer = integer * 10 + *str - '0'; //ascii value for zero would also work
		str++;
	}
	return (integer);
}

int	main(int argc, char *argv[])
{
	char	*str; //error msg is stored here

	if	(argc != 3)
	{
		//anything different than three (exec file name, int1, int2) is wrong
		str = "Ups, please write two integers as arguments\n";
		ft_putstr(str);
		return (1);
	}

	if	(argc == 3)
	{
		int x;
		int y;

		int i;
		i = 1;

		x = ft_string_to_int(argv[1]);
		y = ft_string_to_int(argv[2]);

		if (x > 0 && y > 0)
			rush(x,y);
		
		return (0);
	}
}
