/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:36:15 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/07 16:16:49 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{	
	char *s0 = "Roses are read,";
	char *s1 = "Sky is blue,";
	char *s2 = "Honey is sweet,";
	char *s3 = "So are you.";
	char *s4 = "love";
	int sym;
	char ch;
	char ch1;

	sym = 0;
	ch = 'A';
	ch1 = 'B';
	// ft_printf("   gndjghisd %10.13llf   %44.789u ");    
	//ft_printf("---+++ %  ---30.13f");    
	// ft_printf(" % 2.10ill ");    
	//ft_printf("%6.*d\n", 18, 98, 432);
	//printf("%+d\n", -18);
	//printf(" %30.13f", 34.41);    
	// ft_printf("%s\n %s\n" "%s\n", "Can you see me?", "Yes, I can!", "And me also?");
	// ft_printf("   gndjghisd %  + #   10.13llf   %00.666u ");    
	// ft_printf(" % 2.10ill ");    
	//ft_printf("%6.*d\n", 18, 98, 432);
	//ft_printf("\n%s\n%s\n%s\n%s\n\n", s0, s1, s2 ,s3);
	//ft_printf("00000%s", s4);
	// printf("ft:\n");	
	// ft_printf("%0000007.5s", s4);
	// printf("orig:\n");
	// sym = printf("%2.1s", s4);
	// printf(" orig printed:%d", sym);
	//ft_printf(" fsdfsd %d dgdfhgtt  + %0.d", );
	ft_printf("%s  %s", s4,s4);
	printf("original:\n");
	//sym = printf("%c %c\n", ch, ch);
	sym = printf("%s  %s", s4,s4);
	printf("\n%d\n", sym);
	  return (0);
} 
