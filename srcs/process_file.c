#include "../includes/cub3d.h"

static int	get_height(char *file)
{
	int		fd;
	char	*line;
	int		line_amount;

	line_amount = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Failed to open map file\n", 2);
		exit(1);
	}
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

static void	malloc_for_file(t_data *data, int line_amount)
{
	data->og_file = malloc(sizeof(char *) * (line_amount + 1));
	if (!data->og_file)
	{
		ft_putstr_fd(ERR_MALLOC, 2);
		exit(1);
	}
	data->og_file[line_amount] = NULL;
}

static void	save_file_content(t_data *data)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	malloc_for_file(data, get_height(data->file));
	fd = open(data->file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Failed to open map file\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->og_file[i] = ft_strdup_nl(line);
		if (!data->og_file[i])
		{
			free(line);
			while (--i >= 0)
				free(data->og_file[i]);
			free(data->og_file);
			ft_putstr_fd(ERR_MALLOC, 2);
			exit(1);
		}
		free(line);
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
	if (i < 5 || file[i - 4] != '.' || file[i - 3] != 'c' \
		|| file[i - 2] != 'u' || file[i - 1] != 'b')
	{
		ft_putstr_fd("Error: Invalid map file\n", 2);
		exit(1);
	}
}

#include <stdio.h>

void print_data(const t_data *data)
{
	if (!data)
		return; // Avoid null pointer access

	// Print texture paths
	printf("Texture Paths:\n");
	printf("North Texture: %s\n", data->n_tex ? data->n_tex : "Not Set");
	printf("South Texture: %s\n", data->s_tex ? data->s_tex : "Not Set");
	printf("West Texture: %s\n", data->w_tex ? data->w_tex : "Not Set");
	printf("East Texture: %s\n", data->e_tex ? data->e_tex : "Not Set");

	// Print floor and ceiling colors
	printf("\nFloor Color: RGB(%d, %d, %d)\n", data->floor.red, data->floor.green, data->floor.blue);
	printf("Ceiling Color: RGB(%d, %d, %d)\n", data->ceiling.red, data->ceiling.green, data->ceiling.blue);

	// Print the map
	if (data->map)
	{
		printf("\nMap:\n");
		for (int i = 0; data->map[i]; i++)
		{
			printf("%s\n", data->map[i]);
		}
	}
	else
	{
		printf("\nMap: Not Set\n");
	}
}


void	process_file(t_data *data)
{
	validate_filename(data->file);
	save_file_content(data);
	parse_elements(data);
	print_data(data);
}