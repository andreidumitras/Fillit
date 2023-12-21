# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adumitra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:42:14 by adumitra          #+#    #+#              #
#    Updated: 2023/12/21 22:36:49 by adumitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the name of the executable
NAME = fillit

# the source .c files
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
	  source/solver.c

# the compiler
CC = gcc

# the flags for the compiler
FLAGS = -Wall -Wextra -Werror

# make NAME first
all: $(NAME)
# execute the compiler with the specified flags
$(NAME):
	$(CC) $(FLAGS) -I. -o $(NAME) $(SRC)

# remove executable
clean:
	/bin/rm -f $(NAME)

# remove executable first
fclean: clean

# remove executable and compile it again.
re: fclean all
