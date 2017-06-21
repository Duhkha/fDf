/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:24:18 by syoung            #+#    #+#             */
/*   Updated: 2017/06/09 13:28:58 by godendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*loc;
	int		len;

	len = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (NULL);
	while (len)
	{
		if (s[len] == c)
		{
			loc = (char *)&s[len];
			return (loc);
		}
		len--;
	}
	return (NULL);
}
