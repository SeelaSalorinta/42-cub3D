/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:37:48 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 14:11:20 by jkarhu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_W || y >= SCREEN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_column(t_data *data, int x, t_ray *r)
{
	int		y;
	long	d;
	int		tex_y;
	char	*pix;
	int		color;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		d = y * 256 - SCREEN_H * 128 + r->line_height * 128;
		tex_y = ((d * r->tex->height) / r->line_height) / 256;
		pix = r->tex->addr + (tex_y * r->tex->line_len
				+ r->tex_x * (r->tex->bpp / 8));
		color = *(unsigned int *)pix;
		put_pixel(&data->screen_img, x, y, color);
		y++;
	}
}

static void	render_ceiling(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_H / 2)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			put_pixel(&data->screen_img, x, y,
				(data->ceiling.red << 16)
				| (data->ceiling.green << 8)
				| data->ceiling.blue);
			x++;
		}
		y++;
	}
}

static void	render_floor(t_data *data)
{
	int	y;
	int	x;

	y = SCREEN_H / 2;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			put_pixel(&data->screen_img, x, y,
				(data->floor.red << 16)
				| (data->floor.green << 8)
				| data->floor.blue);
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
	while (x < SCREEN_W)
	{
		camera_x = 2 * x / (double)SCREEN_W - 1;
		ray_dir_x = data->player.dir_x + data->plane_x * camera_x;
		ray_dir_y = data->player.dir_y + data->plane_y * camera_x;
		render_ray(data, x, ray_dir_x, ray_dir_y);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen_img.ptr, 0, 0);
	return (0);
}
