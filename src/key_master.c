/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_master.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:50:42 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:00:50 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Keycode		Key						Function
** 53			ESC						Terminate program
** 49			SPACE					Reset all projection params to default
** 18			1 (below F keys)		Perspective projection
** 19			2 (below F keys)		Parallel projection
** 20			3 (below F keys)		Spherical projection
** 21			4 (below F keys)		Color mode: default
** 23			5 (below F keys)		Color mode: height-based
** 24			+ (below F keys)		Scale X,Y,Z increase
** 27			- (below F keys)		Scale X,Y,Z decrease
** 12			Q						Scale X increase
** 13			W						Scale X decrease
** 14			E						Scale Y increase
** 15			R						Scale Y decrease
** 17			T						Scale Z increase
** 16			Y						Scale Z decrease
** 0			A						Rotate around X-axis angle increase
** 1			S						Rotate around X-axis angle decrease
** 2			D						Rotate around Y-axis angle increase
** 3			F						Rotate around Y-axis angle decrease
** 5			G						Rotate around Z-axis angle increase
** 4			H						Rotate around Z-axis angle decrease
** 6			Z						Translate along +X
** 7			X						Translate along -X
** 8			C						Translate along +Y
** 9			V						Translate along -Y
** 11			B						Translate along +Z
** 45			N						Translate along -Z
** 82			0 (numpad)				View: Isometric
** 83			1 (numpad)				View: Toward -Z axis
** 84			2 (numpad)				View: Toward -X axis
** 85			3 (numpad)				View: Toward -Y axis
** 86			4 (numpad)				View: Toward +Z axis
** 87			5 (numpad)				View: Toward +X axis
** 88			6 (numpad)				View: Toward +Y axis
** -1			(n/a)					(sentinel value)
*/

int							key_master(int keycode, void *param)
{
	int						i;
	static const t_key_map	g_key_map[] = {{53, terminate},
	{49, reset_proj_params}, {18, set_proj_mode_perspect},
	{19, set_proj_mode_parallel}, {20, set_proj_mode_spherical},
	{21, set_color_mode_default}, {23, set_color_mode_height},
	{24, scale_xyz_inc}, {27, scale_xyz_dec}, {12, scale_x_inc},
	{13, scale_x_dec}, {14, scale_y_inc}, {15, scale_y_dec}, {17, scale_z_inc},
	{16, scale_z_dec}, {0, rotate_x_inc}, {1, rotate_x_dec}, {2, rotate_y_inc},
	{3, rotate_y_dec}, {5, rotate_z_inc}, {4, rotate_z_dec},
	{6, translate_x_inc}, {7, translate_x_dec}, {8, translate_y_inc},
	{9, translate_y_dec}, {11, translate_z_inc}, {45, translate_z_dec},
	{82, set_view_iso}, {83, set_view_neg_z}, {84, set_view_neg_x},
	{85, set_view_neg_y}, {86, set_view_pos_z}, {87, set_view_pos_x},
	{88, set_view_pos_y}, {-1, 0}};

	i = -1;
	while (g_key_map[++i].keycode != -1)
	{
		if (g_key_map[i].keycode == keycode)
		{
			g_key_map[i].func(param);
			break ;
		}
	}
	return (render(param));
}

int							terminate(t_master *m)
{
	free_all(m);
	exit(0);
	return (0);
}

int							reset_proj_params(t_master *m)
{
	m->proj_mode = perspect_proj;
	m->color_mode = color_default;
	m->scale_x_factor = 1.0;
	m->scale_y_factor = 1.0;
	m->scale_z_factor = 1.0;
	m->rotate_x_degree = 45.0;
	m->rotate_y_degree = 35.264;
	m->rotate_z_degree = 0.0;
	m->translate_x_dist = 0.0;
	m->translate_y_dist = 0.0;
	m->translate_z_dist = m->map->z_length * -1.0 - 1.0;
	return (0);
}
