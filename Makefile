# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 17:48:38 by bakgun            #+#    #+#              #
#    Updated: 2023/11/10 18:08:27 by bakgun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURCE := *.c

all:
		$(CC) $(SOURCE) -o $(NAME)

clean:
		@rm -f *.o

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re