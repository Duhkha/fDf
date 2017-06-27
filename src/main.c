/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 06:37:17 by syoung            #+#    #+#             */
/*   Updated: 2017/06/26 09:09:27 by syoung           ###   ########.fr       */
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

/*int exit_func(int key, void *param)
{
  printf("Key in Win3 : %d\n",key);
  return (key);
 
} */
void	rotate(void *mlx, void *win, int x, int y, int color)
{
	float x1 = (float)x;
	float y1 = (float)y;

	x1 = x1 * cos(0.523599) - y1 * sin(0.523599);
	y1 = x1 * sin(0.523599) + y1 * cos(0.523599);
	mlx_pixel_put(mlx, win, x1, y1, color);
}
void	line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color) {

	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;
	color = 0x00FFFFFF - (color * 10000);
	for(;;){
		rotate(mlx, win, x0,y0, color);
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
	int		fd_2;
	char	*row;
	char	**split;
	int		row_count;
	int		col_count;
	int		xyh0;
	int		xyh1;
	int		xyh2;
	int		xyh3;
	int		multi;
	char		buff[1];

	multi = 1;
	grid	**cell;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "42");
	x = 0;
	y = 50;
	gap = 25;
	row_count = 0;
	col_count = 0;
	if (argc != 2)
	{
		write(1, "Wrong number of arguments.", 26);
		return (0);
	}
	fd_2 = open(argv[1], O_RDONLY);
	while (read(fd_2, buff, 1))
	{
		if (buff[0] == '\n')
			row_count++;
	}
	fd = open(argv[1], O_RDONLY);
	cell = (grid **)malloc(sizeof(grid *) * row_count);
	row_count = 0;
	col_count = 0;
	while (get_next_line(fd, &row))
	{
		split = ft_strsplit((const char*)row, ' ');
		col_count = 0;
		while (split[col_count] != NULL)
			col_count++;
		cell[row_count] = (grid *)malloc(sizeof(grid) * (col_count + 1));
		col_count = 0;
		while(split[col_count] != NULL)
		{
			cell[row_count][col_count].height = ft_atoi((const char*)split[col_count]);
			col_count++;
		}
		row_count++;
	}
	row_count--;
	col_count--;
//	printf("### Row Count:%d\n### Col Count: %d\n", row_count, col_count);
	for (int i = 0; i <= row_count; i++)
	{
		y += gap;
		x = 200;
		for (int j = 0; j <= col_count; j++)
		{
			xyh0 = 0;
			xyh1 = 0;
			xyh2 = 0;
			xyh3 = 0;
			if (j > 0 && i > 0 && j < col_count && i < row_count)
			{
				if (cell[i][j - 1].height > 0)
					xyh0 = xyh2 = cell[i][j - 1].height;	
				if (cell[i - 1][j - 1].height > 0)
					xyh0 = cell[i - 1][j - 1].height;
				if (cell[i - 1][j].height > 0)
					xyh0 = xyh1 = cell[i - 1][j].height;
				if (cell[i - 1][j + 1].height > 0)
					xyh1 = cell[i - 1][j + 1].height;
				if (cell[i][j + 1].height > 0)
					xyh1 = xyh3 = cell[i][j + 1].height;
				if (cell[i + 1][j + 1].height > 0)
					xyh3 = cell[i + 1][j + 1].height;
				if (cell[i + 1][j].height > 0)
					xyh3 = xyh2 = cell[i + 1][j].height;
				if (cell[i + 1][j - 1].height > 0)
					xyh2 = cell[i + 1][j - 1].height;
				if (cell[i][j].height > 0)
					xyh0 = xyh1 = xyh2 = xyh3 =cell[i][j].height;
			}
			x += gap;
			cell[i][j].x0 = x - xyh0 * multi;
			cell[i][j].y0 = y - xyh0 * multi;
			cell[i][j].x1 = (x + gap) - xyh1 * multi;
			cell[i][j].y1 = y - xyh1 * multi;
			cell[i][j].x2 = x - xyh2 * multi;
			cell[i][j].y2 = (y + gap) - xyh2 * multi;
			cell[i][j].x3 = x + gap - xyh3 * multi;
			cell[i][j].y3 = (y + gap) - xyh3 * multi;
			line(mlx, win, cell[i][j].x0, cell[i][j].y0, cell[i][j].x1, cell[i][j].y1, xyh0 + xyh1);
			line(mlx, win, cell[i][j].x0, cell[i][j].y0, cell[i][j].x2, cell[i][j].y2, xyh0 + xyh2);
			line(mlx, win, cell[i][j].x2, cell[i][j].y2, cell[i][j].x3, cell[i][j].y3, xyh2 + xyh3);
			line(mlx, win, cell[i][j].x1, cell[i][j].y1, cell[i][j].x3, cell[i][j].y3, xyh1 + xyh3);

		}
	}
	//mlx_key_hook(win, exit_func, 0);
	//mlx_hook(win, MotionNotify, PointerMotionMask, exit_func, 0);
	mlx_loop(mlx);
	return (0);
}
