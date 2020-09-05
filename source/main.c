/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:08:14 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/22 18:01:10 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_inim	minim(char *a)
{
	t_inim	m;
	int		i;

	i = 2;
	m.h = a[0] - '0';
	m.w = a[1] - '0';
	while (i < 8)
	{
		if (a[i] - '0' < m.h)
			m.h = a[i] - '0';
		if (a[i + 1] - '0' < m.w)
			m.w = a[i + 1] - '0';
		i += 2;
	}
	return (m);
}

char	*coordonate_simple(char **piesa)
{
	char	*a;
	int		i;
	int		j;
	int		k;

	a = (char *)malloc(sizeof(char) * 8);
	i = 0;
	k = 0;
	while (piesa[i++])
	{
		j = 0;
		while (piesa[i - 1][j++])
		{
			if (piesa[i - 1][j - 1] == '#')
			{
				a[k++] = i - 1 + '0';
				a[k++] = j - 1 + '0';
			}
		}
	}
	a[k] = '\0';
	return (a);
}

char	*coordonate(char **piesa, int *h, int *w)
{
	char	*a;
	t_inim	m;
	int		i;

	i = 0;
	a = coordonate_simple(piesa);
	m = minim(a);
	*w = 0;
	*h = 0;
	while (i < 8)
	{
		a[i] -= m.h;
		if (a[i] - '0' > *h)
			*h = a[i] - '0';
		a[i + 1] -= m.w;
		if (a[i + 1] - '0' > *w)
			*w = a[i + 1] - '0';
		i += 2;
	}
	*h = *h + 1;
	*w = *w + 1;
	return (a);
}

t_etris	*read_pieces(int fd, t_etris **lst)
{
	char		line[21];
	char		**piesa;
	int			cat;
	t_inim		size;
	char		*c;

	while ((cat = read(fd, line, 21)) == 21)
	{
		if (ok(line, cat) == 0)
			return (NULL);
		if (!(piesa = ft_strsplit(line, '\n')))
			return (NULL);
		c = coordonate(piesa, &size.h, &size.w);
		ft_lstpush_back(lst, c, size.w, size.h);
	}
	if (cat != 20)
		return (NULL);
	if (ok(line, cat) && (piesa = ft_strsplit(line, '\n')))
	{
		c = coordonate(piesa, &size.h, &size.w);
		ft_lstpush_back(lst, c, size.w, size.h);
	}
	else
		return (NULL);
	return (*lst);
}

int		main(int ac, char **av)
{
	t_etris	*piese;
	int		fd;

	if (ac != 2)
	{
		write(1, "usage: ./fillit [filename]\n", 27);
		return (0);
	}
	piese = NULL;
	fd = open(av[1], O_RDONLY);
	if (!(piese = read_pieces(fd, &piese)))
		write(1, "error\n", 6);
	else if (!(solve(piese)))
		write(1, "error\n", 6);
	free_list(&piese);
	close(fd);
	return (0);
}
