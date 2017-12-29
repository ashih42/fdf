/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:09:08 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:20:31 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				init_master(t_master *m, char *input_file)
{
	ft_bzero(m, sizeof(t_master));
	if (!(m->mlx = mlx_init()) ||
		!(m->win = mlx_new_window(m->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, W_NAME))
		|| !(m->img = mlx_new_image(m->mlx, WINDOW_WIDTH, WINDOW_HEIGHT)) ||
		!(m->frame = mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line),
		&(m->endian))) || !(m->map = ft_memalloc(sizeof(t_map))))
	{
		free_all(m);
		return (ft_puterror(ERROR_MALLOC));
	}
	if (read_file(input_file, m->map) || compute_3d_params(m->map))
		return (free_all(m));
	m->bpp /= 8;
	ft_bzero(m->frame, WINDOW_WIDTH * WINDOW_HEIGHT * m->bpp);
	reset_proj_params(m);
	render(m);
	return (0);
}

int				main(int argc, char **argv)
{
	t_master	m;

	if (argc != 2)
	{
		ft_putstr(USAGE_ERROR);
		return (0);
	}
	if (init_master(&m, argv[1]))
		return (0);
	mlx_hook(m.win, 4, 0, mouse_button_down, &m);
	mlx_hook(m.win, 5, 0, mouse_button_up, &m);
	mlx_hook(m.win, 6, 0, mouse_move, &m);
	mlx_key_hook(m.win, key_master, &m);
	mlx_loop(m.mlx);
	return (0);
}
