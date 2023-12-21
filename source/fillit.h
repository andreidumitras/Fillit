/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:08:47 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 21:08:55 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "./../functions/libft.h"

// linked list queue
// it contains the Tetris piece
typedef struct  s_etris
{
    char    *piesa;             // the string of coordinates for each '#' inside the piece (normalized form)
    int     width;              // width of the piece
    int     height;             // height of the piece
    char    litera;             // character to fill solution
    struct s_etris *next;       // next pointer element
}               t_etris;

// a temporary structure used for storing details in situations where I needed more than 5 variables (rigor imposed by A+)
typedef struct  s_inim
{
    int     h;                  // the height   
    int     w;                  // the width
}               t_inim;

// verifies if the structure of a piece is correct
int     ok(char *s, int cat);

// tries to arrange all the pieces inside the minimum square matrix
int     solve(t_etris *piese);

// frees a linked list
void    free_list(t_etris **lista);

// add at the end of the list a new element
void    ft_lstpush_back(t_etris **begin, char *piece, int w, int h);

// frees a dynamically allocated matrix
void    free_map(char **map, int size);

// creates a new node for a list
t_etris *ft_lstnew(char *content, int width, int height);

// places a tetris piece inside a matrix, at the given coordinates
void    pune_piesa(t_etris *p, char **map, int i, int j);

// returns the length of the linked list
int     cate_piese(t_etris *lista);

// creates a new dynamically allocated square matrix
char    **new_map(int size);

// prints a matrix to stdout.
void    print_map(char **map, int size);

#endif
