/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 06:45:12 by syoung            #+#    #+#             */
/*   Updated: 2017/06/29 06:45:15 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate(t_mlx m, int x, int y, int color)
{
	float x1;
	float y1;

	x1 = (float)x;
	y1 = (float)y;
	x1 = x1 * cos(0.523599) - y1 * sin(0.523599);
	y1 = x1 * sin(0.523599) + y1 * cos(0.523599);
	mlx_pixel_put(m.mlx, m.win, x1, y1, color);
}

void			line(t_mlx m, int x0, int y0, int x1, int y1, int color)
{
	t_line	n;

	n.dx = abs(x1 - x0);
	n.sx = x0 < x1 ? 1 : -1;
	n.dy = abs(y1 - y0);
	n.sy = y0 < y1 ? 1 : -1;
	n.err = (n.dx > n.dy ? n.dx : -n.dy) / 2;
	color = 0x00FFFFFF - (color * 50000);
	while (1)
	{
		if (x0 == x1 && y0 == y1)
			break ;
		n.e2 = n.err;
		if (n.e2 > -n.dx)
		{
			n.err -= n.dy;
			x0 += n.sx;
		}
		if (n.e2 < n.dy)
		{
			n.err += n.dx;
			y0 += n.sy;
		}
		rotate(m, x0, y0, color);
	}
}

static void		ft_cell_draw(t_grid cell, t_hm xyh, t_mlx m)
{
	int multi;

	multi = MULTIPLIER;
	cell.x0 = xyh.x - xyh.xyh0 * multi;
	cell.y0 = xyh.y - xyh.xyh0 * multi;
	cell.x1 = (xyh.x + xyh.gap) - xyh.xyh1 * multi;
	cell.y1 = xyh.y - xyh.xyh1 * multi;
	cell.x2 = xyh.x - xyh.xyh2 * multi;
	cell.y2 = (xyh.y + xyh.gap) - xyh.xyh2 * multi;
	cell.x3 = xyh.x + xyh.gap - xyh.xyh3 * multi;
	cell.y3 = (xyh.y + xyh.gap) - xyh.xyh3 * multi;
	line(m, cell.x0, cell.y0, cell.x1, cell.y1, xyh.xyh0 + xyh.xyh1);
	line(m, cell.x0, cell.y0, cell.x2, cell.y2, xyh.xyh0 + xyh.xyh2);
	line(m, cell.x2, cell.y2, cell.x3, cell.y3, xyh.xyh2 + xyh.xyh3);
	line(m, cell.x1, cell.y1, cell.x3, cell.y3, xyh.xyh1 + xyh.xyh3);
}

void			ft_draw(int col_count, int row_count, t_grid **cell, int gap, t_mlx m)
{
	int			x;
	int			y;
	int			i;
	int			j;
	t_hm		xyh;

	i = 0;
	xyh.y = 50;
	xyh.gap = gap;
	while (i <= row_count)
	{
		xyh.y += gap;
		xyh.x = 400;
		j = 0;
		while (j <= col_count)
		{
			xyh.xyh3 = xyh.xyh2 = xyh.xyh1 = xyh.xyh0 = cell[i][j].height;
			if (cell[i][j + 1].height != 0 && j < col_count)
				xyh.xyh3 = xyh.xyh1 = cell[i][j + 1].height;
			if (i > 0 && cell[i - 1][j].height != 0)
				xyh.xyh1 = xyh.xyh0 = cell[i - 1][j].height;
			if (i < row_count && cell[i + 1][j].height != 0)
				xyh.xyh2 = xyh.xyh3 = cell[i + 1][j].height;
			if (j > 0 && cell[i][j - 1].height != 0)
				xyh.xyh2 = xyh.xyh0 = cell[i][j - 1].height;
			if (j < col_count && i < row_count && cell[i + 1][j + 1].height != 0)
				xyh.xyh3 = cell[i + 1][j + 1].height;
			if (i > 0 && j > 0 && cell[i - 1][j - 1].height != 0)
				xyh.xyh0 = cell[i - 1][j - 1].height;
			if (j < col_count && i > 0 && cell[i - 1][j + 1].height != 0)
				xyh.xyh1 = cell[i - 1][j + 1].height;
			if (i < row_count && j > 0 && cell[i + 1][j - 1].height != 0)
				xyh.xyh2 = cell[i + 1][j - 1].height;
			xyh.x += gap;
			ft_cell_draw(cell[i][j], xyh, m);
			j++;
		}
		i++;
	}
}
