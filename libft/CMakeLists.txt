cmake_minimum_required(VERSION 3.14)
project(libft)
set(CMAKE_C_STANDARD 99)
add_library(libft STATIC libft.h ft_isalnum.c ft_isprint.c  ft_memcmp.c
		ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strclr.c ft_strdup.c
		ft_strjoin.c ft_strmapi.c ft_strnequ.c ft_strsplit.c ft_tolower.c
		ft_isalpha.c ft_memalloc.c ft_memcpy.c ft_putchar.c ft_putnbr.c
		ft_strcmp.c ft_strequ.c ft_strlcat.c ft_strncat.c ft_strnew.c
		ft_strstr.c ft_toupper.c ft_atoi.c ft_isascii.c ft_itoa.c
		ft_memccpy.c ft_memdel.c ft_putchar_fd.c ft_putnbr_fd.c
		ft_strcat.c ft_strcpy.c ft_striter.c ft_strlen.c ft_strncmp.c
		ft_strnstr.c ft_strsub.c libft.h ft_bzero.c ft_isdigit.c ft_memchr.c
		ft_memmove.c ft_putendl.c ft_putstr.c ft_strchr.c ft_strdel.c
		ft_striteri.c ft_strmap.c ft_strncpy.c ft_strrchr.c ft_strtrim.c ft_strjoin_del_s1.c)