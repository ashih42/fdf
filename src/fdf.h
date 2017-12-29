/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:49:40 by ashih             #+#    #+#             */
/*   Updated: 2017/12/29 12:22:08 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define W_NAME "fdf"

# define USAGE_ERROR "usage: fdf input_file\n"
# define ERROR_OPEN_FILE "No such file"
# define ERROR_READ_FOLDER "Is a directory"
# define ERROR_CLOSE_FILE "Cannot close file"
# define ERROR_MALLOC "Out of memory"
# define ERROR_EMPTY_LINE "Invalid map: Empty line"
# define ERROR_LINE_LENGTH "Invalid map: Line length mismatch"
# define ERROR_Y_VALUE "Invalid map: Invalid height value"
# define ERROR_COLOR_VALUE "Invalid map: Invalid color value"

# define PROJ_PERSPECT "Perspective Projection"
# define PROJ_PARALLEL "Parallel Projection"
# define PROJ_SPHERICAL "Spherical Projection"

# define COLOR_DEFAULT "Color Mode: Default"
# define COLOR_HEIGHT "Color Mode: Height"

# define VIEW_ISO "View: Isometric"
# define VIEW_NEG_Z "View: Toward -Z Axis"
# define VIEW_NEG_X "View: Toward -X Axis"
# define VIEW_NEG_Y "View: Toward -Y Axis"
# define VIEW_POS_Z "View: Toward +Z Axis"
# define VIEW_POS_X "View: Toward +X Axis"
# define VIEW_POS_Y "View: Toward +Y Axis"

# define DEFAULT_COLOR 0xFFFFFF
# define COLOR_MIN_HEIGHT 0x0000FF
# define COLOR_MAX_HEIGHT 0xFF0000

# define SCALE_INC 1.2
# define ROTATE_INC 5.0
# define TRANSLATE_INC 0.5

# define RAD_TO_DEG(a) a * 180.0 / M_PI
# define DEG_TO_RAD(a) a * M_PI / 180.0

enum			e_proj_mode
{
	perspect_proj = 0,
	parallel_proj = 1,
	spherical_proj = 2
};

enum			e_color_mode
{
	color_default = 0,
	color_height = 1
};

enum			e_viewpoint
{
	view_iso = 0,
	view_neg_z = 1,
	view_neg_x = 2,
	view_neg_y = 3,
	view_pos_z = 4,
	view_pos_x = 5,
	view_pos_y = 6
};

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			x_sph;
	double			y_sph;
	double			z_sph;
	int				color;
	int				color_h;
	double			screen_x;
	double			screen_y;
}					t_point;

typedef struct		s_edge
{
	t_point			*point_0;
	t_point			*point_1;
}					t_edge;

typedef struct		s_map
{
	t_point			**points;
	t_list			*edges;
	t_list			*edges_sph;
	unsigned int	x_length;
	unsigned int	y_length;
	unsigned int	z_length;
	double			y_min;
}					t_map;

typedef struct		s_mouse
{
	int				lmb_down;
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_master
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map			*map;
	char			*frame;
	int				bpp;
	int				size_line;
	int				endian;
	int				proj_mode;
	int				color_mode;
	int				viewpoint;
	double			scale_x_factor;
	double			scale_y_factor;
	double			scale_z_factor;
	double			rotate_x_degree;
	double			rotate_y_degree;
	double			rotate_z_degree;
	double			translate_x_dist;
	double			translate_y_dist;
	double			translate_z_dist;
	t_mouse			mouse;
}					t_master;

typedef struct		s_key_map
{
	int				keycode;
	int				(*func)(t_master *);
}					t_key_map;

/*
** key_master.c
*/
int					key_master(int keycode, void *param);
int					terminate(t_master *m);
int					reset_proj_params(t_master *m);

/*
** key_set_proj_mode.c
*/
int					set_proj_mode_perspect(t_master *m);
int					set_proj_mode_parallel(t_master *m);
int					set_proj_mode_spherical(t_master *m);

