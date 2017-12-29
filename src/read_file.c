/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 02:34:57 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:20:25 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			read_file(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		gnl_flag;
	int		z;
	t_list	*points;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ft_puterror(ERROR_OPEN_FILE));
	map->x_length = -1;
	z = 0;
	points = 0;
	while ((gnl_flag = get_next_line(fd, &line)) != 0)
	{
		if (gnl_flag == -1)
			return (ft_puterror(ERROR_READ_FOLDER));
		if (parse_line(line, map, z++, &points))
			return (1);
		ft_strdel(&line);
	}
	map->z_length = z - 1;
	if (close(fd) == -1)
		return (ft_puterror(ERROR_CLOSE_FILE));
	if (build_points(map, points) || build_edges(map))
		return (1);
	return (0);
}

int			parse_line(char *line, t_map *map, int z, t_list **points)
{
	char	**str_y;
	int		x;
	int		line_length;
	t_list	*row;

	str_y = ft_strsplit(line, ' ');
	if (str_y == 0)
		return (ft_puterror(ERROR_MALLOC));
	line_length = ft_char_array_length(str_y);
	if (line_length == 0)
		return (ft_puterror(ERROR_EMPTY_LINE));
	if (map->x_length == -1)
		map->x_length = line_length - 1;
	if (line_length - 1 != map->x_length)
		return (ft_puterror(ERROR_LINE_LENGTH));
	x = 0;
	while (str_y[x] != 0)
	{
		if (add_point(x, str_y[x], z, points))
			return (1);
		x++;
	}
	x = 0;
	ft_char_array_del(str_y);
	return (0);
}

int			add_point(int x, char *str_y, int z, t_list **points)
{
	int		y;
	int		color;
	t_point	*p;

	if (ft_atoi_check(str_y, &y))
		return (ft_puterror(ERROR_Y_VALUE));
	if (ft_strchr(str_y, ','))
	{
		if (ft_hex_to_int_check(ft_strchr(str_y, ',') + 1, &color))
			return (ft_puterror(ERROR_COLOR_VALUE));
	}
	else
		color = DEFAULT_COLOR;
	if ((p = ft_memalloc(sizeof(t_point))) == 0)
		return (ft_puterror(ERROR_MALLOC));
	p->x = (double)x;
	p->y = (double)y;
	p->z = (double)z;
	p->color = color;
	ft_lstadd(points, ft_lst_new_ref(p, sizeof(t_point)));
	return (0);
}

int			build_points(t_map *map, t_list *points)
{
	int		i;
	t_list	*temp;

	if (!(map->points = malloc(sizeof(t_point *) * (map->x_length + 1) *
			(map->z_length + 1))))
		return (ft_puterror(ERROR_MALLOC));
	i = 0;
	while (i < (map->x_length + 1) * (map->z_length + 1))
	{
		temp = points;
		map->points[i] = points->content;
		points = points->next;
		ft_memdel((void **)&temp);
		i++;
	}
	return (0);
}
