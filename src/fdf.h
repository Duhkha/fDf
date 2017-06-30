/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 06:45:26 by syoung            #+#    #+#             */
/*   Updated: 2017/06/30 08:14:33 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MULTIPLIER 5
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_grid
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			x3;
	int			y3;
	int			height;
	int			row_count;
	int			col_coun;
}				t_grid;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_hm
{
	int			xyh0;
	int			xyh1;
	int			xyh2;
	int			xyh3;
	int			x;
	int			y;
	int			gap;
	int			i;
	int			j;
}				t_hm;
typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_line;
typedef	struct	s_read
{
	int			col_count;
	int			row_count;
	char		buff[1];
	char		*row;
	char		**split;
	int			fd;
	int			i;
	int			j;
}				t_read;
typedef struct	s_draw
{
	int			col_count;
	int			row_count;
	int			gap;
}				t_draw;
typedef struct	s_main
{
	t_mlx		m;
	t_grid		**cell;
	t_draw		d;
}				t_main;
t_grid			**ft_read(char *file, int *row_countp, int *col_countp);
void			ft_draw(t_draw d, t_grid **cell, t_mlx m);
void			line(t_mlx m, t_line l, int color);
void			rotate(t_mlx m, int x, int y, int color);
int				ext(int keycode, void *m);
#endif
