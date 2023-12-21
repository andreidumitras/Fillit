/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:48:40 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 18:00:34 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
 > The "ft_lstnew" function is a function from Libft.
 > It creates a new element of type "t_etris" and fills its fields with the given values.

Parameters:
 - *content: the string of coordinates for the piece
 - width: the width of the piece
 - height: the height of the piece

Return value:
 - a pointer to the newly allocated node.
 - NULL if the process fails.
*/
t_etris *ft_lstnew(char *content, int width, int height)
{
    t_etris *new_list;          // the new element of the list that will be allocated

    // verify the pointers
    if (!(new_list = (t_etris *)malloc(sizeof(t_etris))))
        return (NULL);
    if (!content)
        new_list->piesa = NULL;
    else
    {
        // allocate space for the string of coordinates
        new_list->piesa = (char *)malloc(sizeof(char) * 8);
        new_list->piesa = content;
    }
    // place width
    new_list->width = width;
    // place height
    new_list->height = height;
    // place next
    new_list->next = NULL;
    return (new_list);
}
