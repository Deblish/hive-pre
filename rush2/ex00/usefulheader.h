/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefulheader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srautvuo <srautvuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:43:02 by srautvuo          #+#    #+#             */
/*   Updated: 2024/03/03 20:55:31 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef USEFULHEADER_H
#define USEFULHEADER_H

typedef struct
{
    char key[128];
    char value[128];
} dictionary;

void	ft_putstr(char	*str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int    ft_atoi(char *str);
int ft_strlen(char *src);
char	*ft_strdup(char *src);
char	*ft_strchr(char *str, char c);
long double ft_atold(char *str);
char    *ft_isspace(char *str);
char    *ft_isprintable(char *str);
char	*ft_strncat(char	*dest, char	*src, unsigned int nb);
char	*ft_strcat(char	*dest, char	*src);
char    *ft_compress_spaces(char *str);
char    *ft_strndup_until_colon(char *src);
int		ft_str_is_numeric(char *str);
int     ft_dictionary(char *file_name);

#endif
