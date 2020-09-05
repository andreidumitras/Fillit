/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:52:17 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/20 14:31:09 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**new_map(int size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * size);
		ft_memset(map[i], '.', size);
		map[i][size] = '\0';
		i++;
	}
	return (map);
}
