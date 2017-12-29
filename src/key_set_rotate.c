/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:47:43 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:48:13 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				rotate_x_inc(t_master *m)
{
	m->rotate_x_degree += ROTATE_INC;
	return (0);
}

int				rotate_y_inc(t_master *m)
{
	m->rotate_y_degree += ROTATE_INC;
	return (0);
}

int				rotate_z_inc(t_master *m)
{
	m->rotate_z_degree += ROTATE_INC;
	return (0);
}
