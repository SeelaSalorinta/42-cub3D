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
	double	x; //player position on map (changed it to double)
	double	y;
	double	dir_x; // (0,-1) = up, (0,1) = down, (1,0) right, (-1,0) left
	double	dir_y; //does it need to be double
	int	is_set;
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
	char	*file;
	char	**map;
	char	**og_file; //file with all lines
	char	*n_tex; //path to north texture
	char	*s_tex;
	char	*w_tex;
	char	*e_tex;
	int		map_height;//do we need?
	int		map_width;//do we need
	void	*mlx;
	void	*win;
	t_img	n_img;
	t_img	s_img;
	t_img	w_img;
	t_img	e_img;
	t_img	screen_img;
	// For raycasting
	double	camera_x;
	double	plane_x;
	double	plane_y;
	t_color	floor; //floor color
	t_color	ceiling;
	t_player	player;
}   t_data;

#endif
