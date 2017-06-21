/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:24:18 by syoung            #+#    #+#             */
/*   Updated: 2017/06/06 07:25:30 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*loc;
	int		len;

	len = ft_strlen(s);
	i = 0;
	len++;
	while (len--)
	{
		if (s[i] == c)
		{
			loc = (char *)&s[i];
			return (loc);
		}
		i++;
	}
	return (NULL);
}
