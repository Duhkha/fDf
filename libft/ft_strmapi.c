/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:43:07 by syoung            #+#    #+#             */
/*   Updated: 2017/06/06 12:44:00 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	char			*s2;
	unsigned int	i;

	if (s != NULL)
	{
		i = 0;
		size = ft_strlen(s);
		s2 = ft_strnew(size);
		if (s2 == NULL)
			return (NULL);
		while (s[i])
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		return (s2);
	}
	else
		return (NULL);
}
