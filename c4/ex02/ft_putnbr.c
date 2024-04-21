/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:27:21 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/27 16:27:53 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_exponential(int base, int exp)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}

int	ft_digit_counter(int j)
{
	int	i;

	i = 1;
	while (j >= 10)
	{
		j /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	int		digits;
	int		a;
	int		b;
	char	digit_char;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	digits = ft_digit_counter(nb);
	while (digits)
	{
		b = (nb % (ft_exponential(10, digits - 1)));
		a = nb - b;
		digit_char = (a / (ft_exponential(10, digits - 1))) + '0';
		write(1, &digit_char, 1);
		nb = b;
		digits--;
	}
}

int	main(void)
{
	ft_putnbr(991213);
}
