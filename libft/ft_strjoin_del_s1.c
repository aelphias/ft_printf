/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del_s1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:19:19 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/07 23:22:15 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del_s1(char *s1, char const *s2)
{
	char	*rslt;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(rslt = (char *)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	ft_strcpy(rslt, s1);
	ft_strcat(rslt, s2);
	ft_strdel(&s1);
	return (rslt);
}
