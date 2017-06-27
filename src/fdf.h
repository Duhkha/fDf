#ifndef FDF_H
# define FDF_H
# define MULTIPLIER 3
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct {

	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x3;
	int		y3;
	int		height;

} grid;
typedef struct param
{
	void	*mlx;
	void	*win;
}				p;
typedef struct {
	int	xyh0;
	int	xyh1;
	int	xyh2;
	int	xyh3;
} heightmap;
grid		**ft_read(char *file, int *row_countp, int *col_countp);
void		ft_draw(int col_count, int row_count, grid **cell, int gap, void *mlx, void *win);
//heightmap	ft_fillxyh(int i, grid **cell, int row_count, int col_count);
#endif
