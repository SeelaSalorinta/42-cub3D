/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:36:50 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 12:36:54 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (index == 3)
			exit_with_msg(data, ERR_INVALID_COLOR);
		target[index++] = line[(*i)++];
	}
	target[index] = '\0';
	if (line[*i] != '\0' && line[*i] != ',')
		exit_with_msg(data, ERR_COLOR_FORMAT);
	if (line[*i] == ',')
		(*i)++;
}

static t_color	handle_line(t_data *data, char *line, int i, int color_num)
{
	char	red[4];
	char	green[4];
	char	blue[4];

	ft_memcpy(red, (int [4]){0, 0, 0, 0}, sizeof red);
	ft_memcpy(green, (int [4]){0, 0, 0, 0}, sizeof green);
	ft_memcpy(blue, (int [4]){0, 0, 0, 0}, sizeof blue);
	while (line[i])
	{
		if (color_num == RED)
			save_color(data, line, &i, red);
		else if (color_num == GREEN)
			save_color(data, line, &i, green);
		else if (color_num == BLUE)
		{
			save_color(data, line, &i, blue);
			if (line[i - 1] && line[i - 1] == ',')
				exit_with_msg(data, ERR_COLOR_FORMAT);
		}
		else
			exit_with_msg(data, ERR_COLOR_FORMAT);
		color_num++;
	}
	return (validate_color(data, red, green, blue));
}

t_color	parse_colors(t_data *data, char *line)
{
	int		i;
	int		color_num;

	i = 0;
	color_num = RED;
	while (line[i] && line[i] == ' ')
		i++;
	return (handle_line(data, line, i, color_num));
}
