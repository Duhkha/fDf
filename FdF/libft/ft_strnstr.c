/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:18:56 by syoung            #+#    #+#             */
/*   Updated: 2017/06/06 07:23:52 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;
	char	*start;

	j = 0;
	i = 0;
	if (little[0] == '\0')
	{
		start = &big[i];
		return (start);
	}
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && j < len)
			j++;
		if (little[j] == '\0')
		{
			start = &big[i];
			return (start);
		}
		i++;
	}
	return (NULL);
}
