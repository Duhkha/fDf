/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 06:45:12 by syoung            #+#    #+#             */
/*   Updated: 2017/06/30 07:27:19 by syoung           ###   ########.fr       */
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

void			line(t_mlx m, t_line n, int color)
{
	n.dx = ft_abs(n.x1 - n.x0);
	n.sx = n.x0 < n.x1 ? 1 : -1;
	n.dy = ft_abs(n.y1 - n.y0);
	n.sy = n.y0 < n.y1 ? 1 : -1;
	n.err = (n.dx > n.dy ? n.dx : -n.dy) / 2;
	color = 0x00FFFFFF - (color * 50000);
	while (1)
	{
		if (n.x0 == n.x1 && n.y0 == n.y1)
			break ;
		n.e2 = n.err;
		if (n.e2 > -n.dx)
		{
			n.err -= n.dy;
			n.x0 += n.sx;
		}
		if (n.e2 < n.dy)
		{
			n.err += n.dx;
			n.y0 += n.sy;
		}
		rotate(m, n.x0, n.y0, color);
	}
}

static void		ft_cell_draw(t_grid cell, t_hm xyh, t_mlx m)
{
	int		multi;
	t_line	l[4];

	multi = MULTIPLIER;
	l[0].x0 = xyh.x - xyh.xyh0 * multi;
	l[0].y0 = xyh.y - xyh.xyh0 * multi;
	l[0].x1 = (xyh.x + xyh.gap) - xyh.xyh1 * multi;
	l[0].y1 = xyh.y - xyh.xyh1 * multi;
	l[1].x0 = l[0].x0;
	l[1].y0 = l[0].y0;
	l[1].x1 = xyh.x - xyh.xyh2 * multi;
	l[1].y1 = (xyh.y + xyh.gap) - xyh.xyh2 * multi;
	l[2].x0 = l[1].x1;
	l[2].y0 = l[1].y1;
	l[2].x1 = xyh.x + xyh.gap - xyh.xyh3 * multi;
	l[2].y1 = (xyh.y + xyh.gap) - xyh.xyh3 * multi;
	l[3].x0 = l[0].x1;
	l[3].y0 = l[0].y1;
	l[3].x1 = l[2].x1;
	l[3].y1 = l[2].y1;
	line(m, l[0], xyh.xyh0 + xyh.xyh1);
	line(m, l[1], xyh.xyh0 + xyh.xyh2);
	line(m, l[2], xyh.xyh2 + xyh.xyh3);
	line(m, l[3], xyh.xyh1 + xyh.xyh3);
}

static t_hm		ft_draw_helper(t_draw d, t_grid **cell, t_hm xyh)
{
	xyh.xyh3 = cell[xyh.i][xyh.j].height;
	xyh.xyh2 = xyh.xyh3;
	xyh.xyh1 = xyh.xyh3;
	xyh.xyh0 = xyh.xyh3;
	if (cell[xyh.i][xyh.j + 1].height != 0 && xyh.j < d.col_count)
	{
		xyh.xyh3 = cell[xyh.i][xyh.j + 1].height;
		xyh.xyh1 = xyh.xyh3;
	}
	if (xyh.i > 0 && cell[xyh.i - 1][xyh.j].height != 0)
	{
		xyh.xyh1 = cell[xyh.i - 1][xyh.j].height;
		xyh.xyh0 = xyh.xyh1;
	}
	if (xyh.i < d.row_count && cell[xyh.i + 1][xyh.j].height != 0)
	{
		xyh.xyh2 = cell[xyh.i + 1][xyh.j].height;
		xyh.xyh3 = xyh.xyh2;
	}
	if (xyh.j > 0 && cell[xyh.i][xyh.j - 1].height != 0)
	{
		xyh.xyh2 = cell[xyh.i][xyh.j - 1].height;
		xyh.xyh0 = xyh.xyh2;
	}
	return (xyh);
}

void			ft_draw(t_draw d, t_grid **cell, t_mlx m)
{
	t_hm		xyh;

	xyh.i = 0;
	xyh.y = 50;
	xyh.gap = d.gap;
	while (xyh.i <= d.row_count)
	{
		xyh.y += xyh.gap;
		xyh.x = 400;
		xyh.j = 0;
		while (xyh.j <= d.col_count)
		{
			xyh = ft_draw_helper(d, cell, xyh);
			xyh.x += xyh.gap;
			ft_cell_draw(cell[xyh.i][xyh.j], xyh, m);
			xyh.j++;
		}
		xyh.i++;
	}
}
