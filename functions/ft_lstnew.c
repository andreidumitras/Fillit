/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:48:40 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/18 19:31:34 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_etris	*ft_lstnew(char *content, int width, int height)
{
	t_etris	*new_list;

	if (!(new_list = (t_etris *)malloc(sizeof(t_etris))))
		return (NULL);
	if (!content)
		new_list->piesa = NULL;
	else
	{
		new_list->piesa = (char *)malloc(sizeof(char) * 8);
		new_list->piesa = content;
	}
	new_list->width = width;
	new_list->height = height;
	new_list->next = NULL;
	return (new_list);
}
