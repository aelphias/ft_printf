/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:40:55 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/12 19:47:53 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_count_str(t_printf *myprintf, va_list args, int prcnt)
{
	int counter;
	int i;

	i = 0;
	counter = 0;
	if (myprintf->spec & STRING)
    {
	  while (i < prcnt)
	  {
	  	counter = ft_strlen(va_arg(args, char*));
        i++;
	  }
    }
	printf("%s", va_arg(args, char*));
    return (counter);
}
