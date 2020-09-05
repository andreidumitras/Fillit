/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:41:53 by adumitra          #+#    #+#             */
/*   Updated: 2017/04/20 15:48:26 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./../source/fillit.h"

char	**ft_strsplit(char const *s, char c);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putendl(char const *s);

#endif
