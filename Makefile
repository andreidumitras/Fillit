# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adumitra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:42:14 by adumitra          #+#    #+#              #
#    Updated: 2017/04/22 12:42:49 by adumitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = functions/cate_piese.c \
	  functions/free_list.c \
	  functions/free_map.c \
	  functions/ft_bzero.c \
	  functions/ft_lstnew.c \
	  functions/ft_lstpush_back.c \
	  functions/ft_memset.c \
	  functions/ft_putendl.c \
	  functions/ft_strnew.c \
	  functions/ft_strsplit.c \
	  functions/new_map.c \
	  functions/print_map.c \
	  functions/put_piece.c \
	  source/main.c \
	  source/ok.c \
	  source/solver.c \

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -I. -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: fclean all
