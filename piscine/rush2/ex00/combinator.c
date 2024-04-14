/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:03:13 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/03 11:39:51 by srautvuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "usefulheader.h" 

int	main(void)
{
	int buffer_size;
	int line_size;
	int	file;
	int is_key;
	char *buffer;
	char *line;
	char *key;
	char *value;
	size_t line_pos;
	size_t key_pos;
	size_t value_pos;
	ssize_t reader;

	line_pos = 0;
	key_pos = 0;
	value_pos = 0;
	is_key = 0;

	file = open("numbers.dict", O_RDONLY);
	if (file < 0)
		return (-1);
	buffer = (char *)malloc(1024 * sizeof(char));
	buffer[0] = 0;
	line = (char *)malloc(1024 * sizeof(char));
	key = (char *)malloc(512 * sizeof(char));
	value = (char *)malloc(512 * sizeof(char));

	while((reader = read(file, buffer, sizeof(buffer))) > 0)
	{
		size_t i;
		i = 0;
		while (i < (size_t)reader)
		{
			if (buffer[i] == '\n' || buffer[i] == '\r' || line_pos >= 1024)
			{
				line[line_pos] = '\0';

				key_pos = 0;
				value_pos = 0;
				is_key = 1;
			}
			else if (buffer[i] == ':')
				is_key = 0;
			else
			{
				if (is_key)
				{
					if (key_pos < 512)
					{
						key[key_pos++] = buffer[i];
						key[key_pos] = '\0';
					}
				}
				else
				{
					if (value_pos < 512)
					{
						value[value_pos++] = buffer[i];
						value[value_pos] = '\0';
					}
				}
				line[line_pos++] = buffer[i];
			}
			i++;
		}
	}

	if(reader < 0)
	{
		close(file);
		return -1;
	}
	close(file);

	printf("%s", line);

	while()
	return (0);
}
