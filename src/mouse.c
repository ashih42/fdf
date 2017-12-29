/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:21:49 by ashih             #+#    #+#             */
/*   Updated: 2017/12/27 18:15:54 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_button_down(int button, int x, int y, t_master *m)
{
	if (button == 1)
		m->mouse.lmb_down = 1;
	return (0);
}

int			mouse_button_up(int button, int x, int y, t_master *m)
{
	if (button == 1)
		m->mouse.lmb_down = 0;
	return (0);
}

int			mouse_move(int x, int y, t_master *m)
{
	int		dx;
	int		dy;

	if (m->mouse.lmb_down == 0)
		return (0);
	dx = x - m->mouse.x;
	m->mouse.x = x;
	if (dx > 0)
		rotate_y_inc(m);
	else if (dx < 0)
		rotate_y_dec(m);
	dy = y - m->mouse.y;
	m->mouse.y = y;
	if (dy > 0)
		rotate_x_inc(m);
	else if (dy < 0)
		rotate_x_dec(m);
	render(m);
	return (0);
}
