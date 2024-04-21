/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:23:04 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/06 21:58:41 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horsegirls.h"

int		ft_digit_counter(int j);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_atoi(char *str);
int		ft_str_is_numeric(char *str);
void	ft_putstr(char	*str);
int		ft_strlen(char *src);
int		ft_strlen_until_char(char *src, char c);
char	*ft_isspace(char *str);
char	*ft_isprintable(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strndup_until_char(char *src, char c);

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
	char	x;

	x = 0;
	if (nb < 10)
	{
		x = nb + '0';
		write(1, &x, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		x = (nb % 10) + '0';
		write(1, &x, 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	ft_putstr(char	*str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	ft_strlen_until_char(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

char	*ft_isspace(char *str)
{
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	return (str);
}

char	*ft_isprintable(char *str)
{
	while (*str < ' ' || *str > '~')
		str++;
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != c)
		if (!*str++)
			return (NULL);
	return (str);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	char	*result;

	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest < src)
		return (0);
	result = dest;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (result);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

char	*ft_strndup_until_char(char *src, char c)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (src[i] != '\0' && src[i] != c)
		i++;
	dest = (char *)malloc((i * sizeof(char)) + 1);
	if (dest == NULL)
		return (NULL);
	while (++j < i)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}
