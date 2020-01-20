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

#define START "\n\n\n####################  MY FT_PRINTF  ##########################\n"

#define SIZE_FORMATS 8
#define SIZE_STRINGS 6

char formats[SIZE_FORMATS][50] =  { "%s", "%10.0s", "%1.2s", "%2.1s", "%02.3s",
 "%0s", "% 18.43s", "%43.18s" };

char strings[SIZE_STRINGS][50] = {	"12345678901", "1234567890123456", "", "1", "So are you",
 "                             " };


int main(void)
{	
	printf(START);

	int orig;
	int our;
	int size_formats;
	int size_strings = SIZE_STRINGS;
	while (size_strings--)
	{
		size_formats = SIZE_FORMATS;
		while (size_formats--)
		{
			if ((orig = printf(formats[size_formats], strings[size_strings])) ==
					(our = ft_printf(formats[size_formats], strings[size_strings])))
				printf("\nOK\n");
			else
			{
				printf("\nFAIL | orig %d | our %d | %s | %s\n\n",
						orig, our, formats[size_formats], strings[size_strings]);
			}
		}
	}
	return (0);
}
