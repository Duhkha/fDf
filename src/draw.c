#include "fdf.h"

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
	color = 0x00FFFFFF - (color * 2000000);
	for(;;){
		rotate(mlx, win, x0,y0, color);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}
void		ft_draw(int col_count, int row_count, grid **cell, int gap, void *mlx, void *win)
{
	int		xyh0;
	int		xyh1;
	int		xyh2;
	int		xyh3;
	int		x;
	int		y;
	int		multi;

	multi = MULTIPLIER;
	y = 50;
	x = 0;
	for (int i = 0; i <= row_count; i++)
	{
		y += gap;
		x = 400;
		for (int j = 0; j <= col_count; j++)
		{
			xyh0 = 0;
			xyh1 = 0;
			xyh2 = 0;
			xyh3 = 0;

			if (cell[i][j].height != 0)
				xyh3 = xyh2 = xyh1 = xyh0 = cell[i][j].height;

				if ((j > 0 && i > 0) && (j < col_count && i < row_count))
				{
					if (cell[i + 1][j - 1].height != 0)
						xyh2 = cell[i + 1][j - 1].height;
					if (cell[i - 1][j + 1].height != 0)
							xyh1 = cell[i - 1][j + 1].height;
				}
			if (i < row_count && j < col_count)
			{
				if (cell[i + 1][j].height != 0)
					xyh2 = xyh3 = cell[i + 1][j].height;
				if (j < col_count && i < row_count)
					if (cell[i + 1][j + 1].height != 0)
						xyh3 = cell[i + 1][j + 1].height;
				if (j < col_count)
					if (cell[i][j + 1].height != 0)
					xyh3 = xyh1 = cell[i][j + 1].height;
				if (i < row_count)
					if (cell[i + 1][j].height != 0)
						xyh2 = xyh3 = cell[i + 1][j].height;
				if (j > 0 && i > 0)
					if (cell[i - 1][j - 1].height != 0)
						xyh0 = cell[i - 1][j - 1].height;
				if (j > 0)
					if (cell[i][j - 1].height != 0)
						xyh2 = xyh0 = cell[i][j - 1].height;
				if (i > 0)
					if (cell[i - 1][j].height != 0)
						xyh1 = xyh0 = cell[i - 1][j].height;
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
}