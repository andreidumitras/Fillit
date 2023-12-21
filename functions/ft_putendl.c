/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:09:17 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:59:18 by Andrei Dumitras  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "ft_putendl" function is a function from Libft
 > It prints a string to the stdout, together with a new line.

Parameters:
 - *s: the char string to be printed.

Return value:
 - void
*/
void ft_putendl(char const *s)
{
    // verify the pointer
    if (s)
    {
        // while the pointed character is not '\0'
        while (*s)
        {
            // write the character pointed by s
            write(1, s, 1);
            // move the pointer to the next character.
            s++;
        }
        // at the end, write a new line.
        write(1, "\n", 1);
    }
}
