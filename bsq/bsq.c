/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:41:49 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/07 15:23:43 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horsegirls.h"

void	ft_main_wrapper_one(unsigned int total_length);
void	ft_main_wrapper_two(char *buffer);
struct map_info		ft_fill_box_info(struct map_info map_information, char *buffer);
struct map_info 	ft_box_info(char *buffer);
int		ft_minimum(int a, int b, int c);
char	*ft_get_box_characters(char *buffer);
struct map_info     ft_box_info(char *buffer);
void	ft_put_map_info(struct map_info mi);
int	    ft_converter(char *box, int ndex, struct map_info info);
char	*ft_get_box(char *buffer);
int		**ft_reserve_space_matrix(struct map_info info);
void	ft_fill_matrix_auxiliary(struct map_info info, char *box, int **matrix);
void	ft_matrix_printer(struct map_info info, int **matrix);
void	ft_free_matrix(int	**matrix, int y);
struct BSQ  ft_update_matrix_auxiliary(int **matrix, struct map_info info);
void    ft_BSQ(struct BSQ bsq, char *box, struct map_info info);

int		ft_minimum(int a, int b, int c)
{
	int	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

char	*ft_get_box_characters(char *buffer)
{
	return (ft_strndup_until_char(buffer, '\n'));
}

char	*ft_get_box(char *buffer)
{
	return (ft_strchr(buffer, '\n') + 1);
}

struct map_info		ft_fill_box_info(struct map_info map_information, char *buffer)
{
	char *aux;
	int aux_size;
	
	aux = ft_get_box_characters(buffer);
	aux_size = ft_strlen(aux);

	map_information.line_size = ft_strlen_until_char(ft_get_box(buffer), '\n');
	map_information.full_char = aux[aux_size - 1];
	map_information.obstacle_char = aux[aux_size - 2];
	map_information.empty_char = aux[aux_size - 3];
	char *number_str = (char *)malloc((aux_size - 3) * sizeof(char));
	if (number_str)
	{
        ft_strncpy(number_str, aux, aux_size - 3);
        number_str[aux_size - 3] = '\0';
		if (ft_str_is_numeric(number_str))
        	map_information.num_lines = ft_atoi(number_str);
        free(number_str);
    }
	return map_information;
}

struct map_info 	ft_box_info(char *buffer)
{
	char *aux;
	int aux_size;
	
	aux = ft_get_box_characters(buffer);
	aux_size = ft_strlen(aux);

	struct map_info map_information;
	
	map_information.line_size = -1;
	map_information.full_char = '0';
	map_information.obstacle_char = '0';
	map_information.empty_char = '0';
	map_information.num_lines = -1;
	if (aux_size >= 4)
	{
		map_information.line_size = ft_strlen_until_char(ft_get_box(buffer), '\n');
		map_information.full_char = aux[aux_size - 1];
		map_information.obstacle_char = aux[aux_size - 2];
		map_information.empty_char = aux[aux_size - 3];
		char *number_str = (char *)malloc((aux_size - 3) * sizeof(char));
		if (number_str)
		{
			ft_strncpy(number_str, aux, aux_size - 3);
			number_str[aux_size - 3] = '\0';
			if (ft_str_is_numeric(number_str))
				map_information.num_lines = ft_atoi(number_str);
			free(number_str);
		}
	}
	free(aux);
	return map_information;
}

void	ft_put_map_info(struct map_info info)
{
	ft_putnbr(info.num_lines);
	ft_putchar('\n');

	ft_putchar(info.empty_char);
	ft_putchar('\n');

	ft_putchar(info.obstacle_char);
	ft_putchar('\n');

	ft_putchar(info.full_char);
	ft_putchar('\n');

	ft_putnbr(info.line_size);
	ft_putchar('\n');
}

int		**ft_reserve_space_matrix(struct map_info info)
{
	int **matrix;
	int i;

	//reuse this space in memory in every file, or resize if needed?
	matrix = malloc(info.num_lines * sizeof(int *));
	i = -1;
	while (++i < info.num_lines)
		matrix[i] = malloc(info.line_size * sizeof(int));
	return (matrix);
}

int		ft_converter(char *box, int index, struct map_info info)
{
	if (box[index] == info.empty_char)
		return (1);
	else if (box[index] == info.obstacle_char)
		return (0);
	else
		return (-1);
}

void		ft_fill_matrix_auxiliary(struct map_info info, char *box, int **matrix)
{
	int i;
	int j;
	int index;

	index = 0;
	i = -1;
	while (++i < info.num_lines)
	{
		j = -1;
		while (++j < info.line_size)
		{
			if (box[index] == '\n')
			{
				index++;
				j--;
			}
			else
			{
				matrix[i][j] = ft_converter(box, index, info);
				index++;
			}
		}
	}
}

void		ft_matrix_printer(struct map_info info, int **matrix)
{
	int i; 
	int j;

	i = 0;
	while (i < info.num_lines)
	{
		j = 0;
		while (j < info.line_size)
		{
			ft_putnbr(matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_free_matrix(int	**matrix, int y)
{
	int i;

	i = -1;
	while(++i < y)
		free(matrix[i]);
	free(matrix);
}

struct BSQ ft_update_matrix_auxiliary(int **matrix, struct map_info info)
{
	struct BSQ bsq;
	int i; 
    int j;

	bsq.size = 0;
	bsq.x = -1;
	bsq.y = -1;
	i = -1;
    while (++i < info.line_size)
	{
        j = -1;
        while (++j < info.num_lines) 
		{
            if (i > 0 && j > 0 && matrix[i][j] == 1)
                matrix[i][j] = ft_minimum(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
            if (matrix[i][j] > bsq.size) 
			{
                bsq.size = matrix[i][j];
                bsq.x = i;
                bsq.y = j;
            }
        }
    }
	//ft_free_matrix(matrix, info.line_size);
	return bsq;
}

void ft_BSQ(struct BSQ bsq, char *box, struct map_info info)
{
    int i;
	int j;
    int index;

    i = -1;
    while (++i < info.num_lines)
    {
        j = -1;
        while (++j < info.line_size)
        {
            index = i * (info.line_size + 1) + j;
            if (i >= bsq.x - bsq.size + 1 && i <= bsq.x && j >= bsq.y - bsq.size + 1 && j <= bsq.y)
            {
                if (box[index] != '\n')
                    ft_putchar(info.full_char);
                else
                    ft_putchar('\n');
            }
            else
            {
                if (box[index] != '\n')
                    ft_putchar(box[index]);
                else
                    ft_putchar('\n');
            }
        }
        ft_putchar('\n');
    }
    if (bsq.size == 0)
        ft_putstr("No BSQ found in this map\n");
}

void	ft_main_wrapper_one(unsigned int total_length)
{
	char *buffer;
	struct map_info info;
    struct BSQ bsq;
    char *box;
    int **matrix;

	buffer = read_console(&total_length);
	info = ft_box_info(buffer);
	box = ft_get_box(buffer);
	//your validations go here
	matrix = ft_reserve_space_matrix(info);
	ft_fill_matrix_auxiliary(info, box, matrix);
	bsq = ft_update_matrix_auxiliary(matrix, info);
	ft_BSQ(bsq, box, info);
	free(buffer);
}

void	ft_main_wrapper_two(char *buffer)
{
	struct map_info info;
    struct BSQ bsq;
    char *box;
    int **matrix;

	info = ft_box_info(buffer);
	box = ft_get_box(buffer);
	//your validations go here
	matrix = ft_reserve_space_matrix(info);
	ft_fill_matrix_auxiliary(info, box, matrix);
	ft_matrix_printer(info, matrix);
	bsq = ft_update_matrix_auxiliary(matrix, info);
	ft_putchar('\n');
	ft_matrix_printer(info, matrix);
	ft_BSQ(bsq, box, info);
}
