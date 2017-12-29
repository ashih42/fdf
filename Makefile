# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashih <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 15:14:36 by ashih             #+#    #+#              #
#    Updated: 2017/12/29 12:46:55 by ashih            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft
MINILIBX = minilibx

CFILES = $(wildcard src/*.c)

OFILES = $(notdir $(CFILES:.c=.o))

all: $(NAME)

$(NAME):
	make -C $(MINILIBX)
	make -C $(LIBFT)
	$(CC) $(FLAGS) -c $(CFILES)
	$(CC) -o $(NAME) $(OFILES) -L$(LIBFT) -lft -L$(MINILIBX) -lmlx\
		-framework OpenGL -framework AppKit

clean:
	make -C $(MINILIBX) clean
	make -C $(LIBFT) clean
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(LIBFT)/libft.a
	/bin/rm -f $(MINILIBX)/libmlx.a
	/bin/rm -f $(NAME)

re: fclean all
