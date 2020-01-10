/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:06:30 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/10 17:24:26 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_specification(struct s_printf *myprintf, char *s)
{
	if (*s == 'd' || *s == 'i')
		myprintf->spec = *s;
	else if (*s == 'o')
		myprintf->spec = *s;
	else if (*s == 'u')
		myprintf->spec = *s;
	else if (*s == 'X' || *s == 'x')
		myprintf->spec = *s;
	else if (*s == 'f')
		myprintf->spec = *s;
	if (myprintf->spec)
		s++;
 	if (!myprintf->spec)    // DEL
		printf("Specification: none\n");// DEL
	else// DEL
		printf("Specification = %c\n", myprintf->spec);// DEL
}

void	ft_parse_size(struct s_printf *myprintf, char *s)
{
	int		*size;

	size = &myprintf->size;
	if (*s == 'l')
	{
		s++;
		if (*s == 'l')
		{
			*size = SIZE_LL;
			s++;
		}
		else
			*size = SIZE_L;
	}
	else if (*s == 'h')
	{
		s++;
		if (*s == 'h')
		{
			*size = SIZE_HH;
			s++;
		}
		else
			*size = SIZE_H;
	}
	else if (*s == 'l')
	{
		*size = SIZE_L;
		++s;
	}
	
	printf("Additional size = %d\n", *size); // DEL

	ft_parse_specification(myprintf, s);
}

void	ft_parse_astericks(int *astericks, char **s, va_list *check_length)
{
	//s++;
	while (ft_isdigit(**s) || **s == '*')
	{
		*astericks = 0;
		if (**s == '*' && ++(*s))
		{
			*astericks = va_arg(*check_length, int);
			continue;
		}
		while (ft_isdigit(**s))
		{
			*astericks *= 10;
			*astericks += **s - '0';
			(*s)++;
		}
	}
}

void	ft_parse_width_n_precision(struct s_printf *myprintf, char *s)
{
	int		*width;
	int		*precision;

	width = &myprintf->width;
	precision = &myprintf->precision;
	
	//s++;
	printf("          S1 = %s\n", s);
	ft_parse_astericks(width, &s, &myprintf->check_length);
	myprintf->point +=  *s == '.' ? !!++s : 0;
	printf("          S2 = %s\n", s);
	ft_parse_astericks(precision, &s, &myprintf->check_length);

	printf("Width = %d | point = %d | prec = %d\n",
	myprintf->width, myprintf->point, myprintf->precision);
	
	ft_parse_size(myprintf, s);
}

void	ft_init_struct_printf(struct s_printf *myprintf, char *s, va_list args)
{	
	ft_bzero(myprintf, sizeof(struct s_printf));
	va_copy(myprintf->check_length, args);
	myprintf->s = s;
}

void	ft_parse_flags(struct s_printf *myprintf, char *s)
{
	while (*s == ' ' || *s == '+' || *s == '-' || *s == '0' || *s == '#')
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
	// printf("Flags: ");
	// if (myprintf->flag)
	// {
	// 	if (myprintf->flag & MINUS)
	// 		printf("-  ");
	// 	if (myprintf->flag & PLUS)
	// 		printf("+  ");
	// 	if (myprintf->flag & HASH)
	// 		printf("#  ");
	// 	if (myprintf->flag & ZERO)
	// 		printf("0  ");
	// 	if (myprintf->flag & SPACE)
	// 		printf("space  ");
	// 	printf("\n");
	// }
	// else
	// 	printf("	none\n");
	ft_parse_width_n_precision(myprintf, s);
}

int		ft_printf(char *s, ...)
{	
	va_list				args;
	struct s_printf		myprintf;
    va_start(args, s);
	ft_init_struct_printf(&myprintf, s, args);
    while (*s != '\0')
    {
		if (*s == '%')
		{
			ft_parse_flags(&myprintf, ++s);
			ft_memset(&myprintf, 0, 15);
		}
		myprintf.all_len++;
		s++;
    }
    va_end(args);
	return (1);
}
