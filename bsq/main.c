/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:44:47 by djelacik          #+#    #+#             */
/*   Updated: 2024/03/04 13:08:51 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "horsegirls.h"

int    main(int argc, char **argv) 
{
    int i;
    char *buffer;
    char *filename;
    unsigned int total_length;

    if (argc == 1)
        ft_main_wrapper_one(total_length);
    if (argc >= 2) 
    {
        i = 0;
        while (++i < argc)
        {
            if (ft_strlen(argv[i]) > 1)
            {
                buffer = read_file(argv[i], &total_length);
                if (!buffer)
                {
                    ft_putstr("map error\n");
                    continue;
                }
                ft_main_wrapper_two(buffer);
                free(buffer);
            }
            else
                ft_putstr("map error\n");
        }
    }
    return (0);
}