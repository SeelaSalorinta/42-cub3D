#include "../includes/cub3d.h"

static void	update_player_pos(t_data *data, int y, int x)
{
	if (data->player.is_set == TRUE)
		exit_with_msg(data, TOO_MANY_PLAYERS);
	data->player.y = y;
	data->player.x = x;
	if (data->map[y][x] == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	if (data->map[y][x] == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	if (data->map[y][x] == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	if (data->map[y][x] == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	data->player.is_set = TRUE;
}

static void	only_one_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				update_player_pos(data, y, x);
			}
			x++;
		}
		y++;
	}

}

void	validate_map(t_data *data)
{
	only_one_player(data);
}
