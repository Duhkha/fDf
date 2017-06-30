/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 06:45:36 by syoung            #+#    #+#             */
/*   Updated: 2017/06/30 07:29:13 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_read	ft_read_count(char *file, t_read r)
{
	r.i = 0;
	r.j = 0;
	r.row_count = 0;
	r.col_count = 0;
	r.fd = open(file, O_RDONLY);
	while (read(r.fd, r.buff, 1))
		if (r.buff[0] == '\n')
			r.row_count++;
	close(r.fd);
	return (r);
}

void			ft_read_helper(t_read r, int *row_countp, int *col_countp)
{
	*row_countp = r.row_count;
	*col_countp = r.col_count;
	free(r.split);
	close(r.fd);
}

t_grid			**ft_read(char *file, int *row_countp, int *col_countp)
{
	t_read	r;
	t_grid	**cell;

	r = ft_read_count(file, r);
	r.fd = open(file, O_RDONLY);
	cell = (t_grid **)malloc(sizeof(t_grid *) * (r.row_count + 1));
	while (get_next_line(r.fd, &r.row))
	{
		r.split = ft_strsplit((const char*)r.row, ' ');
		free(r.row);
		while (r.split[r.col_count] != NULL)
			r.col_count++;
		r.j = 0;
		cell[r.i] = (t_grid *)malloc(sizeof(t_grid) * (r.col_count + 1));
		while (r.split[r.j] != NULL)
		{
			cell[r.i][r.j].height = ft_atoi((const char*)r.split[r.j]);
			free(r.split[r.j]);
			r.j++;
		}
		r.i++;
	}
	ft_read_helper(r, row_countp, col_countp);
	return (cell);
}
