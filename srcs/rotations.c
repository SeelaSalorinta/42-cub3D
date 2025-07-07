#include "../includes/cub3d.h"

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->plane_x;
	data->player.dir_x = data->player.dir_x * cos(ROT_SPEED)
		- data->player.dir_y * sin(ROT_SPEED);
	data->player.dir_y = old_dir_x * sin(ROT_SPEED)
		+ data->player.dir_y * cos(ROT_SPEED);
	data->plane_x = data->plane_x * cos(ROT_SPEED)
		- data->plane_y * sin(ROT_SPEED);
	data->plane_y = old_plane_x * sin(ROT_SPEED)
		+ data->plane_y * cos(ROT_SPEED);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->plane_x;
	data->player.dir_x = data->player.dir_x * cos(-ROT_SPEED)
		- data->player.dir_y * sin(-ROT_SPEED);
	data->player.dir_y = old_dir_x * sin(-ROT_SPEED)
		+ data->player.dir_y * cos(-ROT_SPEED);
	data->plane_x = data->plane_x * cos(-ROT_SPEED)
		- data->plane_y * sin(-ROT_SPEED);
	data->plane_y = old_plane_x * sin(-ROT_SPEED)
		+ data->plane_y * cos(-ROT_SPEED);
}
