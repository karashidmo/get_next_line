# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krashid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 21:13:21 by krashid-          #+#    #+#              #
#    Updated: 2017/10/02 15:02:26 by krashid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = get_next_line

FLAGS = -g -Werror -Wall -Wextra

SRC = get_next_line.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
