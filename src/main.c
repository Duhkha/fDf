#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

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
//	int		x;
//	int		y;
	int		fd;
	char	*row;
	int		map[100][100];
	char	**split;
	int		row_count;
	int		col_count;
	int		len;

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
			ft_putnbr(len);
			ft_putchar('\n');
			col_count = 0;
			while(col_count < 21)
			{
				map[row_count][col_count] = ft_atoi((const char*)split[col_count]);
				ft_putnbr(map[row_count][col_count]);
				col_count++;
			}
			row_count++;
			free(split);
		}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	line(mlx, win, 50, 50, 100, 50);
	line(mlx, win, 50, 100, 100, 100);
	line(mlx, win, 50, 50, 50, 100);
	line(mlx, win, 100, 50, 100, 100);
	mlx_loop(mlx);
	return (0);
}
