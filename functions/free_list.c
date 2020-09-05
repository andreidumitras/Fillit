/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:54:38 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/18 17:16:00 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(t_etris **lista)
{
	t_etris		*p;

	while (*lista)
	{
		p = *lista;
		*lista = (*lista)->next;
		free(p->piesa);
		free(p);
	}
}
