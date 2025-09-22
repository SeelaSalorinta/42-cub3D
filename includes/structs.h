/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:42:44 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 12:42:47 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	int		is_set;
}	t_player;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	t_img	*tex;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray;

typedef struct s_data
{
	char		*file;
	char		**map;
	char		**og_file;
	char		*n_tex;
	char		*s_tex;
	char		*w_tex;
	char		*e_tex;
	int			map_height;
	void		*mlx;
	void		*win;
	t_img		n_img;
	t_img		s_img;
	t_img		w_img;
	t_img		e_img;
	t_img		screen_img;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
}	t_data;

#endif
