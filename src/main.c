#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

void line(void *mlx, void *win, int x0, int y0, int x1, int y1) {
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    mlx_pixel_put(mlx, win, x0,y0, 0x00FFFFFF);
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
	
	y = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 420, 420, "42");
	line(mlx, win, 50, 50, 75, 75);
	sleep(5);
	return (0);
}
