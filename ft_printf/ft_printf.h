/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:49:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/12 20:17:47 by aelphias         ###   ########.fr       */
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

# define SIZE_LL 100
# define SIZE_HH 101
# define SIZE_BIG_L 102
# define SIZE_L 103
# define SIZE_H 104

# define STRING 201
# define INTEGER 202
# define UNSIGNED 203
# define OCTAL 204
# define HEX 205
# define HEX_UP 206
# define FLOAT 207

typedef	struct	s_printf
{
    char    flag; // in binary
	char	point;
	char	spec;
    int		width;
	int		precision;
	int		size;
	char	*s;
	int		all_len;
	va_list check_length;
	//va_list handle_spec;
}			t_printf;

	void	ft_parse_flags(t_printf *myprintf, const char *s);
	void	ft_init_struct_printf(t_printf *myprintf, const char *s, va_list args);
	int	ft_printf(const char *s, ...);
	int ft_count_str(t_printf *myprintf, va_list args, int prcnt);
#endif
