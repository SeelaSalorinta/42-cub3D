#include "../includes/cub3d.h"

static t_color	validate_numbers(t_data *data, char *red, char *green, char *blue)
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

t_color	parse_colors(t_data *data, char *line)
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