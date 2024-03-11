/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:19:22 by aapadill          #+#    #+#             */
/*   Updated: 2024/02/21 18:31:45 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strcapitalize(char	*str)
{
	int		separator;
	char	*original;

	separator = 1;
	original = str;
	while (*str)
	{
		if (separator && ('a' <= *str && *str <= 'z'))
		{
			*str -= 32;
			separator = 0;
		}
		else if (('0' <= *str && *str <= '9') || ('a' <= *str && *str <= 'z'))
			separator = 0;
		else if ('A' <= *str && *str <= 'Z')
			*str += 32;
		else if (('0' <= *str && *str <= '9') || ('a' <= *str && *str <= 'z'))
			separator = 0;
		else
			separator = 1;
		str++;
	}
	return (original);
}
/*
int	main (void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	//char *str2;
	//str2 = "asasasas";//string literal, read only?

	char *ptr;
	ptr = ft_strcapitalize(str);

	//printf("%s", ptr);
	write(1, ptr, 50);
	return 0;
}
*/
