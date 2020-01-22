/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:40:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/22 18:01:08 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int digit = 1234;
    char *format = "%hd";
    printf("\noriginal:%d\n", printf(format, digit));
    printf("mine:%d\n", ft_printf(format, digit));    
    printf("\nint:%lu\n", sizeof(int));
    printf("\nlong int:%lu\n", sizeof(long int));
    return(0);
}