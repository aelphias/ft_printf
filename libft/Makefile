# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 15:28:53 by aelphias          #+#    #+#              #
#    Updated: 2019/10/21 16:12:05 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror

SRC = ft_isdigit.c ft_isprint.c ft_isascii.c \
      ft_isalnum.c ft_isalpha.c ft_putchar.c \
 	  ft_strlen.c  ft_strdup.c   \
 	  ft_tolower.c ft_toupper.c  \
 	  ft_bzero.c ft_putchar_fd.c ft_memset.c \
 	  ft_memcpy.c ft_memccpy.c \
 	  ft_putstr.c ft_putstr_fd.c ft_putendl.c\
 	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
 	  ft_memmove.c ft_memchr.c ft_memcmp.c \
 	  ft_strcpy.c ft_strncpy.c ft_strcat.c \
 	  ft_strncat.c ft_strlcat.c ft_strchr.c \
 	  ft_strrchr.c ft_strstr.c ft_strcmp.c  \
 	  ft_strncmp.c ft_memalloc.c ft_memdel.c\
 	  ft_strnew.c ft_strdel.c ft_strclr.c \
 	  ft_striter.c ft_striteri.c ft_strmap.c \
 	  ft_strmapi.c ft_strequ.c ft_strnequ.c  \
 	  ft_strsub.c ft_strjoin.c ft_strtrim.c\
 	  ft_strsplit.c ft_itoa.c ft_atoi.c \
 	  ft_strnstr.c ft_strjoin_del_s1.c

HED = libft.h

OBJ = $(SRC:.c=.o)

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(SRC) -I libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c $(HED)
	$(CC) -o $@ -c $<


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
