/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:49:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/20 17:47:20 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h> /*variable argument lists*/
# include <stdio.h> /* DEL */

# define MINUS 1
# define PLUS 2
# define ZERO 4
# define HASH 8
# define SPACE 16

# define SIZE_LL 1
# define SIZE_HH 2
# define SIZE_BIG_L 4
# define SIZE_L 8
# define SIZE_H 16

# define CHAR 'c'
# define STRING 's'
# define INTEGER 'd'
# define UNSIGNED 'u'
# define OCTAL 'o'
# define HEX 'x'
# define HEX_UP 'X'
# define FLOAT 'f'
# define PERCENT '%'

typedef	struct	s_printf
{
    char    flag; // in binary
	char	point;
	int		spec;
    int		width;
	int		precision;
	int		size;
	char	*s;
	int		all_len;
	va_list check_length;
	//va_list handle_spec;
}			t_printf;

	int	ft_printf(const char *s, ...);
	//void	ft_parse_flags(t_printf *myprintf, const char *s);
	//void	ft_init_struct_printf(t_printf *myprintf, const char *s, va_list args);
	void	ft_count_str(t_printf *myprintf, va_list args);
	void	ft_count_int(t_printf *myprintf, va_list args);
	void ft_count(t_printf *myprintf, va_list args);
	void ft_count_char(t_printf *myprintf);

#endif
