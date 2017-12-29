/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_rotate2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:48:17 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:48:51 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				rotate_x_dec(t_master *m)
{
	m->rotate_x_degree -= ROTATE_INC;
	return (0);
}

int				rotate_y_dec(t_master *m)
{
	m->rotate_y_degree -= ROTATE_INC;
	return (0);
}

int				rotate_z_dec(t_master *m)
{
	m->rotate_z_degree -= ROTATE_INC;
	return (0);
}
