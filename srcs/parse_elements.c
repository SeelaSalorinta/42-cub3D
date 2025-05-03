#include "../includes/cub3d.h"

static void	assign_texture(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (data->n_tex)
			exit_with_msg(data, ERR_NO_DUP);
		data->n_tex = safe_strdup(data, line + 3);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (data->s_tex)
			exit_with_msg(data, ERR_SO_DUP);
		data->s_tex = safe_strdup(data, line + 3);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (data->w_tex)
			exit_with_msg(data, ERR_WE_DUP);
		data->w_tex = safe_strdup(data, line + 3);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (data->e_tex)
			exit_with_msg(data, ERR_EA_DUP);
		data->e_tex = safe_strdup(data, line + 3);
	}
}

static void	assign_color(t_data *data, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (data->floor.red != DEFAULT)
			exit_with_msg(data, ERR_F_DUP);
		data->floor = parse_colors(data, line + 2);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (data->ceiling.red != DEFAULT)
			exit_with_msg(data, ERR_C_DUP);
		data->ceiling = parse_colors(data, line + 2);
	}
}

void	assign_tex_or_color(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		assign_texture(data, line);
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		assign_color(data, line);
}

void	parse_elements(t_data *data)
{
	int	y;

	y = 0;
	while (data->og_file[y])
	{
		if (type_line(data->og_file[y]))
			assign_tex_or_color(data, data->og_file[y]);
		else if (!empty_line(data->og_file[y]))
		{
			if (map_line(data->og_file[y]))
			{
				parse_map(data, y);
				return ;
			}
			else
				exit_with_msg(data, ERR_IDENTIFIER);
		}
		y++;
	}
}
