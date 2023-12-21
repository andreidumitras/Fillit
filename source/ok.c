/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:13:09 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 21:46:46 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
Description:
 > The "conex" function counts the neighboring '#'s.
 > The number of neighboring '#'s describes if the piece is dislocated or not.

Parameters:
 - *s: a string that holds a piece, as an array of characters.

Return value:
 - the count of neighboring '#'s
*/
int conex(char *s)
{
    int i;                  // index for string traversing
    int diez;               // count of '#'

    i = 0;
    diez = 0;
    while (i < 20)
    {
        if (s[i] == '#')
        {
            // if the current character is a '#', then it must have at least 1 neighbouring '#'.
            // look to the left
            if (i > 0 && s[i - 1] == '#')
                diez++;
            // look above
            if (i > 4 && s[i - 5] == '#')
                diez++;
            // look to the right
            if (i < 19 && s[i + 1] == '#')
                diez++;
            // look down
            if (i < 15 && s[i + 5] == '#')
                diez++;
        }
        i++;
    }
    // return the amount of neighboring '#'s.
    return (diez);
}

/*
Description:
 > The "ok" function verifies that the piece os well formatted.

Parameters:
 - *s: a string that holds a Tetris piece, as an array of characters.
 - cat: the amount of characters read.

Return value:
 - 1 if all the input verifications are good.
 - 0 if input has an error.
*/
int ok(char *s, int cat)
{
    int i;                  // the index for traversing the string
    int diez;               // the count for '#'s

    i = 0;
    diez = 0;
    // verify each character
    while (i < 20)
    {
        // verify if the character is inside a line or not (a line has 4 characters)
        if (i % 5 < 4)
        {
            // verify if the current character is different than '.'s and '#'s.
            if (!(s[i] == '#' || s[i] == '.'))
                return (0);
            // count the '#'s
            if (s[i] == '#')
                diez++;
        }
        // the 5th should be a '\n'; if not, the input is not ok.
        else if (s[i] != '\n')
            return (0);
        i++;
    }
    // check the amount of '#' to be 4
    // check the read amount to be 21
    // check if the last character is a '\n'
    if (diez != 4 || (cat == 21 && s[20] != '\n'))
        return (0);

    // check if the piece pointed by s has 6 or 8 connection points.
    if (conex(s) != 6 && conex(s) != 8)
        return (0);
    // return 1 if all the criteria were met.
    return (1);
}
