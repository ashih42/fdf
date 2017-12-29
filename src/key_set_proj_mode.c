/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_proj_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:42:22 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:11:28 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				set_proj_mode_perspect(t_master *m)
{
	if (m->proj_mode == parallel_proj)
	{
		m->scale_x_factor *= (double)(m->map->z_length);
		m->scale_y_factor *= (double)(m->map->z_length);
		m->scale_z_factor *= (double)(m->map->z_length);
	}
	m->proj_mode = perspect_proj;
	return (0);
}

int				set_proj_mode_parallel(t_master *m)
{
	if (m->proj_mode != parallel_proj)
	{
		m->scale_x_factor /= (double)(m->map->z_length);
		m->scale_y_factor /= (double)(m->map->z_length);
		m->scale_z_factor /= (double)(m->map->z_length);
	}
	m->proj_mode = parallel_proj;
	return (0);
}

int				set_proj_mode_spherical(t_master *m)
{
	if (m->proj_mode == parallel_proj)
	{
		m->scale_x_factor *= (double)(m->map->z_length);
		m->scale_y_factor *= (double)(m->map->z_length);
		m->scale_z_factor *= (double)(m->map->z_length);
	}
	m->proj_mode = spherical_proj;
	return (0);
}
