# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 17:48:38 by bakgun            #+#    #+#              #
#    Updated: 2023/11/29 15:31:30 by bakgun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_B := checker

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURCE := push_swap.c quicksort.c utils.c lets_sort.c ft_split.c movements_a_b.c movements_a.c movements_b.c\

SOURCE_B := checker_bonus.c ft_split_bonus.c movements_a_b_bonus.c movements_a_bonus.c movements_b_bonus.c utils_bonus.c\

GNL := get_next_line/

OBJECTS := $(SOURCE:.c=.o)

OBJECTS_B := $(SOURCE_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)
	
$(NAME_B): $(OBJECTS_B) | gnl
	$(CC) $(OBJECTS_B) -o $(NAME_B) $(GNL)/*a $(CFLAGS)
	
gnl:
	make all -C $(GNL)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_B)

fclean: clean
	make fclean -C $(GNL)
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all clean fclean re