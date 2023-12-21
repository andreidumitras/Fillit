/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:59:58 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:57:28 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "ft_memset" function is a function implemented in Libft
 > It reproduces the behaviour of "memset" function from libc.
 > It receives a pointer, a value to fill the address and the amount of bytes to be set.
 > It fills the given amount of bytes with the given value.

Parameters:
 - *s: the given memory address
 - c: the value to fill the memory address
 - n: the amount of bytes to be filled

Return value:
 - void
*/
void *ft_memset(void *s, int c, size_t n)
{
    char *a;            // a temporary pointer to work with.

    // cast the given address to char
    a = (char *)s;
    // fill the amount of bytes pointed by a, with the value c
    while (n--)
        *a++ = c;
    // returns the filled memory address.
    return (s);
}
