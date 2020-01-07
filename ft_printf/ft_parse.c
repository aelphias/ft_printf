/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:06:30 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/07 17:03:32 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct_printf(struct s_printf *myprintf, char *s)
{	
	ft_bzero(myprintf, sizeof(struct s_printf));
	myprintf->s = s;
}

void	ft_handle_flags(struct s_printf *myprintf, char *s)
{
	while (*s == ' ' || * s == '+' || *s == '-' || *s == '0' || *s == '#')
	{
		if (*s == ' ')
			myprintf->flag |= SPACE;
		else if (*s == '#')
			myprintf->flag |= HASH;
		else if (*s == '0')
			myprintf->flag |= ZERO;
		else if (*s == '+')
			myprintf->flag |= PLUS;
		else if (*s == '-')
			myprintf->flag |= MINUS;
		s++;
	}
	printf("Flags: ");
	if (myprintf->flag)
	{
		if (myprintf->flag & MINUS)
			printf("-  ");
		if (myprintf->flag & PLUS)
			printf("+  ");
		if (myprintf->flag & HASH)
			printf("#  ");
		if (myprintf->flag & ZERO)
			printf("0  ");
		if (myprintf->flag & SPACE)
			printf("space  ");
		printf("\n");
	}
	else
		printf("	none\n");
}

int		ft_printf(char *s, ...)
{	
	va_list				args;
	struct s_printf		myprintf;
	
    va_start(args, s);
	ft_init_struct_printf(&myprintf, s);
    while (*s != '\0')
    {
		if (*s == '%')
		{
			ft_handle_flags(&myprintf, ++s);
			continue;
		}
		myprintf.all_len++;
		s++;
    }
    va_end(args);
	return (1);
}
