# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 13:58:56 by aelphias          #+#    #+#              #
#    Updated: 2019/12/13 12:57:56 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re lib

NAME	= ft_printf_test_out
#NAME	= libftprintf.a

SRC_DIR = ./src

FILES	=	main.c	
	
SRC		= $(addprefix $(SRC_DIR)/,$(FILES))

INC		= ft_printf.h

OBJ		= $(SRC:.c=.o)

FT_LIB = libft/libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 

all:  $(NAME)

$(NAME): $(OBJ) $(FT_LIB) ./libft/libft.a
	$(CC) $(CFLAGS) -L ./libft -lft -I . -I ./libft $(OBJ) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

FORCE:		;

$(FT_LIB):	FORCE
			make -C ./libft

clean:		
	/bin/rm -f $(OBJ)
	make clean -C ./libft

fclean: 	clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)

re: fclean all
