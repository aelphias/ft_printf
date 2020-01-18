/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:40:55 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/18 20:04:52 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_count(t_printf *myprintf, va_list args)
{	
    args+=0;
    if (myprintf->spec == CHAR)
        ft_count_char(myprintf);
    else if (myprintf->spec == STRING)
        ft_count_str(myprintf, args);
}

void ft_count_str(t_printf *myprintf, va_list args)
{	
    myprintf->all_len += ft_strlen(va_arg(args, char*));
    //printf("%d", myprintf->all_len);    
}

void ft_count_char(t_printf *myprintf)
{	 
    myprintf->all_len += (myprintf->width ? myprintf->width : 1);
}