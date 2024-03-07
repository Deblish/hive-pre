/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horsegirls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:29:54 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/04 13:03:45 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef HORSEGIRLS_H
#define HORSEGIRLS_H
#define BUFFER_SIZE 1
#define INITIAL_BUFFER_SIZE 8

struct map_info{
    int num_lines;
    char empty_char;
    char obstacle_char;
    char full_char;
    int line_size;
};

struct BSQ{
    int size;
    int x;
	int y;
};

int	    ft_digit_counter(int j);
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

void	ft_main_wrapper_one(unsigned int total_length);
void	ft_main_wrapper_two(char *buffer);
struct map_info		ft_fill_box_info(struct map_info map_information, char *buffer);
struct map_info 	ft_box_info(char *buffer);
int		ft_minimum(int a, int b, int c);
char	*ft_get_box_characters(char *buffer);
struct map_info ft_box_info(char *buffer);
void	ft_put_map_info(struct map_info mi);
int	ft_converter(char *box, int ndex, struct map_info info);
char	*ft_get_box(char *buffer);
int		**ft_reserve_space_matrix(struct map_info info);
void	ft_fill_matrix_auxiliary(struct map_info info, char *box, int **matrix);
void	ft_matrix_printer(struct map_info info, int **matrix);
void	ft_free_matrix(int	**matrix, int y);
struct BSQ ft_update_matrix_auxiliary(int **matrix, struct map_info info);
void    ft_BSQ(struct BSQ bsq, char *box, struct map_info info);

char	*read_file(const char *path, unsigned int *size);
char	*read_data(int fd, unsigned int *size);
char	*read_console(unsigned int *size);
char	*ft_realloc(char *ptr, unsigned int new_size, unsigned int old_size);
void	ft_memcpy(char *dest, const char *src, unsigned int n);
char	*realloc_or_free(char *buffer, int new_size, int current_size);

#endif
