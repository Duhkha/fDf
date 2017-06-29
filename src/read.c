/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 06:45:36 by syoung            #+#    #+#             */
/*   Updated: 2017/06/29 06:45:38 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grid		**ft_read(char *file, int *row_countp, int *col_countp)
{
	t_read	r;
	t_grid	**cell;
	int		i;

	r.row_count = 0;
	r.col_count = 0;
	r.fd = open(file, O_RDONLY);
	while (read(r.fd, r.buff, 1))
		if (r.buff[0] == '\n')
			r.row_count++;
	r.fd = open(file, O_RDONLY);
	cell = (t_grid **)malloc(sizeof(t_grid *) * (r.row_count + 1));
	r.row_count = 0;
	r.col_count = 0;
	while (get_next_line(r.fd, &r.row))
	{
		r.split = ft_strsplit((const char*)r.row, ' ');
		free(r.row);
		r.col_count = 0;
		while (r.split[r.col_count] != NULL)
			r.col_count++;
		cell[r.row_count] = (t_grid *)malloc(sizeof(t_grid) * (r.col_count + 1));
		r.col_count = 0;
		while (r.split[r.col_count] != NULL)
		{
			cell[r.row_count][r.col_count].height = ft_atoi((const char*)r.split[r.col_count]);
			r.col_count++;
		}
		r.row_count++;
	}
	*row_countp = r.row_count;
	*col_countp = r.col_count;
	i = 0;
	while (r.split[i] != NULL)
	{
		free(r.split[i]);
		i++;
	}
	free(r.split);
	return (cell);
}
