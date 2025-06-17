#include "../includes/cub3d.h"

//momoooooooooooooooi
char	*ft_strdup_nl(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	len = (int)ft_strlen(s1);
	i = 0;
	if (len > 0 && s1[len - 1] == '\n')
		len--;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

char	*safe_strdup(t_data *data, char *src)
{
	char	*dup;

	dup = ft_strdup(src);
	if (!dup)
		exit_with_msg(data, ERR_MALLOC);
	return (dup);
}

void	malloc_array(t_data *data, char ***array, int lines)
{
	*array = malloc(sizeof(char *) * (lines + 1));
	if (!*array)
		exit_with_msg(data, ERR_MALLOC);
	(*array)[lines] = NULL;
}

static void	set_to_default(t_data *data, char **argv)
{
	data->n_tex = NULL;
	data->s_tex = NULL;
	data->w_tex = NULL;
	data->e_tex = NULL;
	data->map = NULL;
	data->og_file = NULL;
	data->floor.red = DEFAULT;
	data->floor.green = DEFAULT;
	data->floor.blue = DEFAULT;
	data->ceiling.red = DEFAULT;
	data->ceiling.green = DEFAULT;
	data->ceiling.blue = DEFAULT;
	data->player.is_set = FALSE;
	data->file = argv[1];
    data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd(ERR_USAGE, 2);
		return (1);
	}
	set_to_default(&data, argv);
	process_file(&data);
    data.mlx = mlx_init();
    load_textures(&data);   // Load all .xpm textures
    game_loop(&data);
    return (0);
}
