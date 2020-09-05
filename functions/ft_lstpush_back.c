/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:18:18 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/20 15:47:00 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_etris **begin, char *piece, int w, int h)
{
	t_etris	*new;

	new = (NULL);
	if (!(*begin))
		*begin = ft_lstnew(piece, w, h);
	else
	{
		new = *begin;
		while (new->next)
			new = new->next;
		new->next = ft_lstnew(piece, w, h);
	}
}
