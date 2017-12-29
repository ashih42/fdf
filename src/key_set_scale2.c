/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_scale2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:46:56 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:47:38 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				scale_xyz_dec(t_master *m)
{
	scale_x_dec(m);
	scale_y_dec(m);
	scale_z_dec(m);
	return (0);
}

int				scale_x_dec(t_master *m)
{
	m->scale_x_factor /= SCALE_INC;
	return (0);
}

int				scale_y_dec(t_master *m)
{
	m->scale_y_factor /= SCALE_INC;
	return (0);
}

int				scale_z_dec(t_master *m)
{
	m->scale_z_factor /= SCALE_INC;
	return (0);
}
