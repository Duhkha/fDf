/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 06:45:12 by syoung            #+#    #+#             */
/*   Updated: 2017/02/22 07:26:04 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cnt_parts(const char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		ft_wlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

int			ft_strsplit_2(char **t, char const *s, char c)
{
	int		nb_word;
	int		index;

	if (s == NULL)
		return (0);
	index = 0;
	nb_word = ft_cnt_parts((char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_cnt_parts((char *)s, c) + 1));
	if (t == NULL)
		return (0);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_strsub((char *)s, 0, ft_wlen((char *)s, c));
		if (t[index] == NULL)
			return (0);
		s = s + ft_wlen(s, c);
		index++;
	}
	t[index] = NULL;
	return (nb_word);
}