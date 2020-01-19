/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:40:55 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/19 21:32:20 by aelphias         ###   ########.fr       */
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
}

void ft_count_str(t_printf *myprintf, va_list args)
{
    int len;
    int precision;
    int width;

    len = (int)ft_strlen(va_arg(args, char*));
    precision = myprintf->precision;    
    width = myprintf->width;    
    if (precision == 0)
        myprintf->precision += len;
    if (width >= len)
        myprintf->all_len += width;
    else if (width > precision)
        myprintf->all_len += precision;
        else
            myprintf->all_len += width;
    
        
        
        
        
    
        /* myprintf->all_len += (width > precision ?
                precision : width);
         */
}

void ft_count_char(t_printf *myprintf)
{	 
    myprintf->all_len += (myprintf->width ? myprintf->width : 1);
}
