/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_3d_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 02:35:27 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:20:07 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					compute_3d_params(t_map *map)
{
	unsigned int	i;

	find_map_height(map);
	i = 0;
	while (i < (map->x_length + 1) * (map->z_length + 1))
	{
		interp_color(COLOR_MIN_HEIGHT, COLOR_MAX_HEIGHT,
			&(map->points[i]->color_h),
			(map->points[i]->y - map->y_min) / map->y_length);
		set_sph_coords(map->points[i], map);
		map->points[i]->x -= (double)(map->x_length) / 2.0;
		map->points[i]->y -= (double)(map->y_length) / 2.0;
		map->points[i]->z -= (double)(map->z_length) / 2.0;
		i++;
	}
	return (build_edges(map));
}

void				find_map_height(t_map *map)
{
	unsigned int	i;
	double			min;
	double			max;

	i = 0;
	min = map->points[i]->y;
	max = map->points[i++]->y;
	while (i < (map->x_length + 1) * (map->z_length + 1))
	{
		if (map->points[i]->y > max)
			max = map->points[i]->y;
		if (map->points[i]->y < min)
			min = map->points[i]->y;
		i++;
	}
	map->y_length = (unsigned int)(max - min);
	map->y_min = min;
}

void				set_sph_coords(t_point *point, t_map *map)
{
	double			rho;
	double			phi;
	double			theta;

	rho = point->y - map->y_min;
	if (map->y_length != 0)
		rho /= (double)(map->y_length);
	rho += 1.0;
	theta = point->x / (double)(map->x_length) * 2.0 * M_PI;
	phi = point->z / (double)(map->z_length) * M_PI * -1.0;
	point->x_sph = rho * sin(phi) * cos(theta);
	point->z_sph = rho * sin(phi) * sin(theta);
	point->y_sph = rho * cos(phi);
}

int					build_edges(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (++i < (map->x_length + 1) * (map->z_length + 1))
	{
		if ((i + 1) % (map->x_length + 1) != 0)
		{
			if (add_edge(map->points[i], map->points[i + 1], &(map->edges)))
				return (1);
		}
		else
		{
			if (add_edge(map->points[i], map->points[i - map->x_length],
					&(map->edges_sph)))
				return (1);
		}
		if (i + (map->x_length + 1) < (map->x_length + 1) * (map->z_length + 1))
		{
			if (add_edge(map->points[i], map->points[i + map->x_length + 1],
				&(map->edges)))
				return (1);
		}
	}
	return (0);
}

int					add_edge(t_point *point_0, t_point *point_1, t_list **edges)
{
	t_edge			*e;

	if (!(e = ft_memalloc(sizeof(t_edge))))
		return (ft_puterror(ERROR_MALLOC));
	e->point_0 = point_0;
	e->point_1 = point_1;
	ft_lstadd(edges, ft_lst_new_ref(e, sizeof(t_edge)));
	return (0);
}
