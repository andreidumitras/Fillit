/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:34:07 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 18:04:19 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "ft_strnew" function is a function implemented in Libft
 > It allocates a new string of characters, together with '\0' and filled with 0s.

Parameters:
 - size: the length of the newly allocated string.

Return value:
 - the newly allocated string
 - NULL in case of errors.
*/
char *ft_strnew(size_t size)
{
    char *a;        // the pointer that will hold the string

    a = NULL;
    // allocate memory for the new string and '\0'.
    a = (char *)malloc(size + 1);
    // check for allocation fail.
    if (a == NULL)
        return (NULL);
    // fill the memory allocated with 0s.
    ft_bzero(a, size + 1);
    return (a);
}
