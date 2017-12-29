/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_color_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:43:19 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 05:43:44 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				set_color_mode_default(t_master *m)
{
	m->color_mode = color_default;
	return (0);
}

int				set_color_mode_height(t_master *m)
{
	m->color_mode = color_height;
	return (0);
}
