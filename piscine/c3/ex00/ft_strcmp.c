/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:14:31 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/22 20:34:14 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
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
/*
int	main (void)
{
	printf ("%i", ft_strcmp("thisiswillys", "thisiswildy"));
	return 0;
}
*/
