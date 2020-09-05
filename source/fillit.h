/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:08:47 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/22 17:20:55 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "./../functions/libft.h"

typedef	struct	s_etris
{
	char			*piesa;
	int				width;
	int				height;
	char			litera;
	struct s_etris	*next;
}				t_etris;

typedef	struct	s_inim
{
	int				h;
	int				w;
}				t_inim;

int				ok(char *s, int cat);
int				solve(t_etris *piese);
void			free_list(t_etris **lista);
void			ft_lstpush_back(t_etris **begin, char *piece, int w, int h);
void			free_map(char **map, int size);
t_etris			*ft_lstnew(char *content, int width, int height);
void			pune_piesa(t_etris *p, char **map, int i, int j);
int				cate_piese(t_etris *lista);
char			**new_map(int size);
void			print_map(char **map, int size);

#endif
