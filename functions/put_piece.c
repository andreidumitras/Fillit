/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:14:18 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 20:51:49 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "pune_piesa" function fills in the working matrix, the symbol associated for each piece.

Parameters:
 - *p: the pointer for the current piece of the queue
 - **map: the working matrix where the piece will be put
 - i: the starting row where to put the piece
 - j: the starting column where to put the piece

Return value:
 - void
*/
void pune_piesa(t_etris *p, char **map, int i, int j)
{
    int k;

    k = 0;
    // traverse the string of coordinates associated with the given piece
    while (k < 8)
    {
        // offseting the coordinates with i and j.
        map[i + p->piesa[k] - '0'][j + p->piesa[k + 1] - '0'] = p->litera;
        k += 2;
    }
}
