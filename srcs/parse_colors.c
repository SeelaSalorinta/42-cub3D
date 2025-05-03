#include "../includes/cub3d.h"

static t_color	validate_color(t_data *data, char *red, char *green, char *blue)
{
	t_color	color;
	int		error;

	error = 0;
	color.red = atoi_positive(red, &error);
	if (error || color.red < 0 || color.red > 255)
		exit_with_msg(data, ERR_INVALID_COLOR);
	color.green = atoi_positive(green, &error);
	if (error || color.green < 0 || color.green > 255)
		exit_with_msg(data, ERR_INVALID_COLOR);
	color.blue = atoi_positive(blue, &error);
	if (error || color.blue < 0 || color.blue > 255)
		exit_with_msg(data, ERR_INVALID_COLOR);
	return (color);
}

static void	save_color(t_data *data, char *line, int *i, char *target)
{
	int	index;

	index = 0;
	while (line[*i] && (line[*i] >= '0' && line[*i] <= '9'))
	{
		if (index >= 3)
			exit_with_msg(data, ERR_COLORS);
		target[index++] = line[(*i)++];
	}
	target[index] = '\0';
	if (line[*i] != '\0' && line[*i] != ',')
		exit_with_msg(data, ERR_COLORS);
	if (line[*i] == ',')
		(*i)++;
}

t_color	parse_colors(t_data *data, char *line)
{
	char	red[4];
	char	green[4];
	char	blue[4];
	int		i;
	int		color_num;

	i = 0;
	color_num = RED;
	while (line[i])
	{
		if (color_num == RED)
			save_color(data, line, &i, red);
		else if (color_num == GREEN)
			save_color(data, line, &i, green);
		else if (color_num == BLUE)
			save_color(data, line, &i, blue);
		else
			exit_with_msg(data, ERR_COLORS);
		color_num++;
	}
	return (validate_color(data, red, green, blue));
}
