#include "../includes/cub3d.h"

void	game_loop(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 600, "cub3D");

	mlx_hook(data->win, 2, 1L<<0, handle_keypress, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	data->screen_img.ptr = mlx_new_image(data->mlx, 800, 600);
	data->screen_img.addr = mlx_get_data_addr(
	data->screen_img.ptr,
	&data->screen_img.bpp,
	&data->screen_img.line_len,
	&data->screen_img.endian);
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_loop(data->mlx);
}
int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307) // ESC
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}

	if (keycode == 'w') // Move forward
	{
		double new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
		double new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
		if (data->map[(int)new_y][(int)data->player.x] != '1')
			data->player.y = new_y;
		if (data->map[(int)data->player.y][(int)new_x] != '1')
			data->player.x = new_x;
	}

	if (keycode == 's') // Move backward
	{
		double new_x = data->player.x - data->player.dir_x * MOVE_SPEED;
		double new_y = data->player.y - data->player.dir_y * MOVE_SPEED;
		if (data->map[(int)new_y][(int)data->player.x] != '1')
			data->player.y = new_y;
		if (data->map[(int)data->player.y][(int)new_x] != '1')
			data->player.x = new_x;
	}

	// Optional: add 'a' and 'd' for strafing
	// Optional: add left/right arrows for rotation

	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
