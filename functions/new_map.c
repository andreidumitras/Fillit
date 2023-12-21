/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:52:17 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 20:44:09 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "new_map" function allocate memory for a new square matrix of characters
 > It fills the new matrix with '.'s

Parameters:
 - size - the dimension of the new matrix.

Return value:
 - a pointer to the newly created matrix
 - NULL in case of errors.
*/
char **new_map(int size)
{
    int     i;
    char    **map;

    i = 0;
    // allocate the number of rows
    map = (char **)malloc(sizeof(char *) * size);
    // for each row allocate the number of columns
    while (i < size)
    {
        // allocate a new column of length "size"
        map[i] = (char *)malloc(sizeof(char) * (size + 1));
        // initialize the column with dots.
        ft_memset(map[i], '.', size);
        // terminate the column with '\0'.
        map[i][size] = '\0';
        i++;
    }
    // returns the new matrix
    return (map);
}
