/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:49:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/07 16:57:31 by aelphias         ###   ########.fr       */
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

struct      s_printf
{
	char	*s;
    char    flag; // in binary
    int		width;
	int		precision;
	int		all_len;
	//va_list check_length;
	//va_list handle_spec;
}			t_printf;

	void	ft_handle_flags(struct s_printf *myprintf, char *s);
	/*void	ft_handle_width(struct s_printf printf, char *s);
	void	ft_handle_precision(struct s_printf printf, char *s);
	void	ft_handle_length(struct s_printf printf, char *s);
	void	ft_handle_specifier(struct s_printf printf, char *s);
	void	ft_init_struct_printf(struct s_printf *printf, char *s);*/
	int		ft_printf(char *s, ...);

#endif
