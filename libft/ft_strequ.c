/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:00:24 by syoung            #+#    #+#             */
/*   Updated: 2017/06/09 13:18:24 by godendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] || s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
