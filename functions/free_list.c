/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:54:38 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:27:00 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "free_list" function receives the list of pieces and frees all the allocated space.
 
Parameters:
 - *lista: the list of pieces

Return value:
 - void
*/
void free_list(t_etris **lista)
{
    t_etris *p;         // auxiliary pointer

    // for each element of the list:
    while (*lista)
    {
        // place the pointer p to the current element
        p = *lista;
        // move the head to the following element of the list
        *lista = (*lista)->next;
        // free the allocated space for the string of coordinates
        free(p->piesa);
        // free the allocated memory for the node of the list.
        free(p);
    }
}
