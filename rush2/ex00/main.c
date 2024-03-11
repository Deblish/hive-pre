/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:24:50 by aapadill          #+#    #+#             */
/*   Updated: 2024/03/03 21:05:50 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usefulheader.h"

int    main(int argc, char **argv) 
{
    int number;
    int error;
    int is_number;

    error = 0;
    if (argc == 2) 
    {
        is_number = ft_str_is_numeric(argv[1]);
        if (is_number)
        {
            number = ft_atoi(argv[1]);
            ft_dictionary("numbers.dict");
        }
        else
            error = -1;
    }
    else if (argc == 3)
    {
        is_number = ft_str_is_numeric(argv[2]);
        if (is_number)
        {
            number = ft_atoi(argv[2]);
            error = ft_dictionary(argv[1]);
        }
        else
            error = -1;
    }
    if (error <= -1)
        ft_putstr("Error\n");
    return (0);
}
