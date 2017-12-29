/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:46:04 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:46:49 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				scale_xyz_inc(t_master *m)
{
	scale_x_inc(m);
	scale_y_inc(m);
	scale_z_inc(m);
	return (0);
}

int				scale_x_inc(t_master *m)
{
	m->scale_x_factor *= SCALE_INC;
	return (0);
}

int				scale_y_inc(t_master *m)
{
	m->scale_y_factor *= SCALE_INC;
	return (0);
}

int				scale_z_inc(t_master *m)
{
	m->scale_z_factor *= SCALE_INC;
	return (0);
}
