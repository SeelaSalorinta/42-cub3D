#include "../includes/cub3d.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 800 || y >= 600)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static double	calc_side_dist(double pos, int map, double delta, int neg)
{
	if (neg)
		return ((pos - map) * delta);
	return ((map + 1.0 - pos) * delta);
}

static int	calc_step(double ray_dir)
{
	if (ray_dir < 0)
		return (-1);
	return (1);
}

static double	calc_perp_dist(t_data *data, t_ray *r)
{
	if (r->side == 0)
		return ((r->map_x - data->player.x + (1 - r->step_x) / 2.0) / r->ray_dir_x);
	return ((r->map_y - data->player.y + (1 - r->step_y) / 2.0) / r->ray_dir_y);
}

static double	calc_wall_x(t_data *data, t_ray *r, double perp)
{
	if (r->side == 0)
		return (data->player.y + perp * r->ray_dir_y);
	return (data->player.x + perp * r->ray_dir_x);
}

static void	draw_column(t_data *data, int x, t_ray *r)
{
	int		y;
	int		d;
	int		tex_y;
	char	*pix;
	int		color;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		d = y * 256 - 600 * 128 + r->line_height * 128;
		tex_y = ((d * r->tex->height) / r->line_height) / 256;
		pix = r->tex->addr + (tex_y * r->tex->line_len
			+ r->tex_x * (r->tex->bpp / 8));
		color = *(unsigned int *)pix;
		put_pixel(&data->screen_img, x, y, color);
		y++;
	}
}

static void	set_tex(t_data *data, t_ray *r)
{
	if (r->side == 0 && r->ray_dir_x > 0)
		r->tex = &data->w_img;
	else if (r->side == 0 && r->ray_dir_x < 0)
		r->tex = &data->e_img;
	else if (r->side == 1 && r->ray_dir_y > 0)
		r->tex = &data->n_img;
	else
		r->tex = &data->s_img;
}

static void	render_ceiling(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < 600 / 2)
	{
		x = 0;
		while (x < 800)
		{
			put_pixel(&data->screen_img, x, y, 
					(data->ceiling.red << 16) | 
					(data->ceiling.green << 8) | 
					data->ceiling.blue);
			x++;
		}
		y++;
	}
}

static void	render_floor(t_data *data)
{
	int	y;
	int	x;

	y = 600 / 2;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			put_pixel(&data->screen_img, x, y, 
					(data->floor.red << 16) | 
					(data->floor.green << 8) | 
					data->floor.blue);
			x++;
		}
		y++;
	}
}

int	render_frame(t_data *data)
{
	int			x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;

	render_ceiling(data);
	render_floor(data);
	x = 0;
	while (x < 800)
	{
		camera_x = 2 * x / 800.0 - 1;
		ray_dir_x = data->player.dir_x + data->plane_x * camera_x;
		ray_dir_y = data->player.dir_y + data->plane_y * camera_x;
		render_ray(data, x, ray_dir_x, ray_dir_y); // match function signature
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen_img.ptr, 0, 0);
	return (0);
}

void	render_ray(t_data *data, int x, double ray_dir_x, double ray_dir_y)
{
	t_ray	r;
	double	perp;
	double	wall_x;

	r.ray_dir_x = ray_dir_x;
	r.ray_dir_y = ray_dir_y;
	r.map_x = (int)data->player.x;
	r.map_y = (int)data->player.y;
	r.delta_x = fabs(1 / r.ray_dir_x);
	r.delta_y = fabs(1 / r.ray_dir_y);
	r.step_x = calc_step(r.ray_dir_x);
	r.step_y = calc_step(r.ray_dir_y);
	r.side_x = calc_side_dist(data->player.x, r.map_x, r.delta_x, r.ray_dir_x < 0);
	r.side_y = calc_side_dist(data->player.y, r.map_y, r.delta_y, r.ray_dir_y < 0);
	r.hit = 0;
	while (!r.hit)
	{
		if (r.side_x < r.side_y)
		{
			r.side_x += r.delta_x;
			r.map_x += r.step_x;
			r.side = 0;
		}
		else
		{
			r.side_y += r.delta_y;
			r.map_y += r.step_y;
			r.side = 1;
		}
		if (data->map[r.map_y][r.map_x] == '1')
			r.hit = 1;
	}
	perp = calc_perp_dist(data, &r);
	r.line_height = (int)(600 / perp);
	r.draw_start = -r.line_height / 2 + 600 / 2;
	r.draw_end = r.line_height / 2 + 600 / 2;
	if (r.draw_start < 0)
		r.draw_start = 0;
	if (r.draw_end >= 600)
		r.draw_end = 599;
	set_tex(data, &r);
	wall_x = calc_wall_x(data, &r, perp);
	wall_x -= floor(wall_x);
	r.tex_x = (int)(wall_x * (double)(r.tex->width));
	if ((r.side == 0 && r.ray_dir_x > 0)
		|| (r.side == 1 && r.ray_dir_y < 0))
		r.tex_x = r.tex->width - r.tex_x - 1;
	draw_column(data, x, &r);
}
