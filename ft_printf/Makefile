# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 16:33:33 by aelphias          #+#    #+#              #
#    Updated: 2020/01/13 14:38:47 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=		ft_printf.c ft_count.c

OBJ =		$(SRC:.c=.o)

HEAD =		ft_printf.h

NAME =		libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar -rcs $(NAME) $(OBJ)

%.o:		%.c $(HEAD)
			gcc -I ./ -Wall -Wextra -Werror -g -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
