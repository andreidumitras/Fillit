/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:37:11 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 18:04:03 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "cate" function receives a string of characters and it determines the number of words.

Parameters:
 - *s: the given string
 - c: the delimiter character

Return value:
 - the amount of words inside the string.
*/
static int cate(const char *s, char c)
{
    int cat;        // the amount of words counter

    cat = 0;
    // for each character different than '\0'
    while (*s)
    {
        // if the current character is not the delimiter, but the following is, or is '\0', increment the counter
        if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
            cat++;
        s++;
    }
    return (cat);
}

/*
Description:
 > The "cuvant" function receives a string and it counts the length of the first occurring word.

Parameters:
 - *s: the given string
 - c: the delimiter character

Return value:
 - the length of the first word.
*/
static int cuvant(const char *s, char c)
{
    int i;          // the index of the string
    int k;          // the counter that counts the length of the word.

    k = 0;
    i = 0;
    // jump over the delimiter characters (if there are multiple ones)
    while (s[i] == c)
        i++;
    // it stopped at a character different than the delimiter
    // count the number of characters that are different than '\0' or the delimiter.
    while (s[i] != c && s[i])
    {
        k++;
        i++;
    }
    return (k);
}

/*
Description:
 > The "ft_strsplit" function is a function from Libft.
 > It receives a string that must be truncated around the specified delimiter character.
 > It generates a matrix that stores all the words trimmed by delimiter

Parameters:
 - *s: the string to be trimed
 - c: the delimiter character

Return value:
 - a pointer to the new allocated matrix
 - NULL is the process failes.
*/
char **ft_strsplit(char const *s, char c)
{
    char    **a;            // the pointer which holds the matrix.
    int     i;              // index for the matrix rows
    int     j;              // index for the recieved string s
    int     k;              // index for the columns of the matrix

    i = 0;
    j = 0;
    // verify the pointers and allocate memory for the matrix's rows
    if (!s || !(a = (char **)malloc(sizeof(char *) * cate(s, c) + 1)))
        return (NULL);
    // traverse the string while filling the matrix
    while (i < cate(s, c) && s[j])
    {
        k = 0;
        // allocate memory for the new trimmed word
        if (!(a[i] = ft_strnew(cuvant(s + j, c) + 1)))
            return (NULL);
        // jump over the delimiter characters
        while (s[j] == c)
            j++;
        // start copying characters from s to the matrix, until a new delimiter character occurs
        while (s[j] != c && s[j])
            a[i][k++] = s[j++];
        // terminate the matrix column.
        a[i][k] = '\0';
        i++;
    }
    // terminate the matrix rows
    a[i] = NULL;
    return (a);
}
