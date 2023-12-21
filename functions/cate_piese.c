/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cate_piese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:16:19 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 17:27:31 by Andrei Dumitras  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "cate_piese" function receives the list of pieces and returns the number of elements.
 > It also computes the char symbol that each piece will be characterised.
 
Parameters:
 - *piese: the list of pieces

Return value:
 - the amount of pieces inside the list.
*/
int		cate_piese(t_etris *lista)
{
    int     cate;           // the amount of pieces
    char    litera;         // the character symbol

    // initialize the working variables
    cate = 0;
    litera = 'A';
    // traversing the list
    while (lista)
    {
        // increment the amount for each element
        cate++;
        // place the char symbol
        lista->litera = litera;
        // go to the next element
        lista = lista->next;
        // increment the char symbol
        litera++;
    }
    // return the computed amount of pieces.
    return (cate);
}
