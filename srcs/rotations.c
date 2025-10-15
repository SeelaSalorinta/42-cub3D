/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:39:24 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 12:39:27 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	rot_speed(void)
{
	return (2 * M_PI / 16);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->plane_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed())
		- data->player.dir_y * sin(rot_speed());
	data->player.dir_y = old_dir_x * sin(rot_speed())
		+ data->player.dir_y * cos(rot_speed());
	data->plane_x = data->plane_x * cos(rot_speed())
		- data->plane_y * sin(rot_speed());
	data->plane_y = old_plane_x * sin(rot_speed())
		+ data->plane_y * cos(rot_speed());
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->plane_x;
	data->player.dir_x = data->player.dir_x * cos(-rot_speed())
		- data->player.dir_y * sin(-rot_speed());
	data->player.dir_y = old_dir_x * sin(-rot_speed())
		+ data->player.dir_y * cos(-rot_speed());
	data->plane_x = data->plane_x * cos(-rot_speed())
		- data->plane_y * sin(-rot_speed());
	data->plane_y = old_plane_x * sin(-rot_speed())
		+ data->plane_y * cos(-rot_speed());
}
