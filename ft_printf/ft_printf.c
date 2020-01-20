/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:06:30 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/20 15:11:54 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_specification(t_printf *myprintf, char **s)
{
	char	*copy;

	copy = (char *)*s;
	if (*copy == 'd' || *copy == 'i')
		myprintf->spec = INTEGER;
	else if (*copy == 's')
		myprintf->spec = STRING;	
	else if (*copy == 'o')
		myprintf->spec = OCTAL;
	else if (*copy == 'u')
		myprintf->spec = UNSIGNED;
	else if (*copy == 'X')
		myprintf->spec = HEX_UP;
	else if (*copy == 'x')
		myprintf->spec = HEX;
	else if (*copy == 'f')
		myprintf->spec = FLOAT;
	else if (*copy == '%')
		myprintf->spec = PERCENT;
	else if (*copy == 'c')
		myprintf->spec = CHAR;
	if (*copy)
		(*s)++;
	/* if (!myprintf->spec)    // DEL   
	//printf("Specification: none\n");// DEL
		else// DEL
	//printf("Specification = %c\n", myprintf->spec);// DEL
	//ft_count_str(myprintf, args);	 */
}
void	ft_parse_size(t_printf *myprintf, char **s)
{
	int		*size;

	size = &myprintf->size;
	if (**s == 'l')
	{
		(*s)++;
		if (**s == 'l')
		{
			*size = SIZE_LL;
			(*s)++;
		}
		else
			*size = SIZE_L;
	}
	else if (**s == 'h')
	{
		(*s)++;
		if (**s == 'h')
		{
			*size = SIZE_HH;
			(*s)++;
		}
		else
			*size = SIZE_H;
	}
	else if (**s == 'l')
	{
		*size = SIZE_L;
		++(*s);
	}
	/* printf("Additional size = %d\n", *size); // DEL */
	ft_parse_specification(myprintf, s);
}

void	ft_parse_round_dot(int *astericks, char **s, va_list *check_length)
{
	while (ft_isdigit(**s) || **s == '*')
	{
		*astericks = 0;
		if (**s == '*' && ++(*s))
		{
			*astericks = va_arg(*check_length, int);
			continue;
		}
		//printf("{ astericks  %d\n}", *astericks);
		while (ft_isdigit(**s))
		{
			*astericks *= 10;
			*astericks += **s - '0';
			(*s)++;
		}
	}
}

void	ft_parse_width_n_precision(t_printf *myprintf, char **s)
{
	int		*width;
	int		*precision;

	width = &myprintf->width;
	precision = &myprintf->precision;
	
	 
	ft_parse_round_dot(width, s, &myprintf->check_length);
	myprintf->point +=  **s == '.' ? !!++(*s) : 0;

	ft_parse_round_dot(precision, s, &myprintf->check_length);

	
	
	ft_parse_size(myprintf, s);
}

void	ft_init_struct_printf(t_printf *myprintf, char *s, va_list args)
{	
	ft_bzero(myprintf, sizeof(t_printf));
	va_copy(myprintf->check_length, args);
	myprintf->s = (char *)s;
}

void	  ft_parse_flags(t_printf *myprintf, char **s)
{
	char *copy;

	(*s)++;
	copy = (char *)*s;
	while (*copy == ' ' || *copy == '+' || *copy == '-' || *copy == '0' || *copy == '#')
	{
		if (*copy == ' ')
			myprintf->flag |= SPACE;
		else if (*copy == '#')
			myprintf->flag |= HASH;
		else if (*copy == '0')
			myprintf->flag |= ZERO;
		else if (*copy == '+')
			myprintf->flag |= PLUS;
		else if (*copy == '-')
			myprintf->flag |= MINUS;
		copy++;
	}

	/* ////////////////////////////////
	printf("Flags: "); //DEL
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
	////////////////////////////// */
	*s += copy - *s;
	ft_parse_width_n_precision(myprintf, s);
}

int		ft_printf(const char *s, ...)
{	
	t_printf	myprintf;
	va_list		args;
	int			i;
	char *s1;

	s1 = (char *)s; 
	i = 0;
    va_start(args, s);
	ft_init_struct_printf(&myprintf, s1, args);
    while (*s1 != '\0')
    {
		if (*s1 == '%')
		{
			ft_parse_flags(&myprintf, &s1);
			ft_count(&myprintf, args);
			ft_memset(&myprintf, 0, 15);
		}
		else
		{
			myprintf.all_len++;
			s1++;
		}
    }   	
    va_end(args);
	return (myprintf.all_len);
}
