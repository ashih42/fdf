/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 03:41:13 by ashih             #+#    #+#             */
/*   Updated: 2017/12/28 02:56:35 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** void		mult_matrices(double m1[4][4], double m2[4][4]);
**
** Multiply m1 x m2, and store the result in m2
*/

void		mult_matrices(double m1[4][4], double m2[4][4])
{
	double	temp[4][4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] +
				m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
			j++;
		}
		i++;
	}
	ft_memmove(m2, &temp, sizeof(temp));
}

void		mult_rot_x_matrix(double matrix[4][4], t_master *m)
{
	double	rot_x_matrix[4][4];

	ft_bzero(rot_x_matrix, sizeof(double) * 16);
	rot_x_matrix[0][0] = 1.0;
	rot_x_matrix[1][1] = cos(DEG_TO_RAD(m->rotate_x_degree));
	rot_x_matrix[1][2] = sin(DEG_TO_RAD(m->rotate_x_degree)) * -1.0;
	rot_x_matrix[2][1] = sin(DEG_TO_RAD(m->rotate_x_degree));
	rot_x_matrix[2][2] = cos(DEG_TO_RAD(m->rotate_x_degree));
	rot_x_matrix[3][3] = 1.0;
	mult_matrices(rot_x_matrix, matrix);
}

void		mult_rot_y_matrix(double matrix[4][4], t_master *m)
{
	double	rot_y_matrix[4][4];

	ft_bzero(rot_y_matrix, sizeof(double) * 16);
	rot_y_matrix[0][0] = cos(DEG_TO_RAD(m->rotate_y_degree));
	rot_y_matrix[0][2] = sin(DEG_TO_RAD(m->rotate_y_degree));
	rot_y_matrix[1][1] = 1.0;
	rot_y_matrix[2][0] = sin(DEG_TO_RAD(m->rotate_y_degree)) * -1.0;
	rot_y_matrix[2][2] = cos(DEG_TO_RAD(m->rotate_y_degree));
	rot_y_matrix[3][3] = 1.0;
	mult_matrices(rot_y_matrix, matrix);
}

void		mult_rot_z_matrix(double matrix[4][4], t_master *m)
{
	double	rot_z_matrix[4][4];

	ft_bzero(rot_z_matrix, sizeof(double) * 16);
	rot_z_matrix[0][0] = cos(DEG_TO_RAD(m->rotate_z_degree));
	rot_z_matrix[0][1] = sin(DEG_TO_RAD(m->rotate_z_degree)) * -1.0;
	rot_z_matrix[1][0] = sin(DEG_TO_RAD(m->rotate_z_degree));
	rot_z_matrix[1][1] = cos(DEG_TO_RAD(m->rotate_z_degree));
	rot_z_matrix[2][2] = 1.0;
	rot_z_matrix[3][3] = 1.0;
	mult_matrices(rot_z_matrix, matrix);
}

void		mult_trans_matrix(double matrix[4][4], t_master *m)
{
	double	trans_z_matrix[4][4];

	ft_bzero(trans_z_matrix, sizeof(double) * 16);
	trans_z_matrix[0][0] = 1.0;
	trans_z_matrix[1][1] = 1.0;
	trans_z_matrix[2][2] = 1.0;
	trans_z_matrix[3][3] = 1.0;
	trans_z_matrix[0][3] = m->translate_x_dist;
	trans_z_matrix[1][3] = m->translate_y_dist;
	trans_z_matrix[2][3] = m->translate_z_dist;
	mult_matrices(trans_z_matrix, matrix);
}
