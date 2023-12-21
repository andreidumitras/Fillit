/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:18:18 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:45:03 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "ft_lstpuch_back" function is a function from Libft.
 > It travels to the end of a list and inserts a new element with ft_lstnew() function.

Parameters:
 - **begin: the pointer to the head of the list. It is a double pointer because it can be modified in the function.
 - *piece: the string of coordinates to be added.
 - w: the width of the piece to be added
 - h: the heigth of the piece to be added

Return value:
 - void
*/
void ft_lstpush_back(t_etris **begin, char *piece, int w, int h)
{
    t_etris	*new;       // the new element to be added

    // initialize the new element
    new = (NULL);
    // verify if the head is NULL.
    // if is NULL, point it to the newly created element.
    // if not, the new element will be added at the end of the list.
    if (!(*begin))
        *begin = ft_lstnew(piece, w, h);
    else
    {
        // start traveling to the end of the list.
        new = *begin;
        // travel until the last element.
        while (new->next)
            new = new->next;
        // to the last element, attach the newly created element.
        new->next = ft_lstnew(piece, w, h);
    }
}
