/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:40:55 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/29 17:48:20 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_count(t_printf *myprintf, va_list args)
{	
	//args+=0;
	if (myprintf->spec == CHAR)
		ft_count_char(myprintf);
	else if (myprintf->spec == STRING)
		ft_count_str(myprintf, args);
	 else if (myprintf->spec == INTEGER)
		ft_count_int(myprintf, args);
}

void ft_count_str(t_printf *myprintf, va_list args)
{
	int len;
	int precision;
	int width;

	len = (int)ft_strlen(va_arg(args, char*));
	precision = myprintf->precision;    
	width = myprintf->width;    
	
	//printf("Width = %d | len = %d \n", width, len);
	if (width >= len)
		myprintf->all_len += width;
	else if (precision < len && myprintf->point)
		// myprintf->all_len += precision;
		myprintf->all_len += (precision > width ? precision : width);
	else 
		myprintf->all_len += len;
}

void ft_count_char(t_printf *myprintf)
{	 
	myprintf->all_len += (myprintf->width ? myprintf->width : 1);
}

void ft_count_int(t_printf *myprintf, va_list args)
{	
	int len;

	len = 0;
	if (myprintf->flag & SIZE_HH)
		len = ft_nbr_len(va_arg(args, int));
	else if (myprintf->flag & SIZE_H)
		len = ft_nbr_len(va_arg(args, int));
	else if (myprintf->flag & SIZE_L)
		len = ft_nbr_len(va_arg(args, long int));
	else if (myprintf->flag & SIZE_LL)
		len = ft_nbr_len(va_arg(args, long long int));
	else if (!(myprintf->flag))
		len = ft_nbr_len(va_arg(args, int));
	if (myprintf->flag & PLUS)
		myprintf->all_len++;
	myprintf->all_len +=len;
}
