/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:06:30 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/07 19:08:37 by aelphias         ###   ########.fr       */
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

	if (!myprintf->spec)
		printf("Specification: none\n");
	else
		printf("Specification = %c\n", myprintf->spec);
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

void	ft_parse_width_n_precision(struct s_printf *myprintf, char *s)
{
	int		*width;
	int		*precision;

	width = &myprintf->width;
	precision = &myprintf->precision;
	while (ft_isdigit(*s))
	{
		*width *= 10;
		*width += *s++ - '0';
	}
	myprintf->point +=  *s == '.' ? !!++s : 0;
	while (ft_isdigit(*s))
	{
		*precision *= 10;
		*precision += *s++ - '0';
	}

	printf("Width = %d | point = %d | prec = %d\n",
	myprintf->width, myprintf->point, myprintf->precision);
	
	ft_parse_size(myprintf, s);
}

void	ft_init_struct_printf(struct s_printf *myprintf, char *s)
{	
	ft_bzero(myprintf, sizeof(struct s_printf));
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
	ft_init_struct_printf(&myprintf, s);
    while (*s != '\0')
    {
		if (*s == '%')
		{
			ft_memset(&myprintf, '\0', sizeof(char) * 16);
			ft_parse_flags(&myprintf, ++s);
			ft_memset(&myprintf, '\0', sizeof(char) * 16);
			// ft_zero_params;
			continue;
		}
		myprintf.all_len++;
		s++;
    }
    va_end(args);
	return (1);
}
