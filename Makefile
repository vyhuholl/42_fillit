#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/27 20:35:42 by sghezn            #+#    #+#              #
#    Updated: 2019/04/27 20:35:44 by sghezn           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC = main.c input_output.c checker.c solver.c getters.c place_empty.c test.c
OBJ = main.o input_output.o checker.o solver.o getters.o place_empty.o test.o

all: $(NAME)

$(NAME): lib $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) -L libft -lft

$(OBJ):
	gcc $(FLAG) -c $(SRC) -I fillit.h -I libft/libft.h

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all
