#include "../includes/cub3d.h"

int	is_type_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 ||
			ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 ||
			ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' \
			&& line[i] != '\t' && line[i] != '\r' \
			&& line[i] != '\v' && line[i] != '\f')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' ||
			  line[i] == 'S' || line[i] == 'E' || line[i] == 'W' ||
			  line[i] == ' ' || line[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}