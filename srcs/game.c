/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:35:28 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 12:35:45 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	game_loop(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 800, 600, "cub3D");
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	data->screen_img.ptr = mlx_new_image(data->mlx, 800, 600);
	data->screen_img.addr = mlx_get_data_addr(
			data->screen_img.ptr, &data->screen_img.bpp,
			&data->screen_img.line_len, &data->screen_img.endian);
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_loop(data->mlx);
}

static void	check_player_pos(t_data *data, double new_y, double new_x)
{
	if (data->map[(int)new_y][(int)new_x] != '1')
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

static void	update_player_position(int keycode, t_data *data)
{
	double	new_x;
	double	new_y;

	if (keycode == 'w')
	{
		new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
		new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
	}
	else if (keycode == 's')
	{
		new_x = data->player.x - data->player.dir_x * MOVE_SPEED;
		new_y = data->player.y - data->player.dir_y * MOVE_SPEED;
	}
	else if (keycode == 'a')
	{
		new_x = data->player.x - data->plane_x * MOVE_SPEED;
		new_y = data->player.y - data->plane_y * MOVE_SPEED;
	}
	else
	{
		new_x = data->player.x + data->plane_x * MOVE_SPEED;
		new_y = data->player.y + data->plane_y * MOVE_SPEED;
	}
	check_player_pos(data, new_y, new_x);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 'w' || keycode == 's'
		|| keycode == 'a' || keycode == 'd')
		update_player_position(keycode, data);
	if (keycode == 65361)
		rotate_left(data);
	if (keycode == 65363)
		rotate_right(data);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
