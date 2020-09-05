/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cate_piese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:16:19 by adumitra          #+#    #+#             */
/*   Updated: 2018/12/07 08:38:31 by Andrei Dumitras  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cate_piese(t_etris *lista)
{
	int		cate;
	char	litera;

	cate = 0;
	litera = 'A';
	while (lista)
	{
		cate++;
		lista->litera = litera;
		lista = lista->next;
		litera++;
	}
	return (cate);
}
