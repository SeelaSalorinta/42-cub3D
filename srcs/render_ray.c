/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarhu <jkarhu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:22:44 by jkarhu            #+#    #+#             */
/*   Updated: 2025/08/28 14:07:27 by jkarhu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_ray(t_ray *r, t_data *d, double dx, double dy)
{
	r->ray_dir_x = dx;
	r->ray_dir_y = dy;
	r->map_x = (int)d->player.x;
	r->map_y = (int)d->player.y;
	r->delta_x = fabs(1.0 / r->ray_dir_x);
	r->delta_y = fabs(1.0 / r->ray_dir_y);
	r->step_x = calc_step(r->ray_dir_x);
	r->step_y = calc_step(r->ray_dir_y);
	r->side_x = calc_side_dist(d->player.x, r->map_x, r->delta_x,
			r->ray_dir_x < 0);
	r->side_y = calc_side_dist(d->player.y, r->map_y, r->delta_y,
			r->ray_dir_y < 0);
	r->hit = 0;
}

static void	run_dda(t_ray *r, t_data *d)
{
	while (!r->hit)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (d->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

static void	compute_strip_bounds(t_ray *r, double perp_raw)
{
	double	perp;

	perp = perp_raw;
	if (perp < 0.01)
		perp = 0.01;
	r->line_height = (int)(SCREEN_H / perp);
	r->draw_start = -r->line_height / 2 + SCREEN_H / 2;
	r->draw_end = r->line_height / 2 + SCREEN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= SCREEN_H)
		r->draw_end = SCREEN_H - 1;
}

static void	set_tex_x(t_ray *r, double wall_x)
{
	wall_x -= floor(wall_x);
	r->tex_x = (int)(wall_x * (double)(r->tex->width));
	if ((r->side == 0 && r->ray_dir_x > 0)
		|| (r->side == 1 && r->ray_dir_y < 0))
		r->tex_x = r->tex->width - r->tex_x - 1;
}

void	render_ray(t_data *data, int x, double ray_dir_x, double ray_dir_y)
{
	t_ray	r;
	double	perp;
	double	wall_x;

	init_ray(&r, data, ray_dir_x, ray_dir_y);
	run_dda(&r, data);
	perp = calc_perp_dist(data, &r);
	if (perp < 0.01)
		perp = 0.01;
	compute_strip_bounds(&r, perp);
	set_tex(data, &r);
	wall_x = calc_wall_x(data, &r, perp);
	set_tex_x(&r, wall_x);
	draw_column(data, x, &r);
}
