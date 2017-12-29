/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_screen_coords.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 02:44:12 by ashih             #+#    #+#             */
/*   Updated: 2017/12/28 02:57:34 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		find_screen_coords(t_map *map, t_master *m)
{
	double	matrix[4][4];
	int		i;
	t_point	temp;

	init_matrix(matrix, m);
	i = 0;
	while (i < (map->x_length + 1) * (map->z_length + 1))
	{
		apply_transform(matrix, map->points[i], &temp, m);
		apply_projection(map->points[i], &temp, m);
		map->points[i]->screen_x = (map->points[i]->screen_x + 1.0) / 2.0 *
			(double)WINDOW_WIDTH;
		map->points[i]->screen_y = (map->points[i]->screen_y + 1.0) / 2.0 *
			(double)WINDOW_HEIGHT;
		i++;
	}
}

void		init_matrix(double matrix[4][4], t_master *m)
{
	ft_bzero(matrix, sizeof(double) * 16);
	matrix[0][0] = m->scale_x_factor;
	matrix[1][1] = m->scale_y_factor;
	matrix[2][2] = m->scale_z_factor;
	matrix[3][3] = 1.0;
	mult_rot_z_matrix(matrix, m);
	mult_rot_y_matrix(matrix, m);
	mult_rot_x_matrix(matrix, m);
	mult_trans_matrix(matrix, m);
}

void		apply_transform(double matrix[4][4], t_point *point, t_point *temp,
		t_master *m)
{
	if (m->proj_mode == spherical_proj)
	{
		temp->x = matrix[0][0] * point->x_sph + matrix[0][1] * point->y_sph +
			matrix[0][2] * point->z_sph + matrix[0][3];
		temp->y = matrix[1][0] * point->x_sph + matrix[1][1] * point->y_sph +
			matrix[1][2] * point->z_sph + matrix[1][3];
		temp->z = matrix[2][0] * point->x_sph + matrix[2][1] * point->y_sph +
			matrix[2][2] * point->z_sph + matrix[2][3];
	}
	else
	{
		temp->x = matrix[0][0] * point->x + matrix[0][1] * point->y +
			matrix[0][2] * point->z + matrix[0][3];
		temp->y = matrix[1][0] * point->x + matrix[1][1] * point->y +
			matrix[1][2] * point->z + matrix[1][3];
		temp->z = matrix[2][0] * point->x + matrix[2][1] * point->y +
			matrix[2][2] * point->z + matrix[2][3];
	}
}

void		apply_projection(t_point *point, t_point *temp, t_master *m)
{
	if (m->proj_mode == perspect_proj)
	{
		point->screen_x = temp->x * -1.0 / temp->z;
		point->screen_y = temp->y / temp->z;
	}
	else if (m->proj_mode == parallel_proj)
	{
		point->screen_x = temp->x;
		point->screen_y = temp->y * -1.0;
	}
	else if (m->proj_mode == spherical_proj)
	{
		point->screen_x = temp->x;
		point->screen_y = temp->y * -1.0;
	}
}
