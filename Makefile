# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 15:40:00 by tamarant          #+#    #+#              #
#    Updated: 2019/04/29 15:40:00 by tamarant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

SRC =

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
				gcc $(FLAGS) -c $(SRC)
				ar rc $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ)

fclean: clean
				rm -rf $(NAME)

re: fclean all