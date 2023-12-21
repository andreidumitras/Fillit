/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:18:25 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:35:03 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Description:
 > The "ft_bzero" function is a function implemented in Libft
 > It reproduces the behaviour of "bzero" function from libc.
 > It receives a pointer and an amount of bytes, and it fills that amount of bytes from that address with 0s

Parameters:
 - *s: the given memory address
 - n: the amount of bytes to be filled with 0s

Return value:
 - void
*/
void ft_bzero(void *s, size_t n)
{
    char *a;            // a pointer used for cast operations

    // cast the given pointer to char and work with the local pointer a
    a = (char *)s;
    // fill with 0 each byte pointed by a, until the amount of bytes is 0.
    while (n--)
        *a++ = '\0';
}
