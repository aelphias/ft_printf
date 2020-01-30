/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:40:46 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/30 22:50:41 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int digit = 444;
    char *format = "%10d";
    printf("\noriginal:%d\n", printf(format, digit));
    printf("mine:%d\n", ft_printf(format, digit));
    
    return(0);
} 