#include "../includes/cub3d.h"

static void	assign_texture(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (data->n_tex)
			exit_with_msg(data, "Duplicate NO identifier\n");
		data->n_tex = safe_strdup(data, line + 3);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (data->s_tex)
			exit_with_msg(data, "Duplicate SO identifier\n");
		data->s_tex = safe_strdup(data, line + 3);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (data->w_tex)
			exit_with_msg(data, "Duplicate WE identifier\n");
		data->w_tex = safe_strdup(data, line + 3);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (data->e_tex)
			exit_with_msg(data, "Duplicate EA identifier\n");
		data->e_tex = safe_strdup(data, line + 3);
	}
}

static t_color	validate_numbers(t_data *data, char *red, char *green, char *blue)
{
	t_color	color;
	int		error;

	error = 0;
	color.red = atoi_positive(red, &error);
	if (error || color.red < 0 || color.red > 255)
		exit_with_msg(data, "Error: Color needs to be 0-255\n");
	color.green = atoi_positive(green, &error);
	if (error || color.green < 0 || color.green > 255)
		exit_with_msg(data, "Error: Color needs to be 0-255\n");
	color.blue = atoi_positive(blue, &error);
	if (error || color.blue < 0 || color.blue > 255)
		exit_with_msg(data, "Error: Color needs to be 0-255\n");
	return (color);
}

static t_color	parse_color(t_data *data, char *line)
{
	char	red[4];
	char	green[4];
	char	blue[4];
	int		color_num;
	int		i;
	int		index;
	char	*target;

	if (!line)
		exit_with_msg(data, "Error: Invalid color line\n");
	i = 0;
	index = 0;
	color_num = RED;
	while (line[i])
	{
		if (color_num == RED)
			target = red;
		if (color_num == GREEN)
			target = green;
		if (color_num == BLUE)
			target = blue;
		if (color_num > BLUE)
			exit_with_msg(data, ERR_COLORS);
		while (line[i] && (line[i] >= '0' && line[i] <= '9'))
			target[index++] = line[i++];
		target[index] = '\0';
		if (line[i] != '\0' && line[i] != ',')
			exit_with_msg(data, ERR_COLORS);
		else if (line[i] != '\0' && line[i] == ',')
			i++;
		else
			break ;
		index = 0;
		color_num++;
	}
	return (validate_numbers(data, red, green, blue));
}

static void	assign_color(t_data *data, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (data->floor.red != DEFAULT)
			exit_with_msg(data, ERR_F_DUP);
		data->floor = parse_color(data, line + 2);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (data->ceiling.red != DEFAULT)
			exit_with_msg(data, ERR_C_DUP);
		data->ceiling = parse_color(data, line + 2);
	}
}

void	assign_tex_or_color(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		assign_texture(data, line);
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		assign_color(data, line);
	else
		exit_with_msg(data, ERR_IDENTIFIER);
}

void	parse_elements(t_data *data)
{
	int	y;
	int	map_started;

	y = 0;
	map_started = FALSE;
	while (data->og_file[y])
	{
		if (is_type_line(data->og_file[y]))
			assign_tex_or_color(data, data->og_file[y]);
		else if (!empty_line(data->og_file[y]))
		{
			if (is_map_line(data->og_file[y]))
			{
				map_started = TRUE;
				//parse map && add mapline
			}
			else
				free_and_exit(data);
		}
		if (empty_line(data->og_file[y]) && map_started == TRUE)
			exit_with_msg(data, ERR_EMPTY_LINE);
		y++;
	}
}