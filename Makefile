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
SRC = ./fillit/main.c ./fillit/get_next_line.c ./fillit/input.c ./fillit/output.c ./fillit/checker.c ./fillit/solver.c
OBJ = ./fillit/main.o ./fillit/get_next_line.o ./fillit/output.o ./fillit/checker.o ./fillit/solver.o

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
