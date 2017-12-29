/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:49:05 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:49:53 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				translate_x_inc(t_master *m)
{
	m->translate_x_dist += TRANSLATE_INC;
	return (0);
}

int				translate_y_inc(t_master *m)
{
	m->translate_y_dist += TRANSLATE_INC;
	return (0);
}

int				translate_z_inc(t_master *m)
{
	m->translate_z_dist += TRANSLATE_INC;
	return (0);
}
