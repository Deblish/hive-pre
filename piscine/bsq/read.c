/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:40:27 by djelacik          #+#    #+#             */
/*   Updated: 2024/03/06 21:36:09 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horsegirls.h"

void	ft_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_realloc(char *ptr, unsigned int new_size, unsigned int old_size)
{
	char	*new_ptr;

	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}

char	*read_file(const char *filename, unsigned int *size)
{
	int		fd;
	char	*data;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	data = read_data(fd, size);
	close(fd);
	return (data);
}

char	*read_data(int fd, unsigned int *size)
{
	unsigned int	buffer_size;
	unsigned int	bytes_read;
	char			*buffer;
	char			*new_buffer;

	buffer_size = 8;
	buffer = malloc(buffer_size);
	if (!buffer)
		return (NULL);
	*size = 0;
	while (1)
	{
		bytes_read = read(fd, buffer + *size, buffer_size - *size);
		if (bytes_read <= 0)
			break ;
		*size += bytes_read;
		if (*size >= buffer_size)
		{
			new_buffer = realloc_or_free(buffer, buffer_size *= 2, *size);
			if (!new_buffer)
				return (NULL);
			buffer = new_buffer;
		}
	}
	return (buffer);
}

char	*realloc_or_free(char *buffer, int new_size, int current_size)
{
	char	*new_buffer;

	new_buffer = ft_realloc(buffer, new_size, current_size);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (new_buffer);
}

char	*read_console(unsigned int *data_size)
{
	unsigned int	buffer_size;
	unsigned int	index;
	char			*buffer;
	char			*new_buffer;
	char			c;

	buffer_size = 4;
	buffer = malloc(buffer_size);
	if (!buffer)
		return (NULL);
	index = 0;
	while (read(0, &c, 1) > 0)
	{
		if (index >= buffer_size - 1)
		{
			new_buffer = realloc_or_free(buffer, buffer_size *= 2, index);
			if (!new_buffer)
				return (NULL);
			buffer = new_buffer;
		}
		buffer[index++] = c;
	}
	buffer[index] = '\0';
	*data_size = index;
	return (buffer);
}
