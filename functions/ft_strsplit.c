/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:37:11 by adumitra          #+#    #+#             */
/*   Updated: 2017/03/04 11:59:03 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cate(const char *s, char c)
{
	int		cat;

	cat = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			cat++;
		s++;
	}
	return (cat);
}

static	int	cuvant(const char *s, char c)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		k++;
		i++;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(a = (char **)malloc(sizeof(char *) * cate(s, c) + 1)))
		return (NULL);
	while (i < cate(s, c) && s[j])
	{
		k = 0;
		if (!(a[i] = ft_strnew(cuvant(s + j, c) + 1)))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			a[i][k++] = s[j++];
		a[i][k] = '\0';
		i++;
	}
	a[i] = NULL;
	return (a);
}
