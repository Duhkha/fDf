/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 06:37:17 by syoung            #+#    #+#             */
/*   Updated: 2017/06/26 07:14:47 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "fdf.h"

void rotate(void *mlx, void *win, int x, int y)
{
	float x1 = (float)x;
	float y1 = (float)y;

	x1 = x1 * cos(0.523599) - y1 * sin(0.523599);
	y1 = x1 * sin(0.523599) + y1 * cos(0.523599);
	mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
}
void line(void *mlx, void *win, int x0, int y0, int x1, int y1) {

	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

	for(;;){
		rotate(mlx, win, x0,y0);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}
int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		gap;
	int		fd;
	char	*row;
	int		map[100][100];
	char	**split;
	int		row_count;
	int		col_count;
	int		len;
	int		height;
	int		lheight;
	int		rheight;
	int		bheight;
	int		theight;

	lheight = 0;
	rheight = 0;
	bheight = 0;
	theight = 0;
	height = 0;
	grid cell[20][20];

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 1200, "42");
	//mlx_loop(mlx);
	x = 0;
	y = 100;
	gap = 35;
	row_count = 0;
	col_count = 0;
	if (argc != 2)
	{
		write(1, "Wrong number of arguments.\n", 28);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &row))
	{
		split = ft_strsplit((const char*)row, ' ');
		col_count = 0;
		while(split[col_count] != NULL)
		{
			map[row_count][col_count] = ft_atoi((const char*)split[col_count]);
			col_count++;
		}
		row_count++;
		free(split);
	}
//	grid **cell = (grid **)malloc(sizeof(grid *) * row_count);
//	for (int i = 0; i < col_count; i++)
//		cell[i] = (grid *)malloc(sizeof(grid) * col_count);
	for (int i = 0; i < row_count; i++)
		for (int j = 0; j < col_count; j++)
			cell[i][j].height = map[i][j];
	for (int i = 0; i < row_count; i++)
	{
		y += gap;
		x = 400;
		height = 1;
		rheight = 0;
		lheight = 0;
		bheight = 0;
		theight = 0;
		for (int j = 0; j < (col_count); j++)
		{
			if (j < col_count)
				rheight = -2 * cell[i][j + 1].height;
			if (j > 0)
				lheight = -2 * cell[i][j - 1].height;
			if (i < row_count)
				bheight = -2 * cell[i + 1][j].height;
			if (i > 0)
				theight = -2 * cell[i - 1][j].height;
			x += gap;
			cell[i][j].x0 = x + (theight + lheight);
			cell[i][j].y0 = y + (theight + lheight);
			cell[i][j].x1 = (x + gap) + (theight + rheight);
			cell[i][j].y1 = y + (theight + rheight);
			cell[i][j].x2 = x + (bheight + lheight);
			cell[i][j].y2 = (y + gap) + (bheight + lheight);
			cell[i][j].x3 = x + gap + (bheight + rheight);
			cell[i][j].y3 = (y + gap) + (bheight + rheight);
			line(mlx, win, cell[i][j].x0, cell[i][j].y0, cell[i][j].x1, cell[i][j].y1);
			line(mlx, win, cell[i][j].x0, cell[i][j].y0, cell[i][j].x2, cell[i][j].y2);
			line(mlx, win, cell[i][j].x2, cell[i][j].y2, cell[i][j].x3, cell[i][j].y3);
			line(mlx, win, cell[i][j].x1, cell[i][j].y1, cell[i][j].x3, cell[i][j].y3);

		}
	}
	mlx_loop(mlx);
	return (0);
}
