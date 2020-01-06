/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:06:30 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/06 22:18:42 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct_printf(struct s_printf *printf, char *s)
{	
	ft_bzero(&printf, sizeof(struct s_printf));
	printf->s = s;
	printf->flag = 0;
	printf->width = 0;
	printf->precision = 0;
}

void	ft_handle_flags(struct s_printf printf, char *s)
{
	if (*s == '%')
		printf.flag |= PERCENT;
	if (*s == ' ')
		printf.flag |= SPACE;
	if (*s == '#')
		printf.flag |= HASH;
	if (*s == '0')
		printf.flag |= ZERO;
	if (*s == '+')
		printf.flag |= PLUS;
	if (*s == '-')
		printf.flag |= MINUS;
}

void ft_printf(char *s, ...)
{	
	va_list args;
    va_start(args, s);
	struct s_printf	printf;
	ft_init_struct_printf(&printf, s);
    while (*s != '\0')
    {
		if (*s == '%')
		{
			ft_handle_flags(printf, s);
			continue;
		}
		else
		{
			printf.all_len++;
		}
        	s++;
    }
    va_end(args);
}

int main(void)
{
    int a;
    
    a = 123456;
    ft_printf("a=%d", a);
    return (0);
}