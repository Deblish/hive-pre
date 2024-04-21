/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srautvuo <srautvuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:53:15 by srautvuo          #+#    #+#             */
/*   Updated: 2024/03/03 20:05:30 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usefulheader.h"

int		ft_atoi(char *str);
int		ft_strlen(char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strchr(char *str, char c);
long double	ft_atold(char *str);
char	*ft_isspace(char *str);
char	*ft_isprintable(char *str);
char	*ft_strncat(char	*dest, char	*src, unsigned int nb);
char	*ft_strcat(char	*dest, char	*src);
char	*ft_compress_spaces(char *str);
char	*ft_strndup_until_colon(char *src);
void	ft_putstr(char	*str);
int		ft_str_is_numeric(char *str);
int		ft_dictionary(char *file_name);

void	ft_putstr(char	*str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_strcat(char	*dest, char	*src)
{
	char	*original;

	original = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (original);
}

char	*ft_strncat(char	*dest, char	*src, unsigned int nb)
{
	char	*original;

	original = dest;
	while (*dest)
		dest++;
	while (*src && nb)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (original);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int	i;

	i = 0;
	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *src)
{
	int i;


	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;
	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

char	*ft_isspace(char *str)
{
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	return str;
}

char	*ft_isprintable(char *str)
{
	while (*str < '!' || *str > '~')
		str++;
	return str;
}


long double	ft_atold(char *str)
{
	long double	res;
	int	i;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i] - '0');
		i++;
	}
	return res;
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*original;

	original = dest;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n)
	{
		*dest++ = '\0';
		n--;
	}
	return (original);
}

char	*ft_strchr(char *str, char c) 
{
    while (*str != c) 
        if (!*str++)
            return NULL;
    return str;
}

char	*ft_compress_spaces(char *str)
{
    char *original = ft_strdup(str);
    if (original == NULL)
		return NULL;
    char *reader = original;
    char *writer = original;
    int space_found = 0;
    while (*reader)
    {
		if ((*reader >= 9 && *reader <= 13) || (*reader == 32))
        {
			if (!space_found)
			{
				*writer++ = ' ';
                space_found = 1;
            }
        }
        else
        {
            *writer++ = *reader;
            space_found = 0;
        }
        reader++;
    }
    *writer = '\0';
    return original;
}

char	*ft_strndup_until_colon(char *src)
{
    char *dest;
    int i = 0;
	int j = -1;

    while (src[i] != '\0' && src[i] != ':')
        i++;
    dest = malloc(i + 1);
	if (dest == NULL)
        return (NULL);
	while (++j < i)
		dest[j] = src[j];
	dest[j] = '\0';
    return dest;
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

int	ft_dictionary(char *file_name)
{
    int file;
    ssize_t reader;
    dictionary *dict;
    char *buffer;
    char *line;
    char *key;
    char *value;
    dictionary *dict_ptr;
    char *buffer_ptr;
    char *line_ptr;
    char *key_ptr;
    char *value_ptr;
    size_t dict_size;
    int buffer_size;
	//unsigned int key;

    buffer_size = 1024;
    dict_size = 100;

    buffer = malloc(buffer_size * sizeof(char));
    line = malloc(256 * sizeof(char));
    if (buffer == NULL || line == NULL)
   	{
        free(buffer);
		free(line);
        return (-1);
    }

    file = open(file_name, O_RDONLY);
    if (file < 0)
   	{
        free(buffer);
        free(line);
        return (-1);
    }

	dict = malloc(dict_size * sizeof(dictionary));
    if (dict == NULL)
   	{
        close(file);
        free(buffer);
        free(line);
        return (-1);
    }

    dict_ptr = dict;

    while ((reader = read(file, buffer, buffer_size)) > 0)
   	{
        buffer_ptr = buffer;
        line_ptr = line;
        while (buffer_ptr < buffer + reader)
	   	{
            if (*buffer_ptr == '\n' || *buffer_ptr == '\r' || (line_ptr - line) >= 255)
		   	{
                *line_ptr = 0;
                line_ptr = line;
                if (line_ptr >= line && ft_strchr(line, ':') != NULL && ft_str_is_numeric(ft_strndup_until_colon(line)))
			   	{	    
                    dict_ptr->key[0] = 0;
                    //key = ft_atoi(line);
					key = ft_isspace(line);
					ft_strcat(dict_ptr->key, ft_strndup_until_colon(key));
                    dict_ptr->value[0] = 0;
					value = ft_isprintable(ft_isspace(ft_strchr(line, ':') + 1));
					ft_strcat(dict_ptr->value, ft_compress_spaces(value));
                    ft_putstr(dict_ptr->key);
                    ft_putstr(" -> ");
                    ft_putstr(dict_ptr->value);
                    ft_putstr("\n");
                }
            } 
			else 
                *line_ptr++ = *buffer_ptr;
            buffer_ptr++;
        }
    }

    if (reader < 0)
   	{
        free(dict);
        close(file);
        free(buffer);
        free(line);
        return (-1);
    }
    free(dict);
    close(file);
    free(buffer);
    free(line);
    return (0);
}
