/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 04:59:35 by ashih             #+#    #+#             */
/*   Updated: 2017/12/28 02:55:53 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_dot(int x, int y, int color, t_master *m)
{
	if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
		*(int *)(m->frame + (x + y * WINDOW_WIDTH) * m->bpp) = color;
}

void		draw_line(t_point *p0, t_point *p1, t_master *m)
{
	int		steps;
	int		i;
	t_point	p;
	double	x_increment;
	double	y_increment;

	steps = ft_max(
		ft_abs(ft_round_dbl(p1->screen_x) - ft_round_dbl(p0->screen_x)),
		ft_abs(ft_round_dbl(p1->screen_y) - ft_round_dbl(p0->screen_y)));
	i = 0;
	p.screen_x = p0->screen_x;
	p.screen_y = p0->screen_y;
	p.color = p0->color;
	x_increment = (p1->screen_x - p0->screen_x) / (double)steps;
	y_increment = (p1->screen_y - p0->screen_y) / (double)steps;
	while (i <= steps)
	{
		draw_dot(ft_round_dbl(p.screen_x),
			ft_round_dbl(p.screen_y), p.color, m);
		p.screen_x += x_increment;
		p.screen_y += y_increment;
		i++;
		interp_color(p0->color, p1->color, &(p.color),
			(double)i / (double)steps);
	}
}

void		draw_line_h(t_point *p0, t_point *p1, t_master *m)
{
	int		steps;
	int		i;
	t_point	p;
	double	x_increment;
	double	y_increment;

	steps = ft_max(
		ft_abs(ft_round_dbl(p1->screen_x) - ft_round_dbl(p0->screen_x)),
		ft_abs(ft_round_dbl(p1->screen_y) - ft_round_dbl(p0->screen_y)));
	i = 0;
	p.screen_x = p0->screen_x;
	p.screen_y = p0->screen_y;
	p.color_h = p0->color_h;
	x_increment = (p1->screen_x - p0->screen_x) / (double)steps;
	y_increment = (p1->screen_y - p0->screen_y) / (double)steps;
	while (i <= steps)
	{
		draw_dot(ft_round_dbl(p.screen_x), ft_round_dbl(p.screen_y),
			p.color_h, m);
		p.screen_x += x_increment;
		p.screen_y += y_increment;
		i++;
		interp_color(p0->color_h, p1->color_h, &(p.color_h),
			(double)i / (double)steps);
	}
}

void		interp_color(int color_0, int color_1, int *color, double k)
{
	int		r;
	int		g;
	int		b;

	if (color == 0)
		return ;
	r = ft_round_dbl((1.0 - k) * (double)(color_0 >> 16 & 0xFF) +
			k * (double)(color_1 >> 16 & 0xFF));
	g = ft_round_dbl((1.0 - k) * (double)(color_0 >> 8 & 0xFF) +
			k * (double)(color_1 >> 8 & 0xFF));
	b = ft_round_dbl((1.0 - k) * (double)(color_0 & 0xFF) +
			k * (double)(color_1 & 0xFF));
	*color = (r << 16) + (g << 8) + b;
}
