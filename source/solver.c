/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:56:19 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 22:33:09 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
Description:
 > Verifies the matrix values at the given coordinates to check if there is space to place the piece.
 > Is the piece is overwriting something else, a signal will be returned.

Parameters:
 - *p: the current piece, characterized by the string of coordinates
 - **map: the matrix in which the piece is tried to be placed.
 - x: the x coordinate of the matrix (analogue of i)
 - y: the y coordinate of the matrix (analogue of j)

Return value:
 - 0 if something goes wrong.
 - 1 if all goes well.
*/
int verificare(t_etris *p, char **map, int x, int y)
{
    int i;          // the index for the string of coordinates

    i = 0;
    // for each pair of coordinates stored inside the "piesa" field
    while (i < 8)
    {
        // check if at the given coordinates, the matrix has free space.
        // if something else is there placed in the past (e.g. another piece), 0 is returned.
        if (map[p->piesa[i] - '0' + x][p->piesa[i + 1] - '0' + y] != '.')
            return (0);
        // increment by 2 because the function verifies pairs of coordinates (x, y), so increase by 2.
        i += 2;
    }
    // if all went well, the piece will be placed at (x, y) coordinates.
    pune_piesa(p, map, x, y);
    // return 1 for success
    return (1);
}

/*
Description:
 > The "repozitionare" function receives a piece to be replaced.
 > It fills with '.' the spaces where the piece was placed before.

Parameters:
 - *piese: the piece to be erased
 - **map: the matrix where the piece resides
 - i: the starting x coordinate of the piece
 - j: the starting y coordinate of the piece

Return value:
 - void
*/
void repozitionare(t_etris *piese, char **map, int i, int j)
{
    int k;          // the index for the string of coordinates

    k = 0;
    // traverse the string of coordinates stored inside the field "piesa"
    while (k < 8)
    {
        // fill with '.'s the matrix at the specified coordinates
        map[i + piese->piesa[k] - '0'][j + piese->piesa[k + 1] - '0'] = '.';
        k += 2;
    }
}

/*
Description:
 > The "back_tetris" function is doing backtracking while trying to place the list of pieces into the given matrix.
 > If it could place a piece at the a certain pair of coordinate, it will go to the next piece.
 > If not, the piece will be replaced to a new pair of coordinates.

Parameters:
 - *piese: the queue of pieces to be placed
 - **map: the matrix in which the pieces will be placed
 - size: the dimension of the matrix map

Return value:
 - 0 if an error occurs.
 - 1 if all is good.
*/
int back_tetris(t_etris *piese, char **map, int size)
{
    int i;          // index for the rows
    int j;          // index for the columns

    // safety check for a null pointer
    if (!piese)
        return (1);
    i = 0;
    // traverse the rows until the current piece can be placed.
    // place it first on row 0, then try on row 1, and so on.
    // until row (size - height), because if it will be placed on row (size - height + 1), the piece will be out of bounds.
    while (i <= size - piese->height)
    {
        j = 0;
        // place the piece initially on col 0, until col (size - width)
        while (j <= size - piese->width)
        {
            // if the piece is well placed inside the matrix, backtracking will continue to the next piece.
            if (verificare(piese, map, i, j))
            {
                // try placing the next piece. If the backtracking for the next pieces failes, the current piece will be replaced.
                if (!(back_tetris(piese->next, map, size)))
                    repozitionare(piese, map, i, j);
                else
                    return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

/*
Description:
 > The "solve" tries to arrange the given list of pieces into the smallest square matrix.
 > It allocates a minimum matrix and tries to possitionate pieces via backtracking, until all of the pieces are placed accordingly.
 > If the size of the matrix is not sufficient, the old matrix will be freed and a larger one will be created.
 > The process continues until all the pieces are in place and they have enough space.
 > When the process is over, the solution matrix will be printed to stdout.

Parameters:
 - *piese: the list of pieces

Return value:
 - 0 if an error occurs
 - 1 if succeded.
*/
int solve(t_etris *piese)
{
    int     size;           // the dimension of the matrix
    int     cate;           // the amount of pieces to place
    char    **map;          // the working matrix

    // get the number of pieces stored inside the "piese" queue.
    cate = cate_piese(piese);
    // the starting size of the created matrix (size rows x size cols) will be 2
    size = 2;
    // compute the required size, in terms of the amount of pieces
    while (size * size < cate * 4)
        size++;
    // allocate a dynamic char matrix of the computed size. If allocation failes, 0 is returned.
    if (!(map = new_map(size)))
        return (0);
    // try to arrange the pieces into the smallest square possible via backtracking.
    // if the pieces cannot be arranged inside the created matrix, then a new one will be created with a grater size.
    while (back_tetris(piese, map, size) == 0)
    {
        // free the matrix
        free_map(map, size);
        // increase the size
        size++;
        // and try to allocate a larger matrix
        if (!(map = new_map(size)))
            return (0);
    }
    // at the end, print the pieces arranged into the smallest square matrix.
    print_map(map, size);
    return (1);
}
