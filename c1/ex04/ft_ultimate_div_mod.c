/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:11:17 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/18 17:32:41 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
//int main(void)
//{
//	int a = 0;
//	int b = 0;
//
//	a = 10;
//	b = 0;
//	ft_ultimate_div_mod(&a, &b);
//
//	printf("%i, %i", a, b);
//	return 0;
//}
