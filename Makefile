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
HEADER = ./fillit/fillit.h
FLAG = -Wall -Wextra -Werror
SRC = ./fillit/main.c ./fillit/input_output.c ./fillit/checker.c ./fillit/solver.c ./fillit/getters.c ./fillit/place_empty.c
OBJ = ./fillit/main.o ./fillit/input_output.c ./fillit/checker.o ./fillit/solver.o ./fillit/getters.o ./fillit/place_empty.o

OPTION = -c -I $(HEADER)

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
