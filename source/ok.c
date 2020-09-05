/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:13:09 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/22 17:58:46 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		conex(char *s)
{
	int		i;
	int		diez;

	i = 0;
	diez = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i > 0 && s[i - 1] == '#')
				diez++;
			if (i > 4 && s[i - 5] == '#')
				diez++;
			if (i < 19 && s[i + 1] == '#')
				diez++;
			if (i < 15 && s[i + 5] == '#')
				diez++;
		}
		i++;
	}
	return (diez);
}

int		ok(char *s, int cat)
{
	int		i;
	int		diez;

	i = 0;
	diez = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (0);
			if (s[i] == '#')
				diez++;
		}
		else if (s[i] != '\n')
			return (0);
		i++;
	}
	if (diez != 4 || (cat == 21 && s[20] != '\n'))
		return (0);
	if (conex(s) != 6 && conex(s) != 8)
		return (0);
	return (1);
}
