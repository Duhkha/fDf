/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 06:37:17 by syoung            #+#    #+#             */
/*   Updated: 2017/06/30 08:05:34 by syoung           ###   ########.fr       */
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
int		expose(void *h)
{
	t_main *temp;

	temp = (t_main *)h;
	mlx_clear_window(temp->m.mlx, temp->m.win);
	ft_draw(temp->d, temp->cell, temp->m);
	return (1);
}
int		main(int argc, char **argv)
{
	t_main	h;

	h.d.gap = 1;
	h.d.row_count = 1;
	h.d.col_count = 0;
	if (argc != 2)
		return (0);
	h.cell = ft_read(argv[1], &h.d.row_count, &h.d.col_count);
	while (h.d.gap * h.d.col_count < 600 && h.d.gap * h.d.row_count < 600)
		h.d.gap++;
	h.d.row_count--;
	h.d.col_count--;
	h.m.mlx = mlx_init();
	h.m.win = mlx_new_window(h.m.mlx, 1000, 1000, "42");
	mlx_expose_hook(h.m.win, expose, &h);
	mlx_key_hook(h.m.win, ext, &h.m);
	mlx_loop(h.m.mlx);
	return (0);
}
