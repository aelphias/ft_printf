/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:49:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/10 13:42:30 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h> /*variable argument lists*/
# include <stdio.h> /*remove after debug */

# define SPACE 16
# define HASH 8
# define ZERO 4
# define PLUS 2
# define MINUS 1

# define SIZE_LL 100
# define SIZE_HH 101
# define SIZE_BIG_L 102
# define SIZE_L 103
# define SIZE_H 104

struct      s_printf
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

	void	ft_parse_flags(struct s_printf *myprintf, char *s);
	void	ft_init_struct_printf(struct s_printf *myprintf, char *s, va_list args);
	int		ft_printf(char *s, ...);

#endif
