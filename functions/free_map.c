/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:53:39 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:21:19 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "free_map" function recieves a char matrix and its size and frees the allocated memory for it.

Parameters:
 - **map: the matrix to be freed
 - size: the dimensions of the matrix

Return value:
 - void
*/
void free_map(char **map, int size)
{
    int i;      // the index for rows

    i = 0;
    // traversing each row
    while (i < size)
    {
        // freeing each row
        free(map[i]);
        i++;
    }
    // freeing the matrix
    free(map);
}
