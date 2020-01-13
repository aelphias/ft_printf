/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:40:55 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/13 19:38:29 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_count_str(t_printf *myprintf, va_list args)
{	
    //int counter;
    /* 
    //counter = printf("%s",va_arg(args, char*));
    counter = ft_strlen(va_arg(args, char*));
    printf("%d\n", counter);
	//ft_putstr(va_arg(args, char*));
       // write(1, &counter, 1); */
    myprintf->all_len += ft_strlen(va_arg(args, char*));
//    printf("%d", myprintf->all_len);    
}
