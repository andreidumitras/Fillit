/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:41:53 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 20:41:26 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./../source/fillit.h"

// creates a new matrix of words from the string "s" trimmed by the delimiter "c".
char    **ft_strsplit(char const *s, char c);

// fills with 0s the amount of "n" bytes at the address pointed by "s".
void    ft_bzero(void *s, size_t n);

// creates a new string, filled by 0s
char    *ft_strnew(size_t size);

// fills with the value "c", the specified amount of bytes "n", at the address pointed by "s"
void    *ft_memset(void *s, int c, size_t n);

// printd the string "s" at stdout.
void    ft_putendl(char const *s);

#endif
