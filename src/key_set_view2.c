/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_view2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:45:17 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:45:50 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				set_view_pos_x(t_master *m)
{
	m->viewpoint = view_pos_x;
	m->rotate_x_degree = 0.0;
	m->rotate_y_degree = 90.0;
	m->rotate_z_degree = 0.0;
	return (0);
}

int				set_view_pos_y(t_master *m)
{
	m->viewpoint = view_pos_y;
	m->rotate_x_degree = -90.0;
	m->rotate_y_degree = 0.0;
	m->rotate_z_degree = 0.0;
	return (0);
}

int				set_view_pos_z(t_master *m)
{
	m->viewpoint = view_pos_z;
	m->rotate_x_degree = 0.0;
	m->rotate_y_degree = 180.0;
	m->rotate_z_degree = 0.0;
	return (0);
}
