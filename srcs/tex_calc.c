/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarhu <jkarhu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:09:38 by jkarhu            #+#    #+#             */
/*   Updated: 2025/08/28 14:10:56 by jkarhu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calc_side_dist(double pos, int map, double delta, int neg)
{
	if (neg)
		return ((pos - map) * delta);
	return ((map + 1.0 - pos) * delta);
}

int	calc_step(double ray_dir)
{
	if (ray_dir < 0)
		return (-1);
	return (1);
}

double	calc_perp_dist(t_data *data, t_ray *r)
{
	if (r->side == 0)
		return ((r->map_x - data->player.x + (1 - r->step_x) / 2.0)
			/ r->ray_dir_x);
	return ((r->map_y - data->player.y + (1 - r->step_y) / 2.0) / r->ray_dir_y);
}

double	calc_wall_x(t_data *data, t_ray *r, double perp)
{
	if (r->side == 0)
		return (data->player.y + perp * r->ray_dir_y);
	return (data->player.x + perp * r->ray_dir_x);
}

void	set_tex(t_data *data, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			r->tex = &data->e_img;
		else
			r->tex = &data->w_img;
	}
	else
	{
		if (r->ray_dir_y > 0)
			r->tex = &data->s_img;
		else
			r->tex = &data->n_img;
	}
}
