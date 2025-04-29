#include "../includes/cub3d.h"

static void	set_to_default(t_data *data, char **argv)
{
	data->n_tex = NULL;
	data->s_tex = NULL;
	data->w_tex = NULL;
	data->e_tex = NULL;
	data->map = NULL;
	data->og_file = NULL;
	data->floor.red = -1;
	data->floor.green = -1;
	data->floor.blue = -1;
	data->ceiling.red = -1;
	data->ceiling.green = -1;
	data->ceiling.blue = -1;
	data->file = argv[1];
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3D [map.cub]\n", 2);
		return (1);
	}
	set_to_default(&data, argv);
	process_file(&data);
}