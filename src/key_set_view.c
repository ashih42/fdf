/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:44:00 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:12:01 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				set_view_iso(t_master *m)
{
	m->viewpoint = view_iso;
	m->rotate_x_degree = 45.0;
	m->rotate_y_degree = 35.264;
	m->rotate_z_degree = 0.0;
	return (0);
}

int				set_view_neg_x(t_master *m)
{
	m->viewpoint = view_neg_x;
	m->rotate_x_degree = 0.0;
	m->rotate_y_degree = -90.0;
	m->rotate_z_degree = 0.0;
	return (0);
}

int				set_view_neg_y(t_master *m)
{
	m->viewpoint = view_neg_y;
	m->rotate_x_degree = 90.0;
	m->rotate_y_degree = 0.0;
	m->rotate_z_degree = 0.0;
	return (0);
}

int				set_view_neg_z(t_master *m)
{
	m->viewpoint = view_neg_z;
	m->rotate_x_degree = 0.0;
	m->rotate_y_degree = 0.0;
	m->rotate_z_degree = 0.0;
	return (0);
}
