# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 15:20:19 by bakgun            #+#    #+#              #
#    Updated: 2023/12/15 15:46:29 by bakgun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
FLAG = -Wall -Wextra -Werror
SRC = get_next_line.c\
	get_next_line_utils.c\

all:
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) get_next_line.o get_next_line_utils.o
clean:
	/bin/rm -f  get_next_line.o get_next_line_utils.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re