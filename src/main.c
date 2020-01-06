/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:36:15 by aelphias          #+#    #+#             */
/*   Updated: 2020/01/06 19:09:57 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{	
	char *str;
	
	str = "Can you print me?";
	printf("orig %s\n", str);
	ft_printf("ours %s\n", str);
	return (0);
}
