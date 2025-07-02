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
		exit_with_msg(data, TOO_MANY_PLAYERS);
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
	data->player.is_set = TRUE;
}

static int	not_space_or_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

static int	invalid_neighbor(t_data *data, int y, int x)
{
	if (y == (data->map_height - 1) || y <= 0)
		return (1);
	if (!data->map[y - 1][x] || (data->map[y - 1][x] != '1'
		&& !not_space_or_wall(data->map[y - 1][x])))
		return (1);
	if (!data->map[y + 1][x] || (data->map[y + 1][x] != '1'
		&& !not_space_or_wall(data->map[y + 1][x])))
		return (1);
	if (!data->map[y][x - 1] || (data->map[y][x - 1] != '1'
		&& !not_space_or_wall(data->map[y][x - 1])))
		return (1);
	if (!data->map[y][x + 1] || (data->map[y][x + 1] != '1'
		&& !not_space_or_wall(data->map[y][x + 1])))
		return (1);
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
			if (not_space_or_wall(data->map[y][x]))
			{
				if (invalid_neighbor(data, y, x))
					exit_with_msg(data, ERR_MAP_WALLS);
			}
			x++;
		}
		y++;
	}
}
