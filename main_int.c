/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:40:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/29 17:49:21 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int digit = -234;
    //char *format = "%.16d";
    char *format = "%+d";
    printf("\noriginal:%d\n", printf(format, digit));
    printf("mine:%d\n", ft_printf(format, digit));
    return(0);
} 