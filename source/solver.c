/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:56:19 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/22 17:42:09 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verificare(t_etris *p, char **map, int x, int y)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (map[p->piesa[i] - '0' + x][p->piesa[i + 1] - '0' + y] != '.')
			return (0);
		i += 2;
	}
	pune_piesa(p, map, x, y);
	return (1);
}

void	repozitionare(t_etris *piese, char **map, int i, int j)
{
	int		k;

	k = 0;
	while (k < 8)
	{
		map[i + piese->piesa[k] - '0'][j + piese->piesa[k + 1] - '0'] = '.';
		k += 2;
	}
}

int		back_tetris(t_etris *piese, char **map, int size)
{
	int		i;
	int		j;

	if (!piese)
		return (1);
	i = 0;
	while (i <= size - piese->height)
	{
		j = 0;
		while (j <= size - piese->width)
		{
			if (verificare(piese, map, i, j))
			{
				if (!(back_tetris(piese->next, map, size)))
					repozitionare(piese, map, i, j);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		solve(t_etris *piese)
{
	int		size;
	int		cate;
	char	**map;

	cate = cate_piese(piese);
	size = 2;
	while (size * size < cate * 4)
		size++;
	if (!(map = new_map(size)))
		return (0);
	while (back_tetris(piese, map, size) == 0)
	{
		free_map(map, size);
		size++;
		if (!(map = new_map(size)))
			return (0);
	}
	print_map(map, size);
	return (1);
}
