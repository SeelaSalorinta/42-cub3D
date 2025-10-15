/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:39:36 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 12:39:40 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_ns_direction(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
}

static void	update_player_pos(t_data *data, int y, int x)
{
	if (data->player.is_set == TRUE)
		exit_with_msg(data, ERR_MANY_PLAYERS);
	data->player.y = y;
	data->player.x = x;
	if (data->map[y][x] == 'N' || data->map[y][x] == 'S')
		set_ns_direction(data, data->map[y][x]);
	else if (data->map[y][x] == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (data->map[y][x] == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	data->map[y][x] = '0';
	data->player.is_set = TRUE;
}

static char	get_cell(char **map, int map_h, int y, int x)
{
	int	len;

	len = row_len(map, y);
	if (y < 0 || y >= map_h)
		return (' ');
	if (x < 0 || x >= len)
		return (' ');
	return (map[y][x]);
}

static int	invalid_neighbor(t_data *data, int y, int x)
{
	static const int	y_dir[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	static const int	x_dir[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int					i;
	char				neighbor;

	i = 0;
	while (i < 8)
	{
		neighbor = get_cell(data->map, data->map_height,
				y + y_dir[i], x + x_dir[i]);
		if (is_void(neighbor))
			return (1);
		if (!is_wall(neighbor) && !is_walkable_tile(neighbor))
			return (1);
		i++;
	}
	return (0);
}

void	validate_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				update_player_pos(data, y, x);
			if (is_walkable_tile(data->map[y][x]))
			{
				if (invalid_neighbor(data, y, x))
					exit_with_msg(data, ERR_MAP_WALLS);
			}
			x++;
		}
		y++;
	}
}
