/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 02:40:04 by ashih             #+#    #+#             */
/*   Updated: 2017/12/28 02:53:04 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			render(t_master *m)
{
	ft_bzero(m->frame, WINDOW_WIDTH * WINDOW_HEIGHT * m->bpp);
	find_screen_coords(m->map, m);
	draw_all_edges(m->map->edges, m);
	if (m->proj_mode == spherical_proj)
		draw_all_edges(m->map->edges_sph, m);
	mlx_clear_window(m->mlx, m->win);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	render_text(m);
	return (0);
}

void		render_text(t_master *m)
{
	static const char *proj_text[] = {PROJ_PERSPECT, PROJ_PARALLEL,
		PROJ_SPHERICAL};
	static const char *color_text[] = {COLOR_DEFAULT, COLOR_HEIGHT};
	static const char *view_text[] = {VIEW_ISO, VIEW_NEG_Z, VIEW_NEG_X,
		VIEW_NEG_Y, VIEW_POS_Z, VIEW_POS_X, VIEW_POS_Y};

	ft_printf("%s\n", proj_text[m->proj_mode]);
	ft_printf("%s\n", color_text[m->color_mode]);
	ft_printf("%s\n", view_text[m->viewpoint]);
	ft_printf("Scale X by: %.4f\n", m->scale_x_factor);
	ft_printf("Scale Y by: %.4f\n", m->scale_y_factor);
	ft_printf("Scale Z by: %.4f\n", m->scale_z_factor);
	ft_printf("Rotate around X-axis by: %.2f degrees\n", m->rotate_x_degree);
	ft_printf("Rotate around Y-axis by: %.2f degrees\n", m->rotate_y_degree);
	ft_printf("Rotate around Z-axis by: %.2f degrees\n", m->rotate_z_degree);
	ft_printf("Translate along X by: %.2f\n", m->translate_x_dist);
	ft_printf("Translate along Y by: %.2f\n", m->translate_y_dist);
	ft_printf("Translate along Z by: %.2f\n\n", m->translate_z_dist);
	mlx_string_put(m->mlx, m->win, 0, 0, DEFAULT_COLOR,
		(char *)proj_text[m->proj_mode]);
	mlx_string_put(m->mlx, m->win, 0, 20, DEFAULT_COLOR,
		(char *)color_text[m->color_mode]);
	mlx_string_put(m->mlx, m->win, 0, 40, DEFAULT_COLOR,
		(char *)view_text[m->viewpoint]);
}

void		draw_all_edges(t_list *edges, t_master *m)
{
	t_edge	*e;

	while (edges != 0)
	{
		e = edges->content;
		if (m->color_mode == color_default)
			draw_line(e->point_0, e->point_1, m);
		else
			draw_line_h(e->point_0, e->point_1, m);
		edges = edges->next;
	}
}
