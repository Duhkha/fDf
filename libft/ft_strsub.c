/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 07:39:01 by syoung            #+#    #+#             */
/*   Updated: 2017/06/07 07:40:57 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s != NULL && &s[start] != NULL)
	{
		sub = ft_memalloc(len + 1);
		if (sub == NULL)
			return (NULL);
		while (i < len)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		sub[i] = '\0';
		return (&sub[0]);
	}
	else
		return (NULL);
}
