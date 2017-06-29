/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 06:37:17 by syoung            #+#    #+#             */
/*   Updated: 2017/06/29 07:59:05 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ext(int keycode, void *m)
{
	t_mlx	*temp;

	temp = (t_mlx *)m;
	if (keycode == 53)
	{
		mlx_destroy_window(temp->mlx, temp->win);
		exit(0);
	}
	return (keycode);
}

int		main(int argc, char **argv)
{
	int		gap;
	int		row_count;
	int		col_count;
	t_grid	**cell;
	t_mlx	m;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, 1000, 1000, "42");
	gap = 1;
	row_count = 1;
	col_count = 0;
	if (argc != 2)
		return (0);
	cell = ft_read(argv[1], &row_count, &col_count);
	while (gap * col_count < 600 && gap * row_count < 600)
		gap++;
	row_count--;
	col_count--;
	ft_draw(col_count, row_count, cell, gap, m);
	row_count++;
	mlx_key_hook(m.win, ext, &m);
	mlx_loop(m.mlx);
	return (0);
}
