/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:08:14 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 21:34:10 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
Description:
 > The "minim" function finds the minimum pair of coordinates (the most top-left '#') from the given string.
 > It performs a linear search and returns the pair of coordinates corresponding to the most top-left '#'.

Parameters:
 - *a: a char string, containing coordinates for each '#', of a Tetris piece

Return value:
 - a structure containing the minimum values of (x, y).
*/
t_inim minim(char *a)
{
    t_inim  m;          // the auxilliary values which will hold the most top-left pair of coordinates
    int     i;          // the index for the string of coordinates

    // initialize the minimum value to the first pair of coordinates
    m.h = a[0] - '0';
    m.w = a[1] - '0';
    // start traversing the string from the second pair of coordinates
    i = 2;
    while (i < 8)
    {
        // if something less than the first pair if found, overwrite the minimum.
        if (a[i] - '0' < m.h)
            m.h = a[i] - '0';
        if (a[i + 1] - '0' < m.w)
            m.w = a[i + 1] - '0';
        // jump to the next pair
        i += 2;
    }
    return (m);
}

/*
Description:
 > The "coordonate_simple" function computes the string coordinates of each '#' that forms a piece.

Parameters:
 - **piesa: a char matrix containing the caracters of a Tetris piece

Return value:
 - the newly constructred string of coordinates.
*/
char *coordonate_simple(char **piesa)
{
    char    *a;         // the string of coordinates that will be created
    int     i;          // the index for the rows of the matrix
    int     j;          // the index for the columns of the matrix
    int     k;          // the index for the string of coordinates

    // alocate exactly 8 + 1 chars
    a = (char *)malloc(sizeof(char) * 9);
    // initialize indexes for matrix and for the string of coordinates
    i = 0;
    k = 0;
    // traverse the matrix
    while (piesa[i++])
    {
        j = 0;
        while (piesa[i - 1][j++])
        {
            // if a '#' is found, store its coordinates as characters inside the created string.
            if (piesa[i - 1][j - 1] == '#')
            {
                a[k++] = i - 1 + '0';
                a[k++] = j - 1 + '0';
            }
        }
    }
    // terminate the string with a '\0'
    a[k] = '\0';
    return (a);
}

/*
Description:
 > The "coordonate" function computes the string of normalized coordinates for each '#'

Parameters:
 - **piesa: a char matrix containing the Tetris piece
 - *h: a pointer to the height of the piece, which will modify the value of its reference
 - *w: a pointer to the width of the piece, which will modify the value of its reference

Return value:
 - the string of normalized coordinates.
*/
char *coordonate(char **piesa, int *h, int *w)
{
    char    *a;     // a string that stores all the pairs of coordinates
    t_inim  m;      // an auxiliary structure that stores (width, height) parameters
    int     i;      // index for traversing the string of coordinates

    i = 0;
    // store the coordinates for all '#'s under the form: {x1,y1,x2,y2,...}, inside a string
    a = coordonate_simple(piesa);
    // get the most top-left pair of values
    m = minim(a);

    // initialize width and height
    *w = 0;
    *h = 0;
    // normalize the string of coordinates, with respect to the most top-left coordinates
    while (i < 8)
    {
        // offsetting x coordinate with the minimum top value
        a[i] -= m.h;
        // modify the height parameter of the piece if there is an increase of height
        if (a[i] - '0' > *h)
            *h = a[i] - '0';
        // offsetting y value with the minimum left value
        a[i + 1] -= m.w;
        // modify the width parameter of the piece if there is an increase of width
        if (a[i + 1] - '0' > *w)
            *w = a[i + 1] - '0';
        // jump to the following pair of coordinates
        i += 2;
    }
    // increease with 1 each, to give a real amount (if x = 0 => height = 1, not 0)
    *h = *h + 1;
    *w = *w + 1;
    // returning the new string of coordinates
    return (a);
}

/*
Description:
 > The "read_pieces" function reads the Tetris pieces from a given file.
 > If a piece is valide, its values will be added to a queue.
 > If something goes wrong, NULL is returned.

Parameters:
 - fd: the file descriptor of the input file
 - **lst: the head of the queue which will be monified at first.

Return value:
 - the queue containing the details of all pieces
 - NULL in case of error.
*/
t_etris *read_pieces(int fd, t_etris **lst)
{
    char        line[21];       // buffer for storing a piece as characters: exactly 21 characters
    char        **piesa;        // character matrix for storing the piece
    int         cat;            // the read amount
    t_inim      size;           // an auxiliary structure value containing the withd and height values of the piece
    char        *c;             // the string of normalized coordinats

    // try to continuously read 21 characters from the file-descriptor
    while ((cat = read(fd, line, 21)) == 21)
    {
        // if the read line is not a valid piece, it returns NULL
        if (ok(line, cat) == 0)
            return (NULL);
        // if the matrix creation of the piece fails, it returns NULL
        if (!(piesa = ft_strsplit(line, '\n')))
            return (NULL);
        // find the string of normalized coordinates for each piece
        c = coordonate(piesa, &size.h, &size.w);
        // add to the queue, the string of coordinates, the width and the height of the piece
        ft_lstpush_back(lst, c, size.w, size.h);
    }
    // if the last read is not 21, the input file is not well formatted. NULL is returned.
    if (cat != 20)
        return (NULL);
    // if the read content is a valid Tetris piece and if the matrix creation succeded...
    if (ok(line, cat) && (piesa = ft_strsplit(line, '\n')))
    {
        // compute the string of coordinates for the last piece
        c = coordonate(piesa, &size.h, &size.w);
        // add the last piece to the queue
        ft_lstpush_back(lst, c, size.w, size.h);
    }
    else
        return (NULL);
    // return the queue of pieces
    return (*lst);
}

/*
Description:
 > The "main" function handles the input validation and starts the solving algorithm.

Parameters:
 - ac: the arguments count parameter.
 - **av: the arguments vector parameter which will store the input filename.

Return value:
 - 0 for the system.
*/
int main(int ac, char **av)
{
    t_etris *piese;		// list of pieces
    int     fd;			// file-descriptor for the specified file

    // handling wrong number of command line arguments
    if (ac != 2)
    {
        write(1, "usage: ./fillit [filename]\n", 27);
        return (0);
    }

    // initialize variables
    piese = NULL;
    fd = open(av[1], O_RDONLY);

    // try to read pieces from the input file and store them inside the "piese" queue
    // handling reading errors
    if (!(piese = read_pieces(fd, &piese)))
        write(1, "error\n", 6);
    else if (!(solve(piese)))		// if reading was successufl, start solving the problem
        write(1, "error\n", 6);		// handling solving errors

    // clear memory
    free_list(&piese);
    // close the file descriptor
    close(fd);
    return (0);
}
