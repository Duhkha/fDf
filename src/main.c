/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 06:37:17 by syoung            #+#    #+#             */
/*   Updated: 2017/06/26 08:03:10 by syoung           ###   ########.fr       */
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
	int		xyh0;
	int		xyh1;
	int		xyh2;
	int		xyh3;
	int		multi;

	multi = 2;
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
		xyh0 = 0;
		xyh1 = 0;
		xyh2 = 0;
		xyh3 = 0;
		for (int j = 0; j < (col_count); j++)
		{
			xyh0 = 0;
			xyh1 = 0;
			xyh2 = 0;
			xyh3 = 0;
			if (j > 0 && i > 0 && j < col_count && i < row_count)
			{
				if (cell[i][j - 1].height > 0)
				{
					xyh0 = cell[i][j - 1].height * 2;	
					xyh2 = xyh0;
				}
				if (cell[i - 1][j - 1].height > 0)
					xyh0 = cell[i][j - 1].height;
				if (cell[i - 1][j].height > 0)
				{
					xyh0 = cell[i - 1][j].height;
					xyh1 = xyh0;
				}
				if (cell[i - 1][j + 1].height > 0)
					xyh1 = cell[i - 1][j + 1].height;
				if (cell[i][j + 1].height > 0)
				{
					xyh1 = cell[i][j + 1].height;
					xyh3 = xyh1;
				}
				if (cell[i + 1][j + 1].height > 0)
					xyh3 = cell[i + 1][j + 1].height;
				if (cell[i + 1][j].height > 0)
				{
					xyh3 = cell[i + 1][j].height;
					xyh2 = xyh3;
				}
				if (cell[i + 1][j - 1].height > 0)
					xyh2 = cell[i + 1][j - 1].height;
				if (cell[i][j].height > 0)
				{
					xyh0 = cell[i][j].height;
					xyh1 = xyh0;
					xyh2 = xyh0;
					xyh3 = xyh3;
				}
			}
			printf("0: %d\n 1: %d\n 2: %d\n 3: %d\n", xyh0, xyh1, xyh2, xyh3);
			x += gap;
			cell[i][j].x0 = x - xyh0 * multi;
			cell[i][j].y0 = y - xyh0 * multi;
			cell[i][j].x1 = (x + gap) - xyh1 * multi;
			cell[i][j].y1 = y - xyh1 * multi;
			cell[i][j].x2 = x - xyh2 * multi;
			cell[i][j].y2 = (y + gap) - xyh2 * multi;
			cell[i][j].x3 = x + gap - xyh3 * multi;
			cell[i][j].y3 = (y + gap) - xyh3 * multi;
			line(mlx, win, cell[i][j].x0, cell[i][j].y0, cell[i][j].x1, cell[i][j].y1);
			line(mlx, win, cell[i][j].x0, cell[i][j].y0, cell[i][j].x2, cell[i][j].y2);
			line(mlx, win, cell[i][j].x2, cell[i][j].y2, cell[i][j].x3, cell[i][j].y3);
			line(mlx, win, cell[i][j].x1, cell[i][j].y1, cell[i][j].x3, cell[i][j].y3);

		}
	}
	mlx_loop(mlx);
	return (0);
}
