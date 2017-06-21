/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:38:48 by syoung            #+#    #+#             */
/*   Updated: 2017/06/06 07:27:26 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cs;
	size_t	i;
	void	*loc;

	i = 0;
	cs = (char *)s;
	while (i < n)
	{
		if (cs[i] == c)
		{
			loc = &cs[i];
			return (loc);
		}
		i++;
	}
	return (NULL);
}
