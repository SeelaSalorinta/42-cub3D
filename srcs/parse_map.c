#include "../includes/cub3d.h"

static void	count_map_lines(t_data *data, int y)
{
	int	lines;

	lines = 0;
	while (data->og_file[y])
	{
		y++;
		lines++;
	}
	data->map_height = lines;
}

static void	form_map(t_data *data, int y)
{
	int	i;

	i = 0;
	while (data->og_file[y])
	{
		if (empty_line(data->og_file[y]))
			exit_with_msg(data, ERR_EMPTY_LINE);
		if (!map_line(data->og_file[y]))
			exit_with_msg(data, ERR_INVALID_CHAR);
		data->map[i++] = safe_strdup(data, data->og_file[y++]);
	}
}

void	parse_map(t_data *data, int y)
{
	count_map_lines(data, y);
	malloc_array(data, &data->map, data->map_height);
	form_map(data, y);
	validate_map(data);
}
