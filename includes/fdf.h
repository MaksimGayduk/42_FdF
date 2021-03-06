/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:01:01 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/16 11:22:03 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "matrix.h"
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "reader.h"
# include "vector.h"
# include "ft_x11.h"

# define SCREEN_WIDTH	1024
# define SCREEN_HEIGHT	768
# define WORK_WIDTH		SCREEN_WIDTH - N_WIDTH
# define N_COLOR		0x999999
# define N_WIDTH		100
# define NX_P			20
# define NY_P			20
# define R_STEP 		DEG(10)

# define DEG(x)			(x * 3.14) / 180
# define RAD(x)			(x * 180) / 3.14

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_node
{
	int			x;
	int			y;
	int			z;
	long long	color;
}				t_node;

typedef struct	s_clip
{
	t_matrix	vert;
	t_matrix	clip_mat;
	float		top;
	float		bottom;
	float		left;
	float		right;
}				t_clip;

typedef struct	s_camera
{
	t_matrix	vert;
	t_matrix	look;
	t_vector	eye;
	t_vector	target;
	t_vector	up_dir;

	float		xy_step;
	float		z_step;
	t_vector	forward;
	t_vector	right;
	t_vector	up;

	float		near;
	float		far;
	float		fov_h;
	float		fov_v;
}				t_camera;

typedef struct	s_object
{
	t_matrix	vert;
	t_matrix	morph;
	t_vector	amp;
	char		*is_pushed;
	long long	*colors;
	size_t		*p_in_row;
}				t_object;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_object	obj;
	t_object	world;
	t_object	view_port;
	t_camera	camera;
	t_clip		clip;
}				t_env;

t_vector		get_mean(t_matrix m);
t_vector		get_center(t_matrix m);
t_vector		get_amp(t_matrix m);
int				restore_view(t_env *env);
t_object		parse_content(t_list *head);
void			draw_figure(t_env *env);
void			print_notations(t_env *env);
int				draw_line(t_env *env, size_t start, size_t end);

t_matrix		translate(t_matrix a, float x, float y, float z);
t_matrix		scale(t_matrix a, float x, float y, float z);
t_matrix		rotate_about_x_center(t_matrix a, float x);
t_matrix		rotate_about_y_center(t_matrix a, float y);
t_matrix		rotate_about_z_center(t_matrix a, float z);
t_matrix		rotate_about_x(t_matrix a, float x);
t_matrix		rotate_about_y(t_matrix a, float y);
t_matrix		rotate_about_z(t_matrix a, float z);

void			init_camera(t_env *env);
int				cam_trans(int keycode, t_env *env);
int				cam_rotate(int keycode, t_env *env);

void			init_clip(t_env *env);
void			normalize(t_env *env);

int				colors(int keycode, t_env *env);

int				deformations(int keycode, t_env *env);

#endif
