#include "../includes/cub3d.h"

static int	get_height(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		line_amount;

	line_amount = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_msg(data, ERR_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		line_amount++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_amount);
}

static void	save_file_content(t_data *data)
{
	int		i;
	char	*line;
	int		fd;
	int		height;

	i = 0;
	height = get_height(data, data->file);
	malloc_array(data, &data->og_file, height);
	fd = open(data->file, O_RDONLY);
	if (fd < 0)
		exit_with_msg(data, ERR_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		data->og_file[i] = ft_strdup_nl(line);
		free(line);
		if (!data->og_file[i])
			exit_with_msg(data, ERR_MALLOC);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	validate_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 5 || file[i - 4] != '.' || file[i - 3] != 'c'
		|| file[i - 2] != 'u' || file[i - 1] != 'b')
	{
		ft_putstr_fd(ERR_FILE, 2);
		exit(1);
	}
}

static	void	check_everything_is_set(t_data *data)
{
	if (!data->n_tex || !data->s_tex || !data->e_tex || !data->w_tex)
		exit_with_msg(data, ERR_NO_TEX);
	if (data->floor.red == DEFAULT || data->floor.green == DEFAULT
		|| data->floor.blue == DEFAULT)
		exit_with_msg(data, ERR_NO_F);
	if (data->ceiling.red == DEFAULT || data->ceiling.green == DEFAULT
		|| data->ceiling.blue == DEFAULT)
		exit_with_msg(data, ERR_NO_C);
	if (!data->map)
		exit_with_msg(data, ERR_NO_MAP);
}

void	process_file(t_data *data)
{
	validate_filename(data->file);
	save_file_content(data);
	parse_elements(data);
	check_everything_is_set(data);
	print_data(data);
}
