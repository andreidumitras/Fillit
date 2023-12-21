/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:52:47 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 20:46:23 by Andrei Dumitras  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "print_map" function prints the given matrix to the stdout.

Parameters:
 - **map: the matrix to be printed
 - size: its dimension

Return value:
 - void
*/
void print_map(char **map, int size)
{
    int i;

    i = 0;
    // for each row, print the line
    while (i < size)
    {
        ft_putendl(map[i]);
        i++;
    }
}
