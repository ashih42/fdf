/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:22:48 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:03:57 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				free_all(t_master *m)
{
	free_points(m->map);
	free_edges(m->map->edges);
	free_edges(m->map->edges_sph);
	ft_memdel((void **)&(m->map));
	ft_memdel((void **)&(m->frame));
	ft_memdel(&(m->img));
	ft_memdel(&(m->win));
	ft_memdel(&(m->mlx));
	return (1);
}

void			free_points(t_map *map)
{
	int			i;

	if (map->points != 0)
	{
		i = 0;
		while (i < (map->x_length + 1) * (map->z_length + 1))
		{
			ft_memdel((void **)&(map->points[i]));
			i++;
		}
	}
	ft_memdel((void **)&(map->points));
}

void			free_edges(t_list *edges)
{
	t_edge		*e;
	t_list		*temp;

	while (edges != 0)
	{
		e = edges->content;
		temp = edges;
		edges = edges->next;
		ft_memdel((void **)&e);
		ft_memdel((void **)&temp);
	}
}