/*
** key_set_color_mode.c
*/
int					set_color_mode_default(t_master *m);
int					set_color_mode_height(t_master *m);

/*
** key_set_view.c
*/
int					set_view_iso(t_master *m);
int					set_view_neg_x(t_master *m);
int					set_view_neg_y(t_master *m);
int					set_view_neg_z(t_master *m);

/*
** key_set_view2.c
*/
int					set_view_pos_x(t_master *m);
int					set_view_pos_y(t_master *m);
int					set_view_pos_z(t_master *m);

/*
** key_set_scale.c
*/
int					scale_xyz_inc(t_master *m);
int					scale_x_inc(t_master *m);
int					scale_y_inc(t_master *m);
int					scale_z_inc(t_master *m);

/*
** key_set_scale2.c
*/
int					scale_xyz_dec(t_master *m);
int					scale_x_dec(t_master *m);
int					scale_y_dec(t_master *m);
int					scale_z_dec(t_master *m);

/*
** key_set_rotate.c
*/
int					rotate_x_inc(t_master *m);
int					rotate_y_inc(t_master *m);
int					rotate_z_inc(t_master *m);

/*
** key_set_rotate2.c
*/
int					rotate_x_dec(t_master *m);
int					rotate_y_dec(t_master *m);
int					rotate_z_dec(t_master *m);

/*
** key_set_translate.c
*/
int					translate_x_inc(t_master *m);
int					translate_y_inc(t_master *m);
int					translate_z_inc(t_master *m);

/*
** key_set_translate2.c
*/
int					translate_x_dec(t_master *m);
int					translate_y_dec(t_master *m);
int					translate_z_dec(t_master *m);

/*
** mouse.c
*/
int					mouse_button_down(int button, int x, int y, t_master *m);
int					mouse_button_up(int button, int x, int y, t_master *m);
int					mouse_move(int x, int y, t_master *m);

/*
** draw_line.c
*/
void				draw_dot(int x, int y, int color, t_master *m);
void				draw_line(t_point *p0, t_point *p1, t_master *m);
void				draw_line_h(t_point *p0, t_point *p1, t_master *m);
void				interp_color(int color_0, int color_1, int *color,
		double k);

/*
** render.c
*/
int					render(t_master *m);
void				render_text(t_master *m);
void				draw_all_edges(t_list *edges, t_master *m);

/*
** matrix.c
*/
void				mult_matrices(double m1[4][4], double m2[4][4]);
void				mult_rot_x_matrix(double matrix[4][4], t_master *m);
void				mult_rot_y_matrix(double matrix[4][4], t_master *m);
void				mult_rot_z_matrix(double matrix[4][4], t_master *m);
void				mult_trans_matrix(double matrix[4][4], t_master *m);

/*
** find_screen_coords.c
*/
void				find_screen_coords(t_map *map, t_master *m);
void				init_matrix(double matrix[4][4], t_master *m);
void				apply_transform(double matrix[4][4], t_point *point,
		t_point *temp, t_master *m);
void				apply_projection(t_point *point, t_point *temp,
		t_master *m);

/*
** compute_3d_params.c
*/
int					compute_3d_params(t_map *map);
void				find_map_height(t_map *map);
void				set_sph_coords(t_point *point, t_map *map);
int					build_edges(t_map *map);
int					add_edge(t_point *point_0, t_point *point_1,
		t_list **edges);

/*
** read_file.c
*/
int					read_file(char *filename, t_map *map);
int					parse_line(char *line, t_map *map, int x, t_list **points);
int					add_point(int x, char *str_y, int z, t_list **points);
int					build_points(t_map *map, t_list *points);

/*
** main.c
*/
int					init_master(t_master *m, char *input_file);
int					main(int argc, char **argv);

/*
** freedom.c
*/
int					free_all(t_master *m);
void				free_points(t_map *map);
void				free_edges(t_list *edges);

#endif
