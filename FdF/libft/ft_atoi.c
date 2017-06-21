/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:36:00 by syoung            #+#    #+#             */
/*   Updated: 2017/06/06 07:13:41 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int ret;
	int i;
	int sign;

	ret = 0;
	i = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\v')
			|| (str[i] == '\f' || str[i] == '\r')
			|| (str[i] == '\n' || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - '0') % 10;
		i++;
	}
	ret = ret * sign;
	return (ret);
}
