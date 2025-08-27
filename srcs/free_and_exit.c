#include "../includes/cub3d.h"

void	clean_arr(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

static void	clean_str(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

void	free_and_exit(t_data *data)
{
	if (data->og_file)
		clean_arr(&data->og_file);
	if (data->map)
		clean_arr(&data->map);
	if (data->n_tex)
		clean_str(&data->n_tex);
	if (data->s_tex)
		clean_str(&data->s_tex);
	if (data->w_tex)
		clean_str(&data->w_tex);
	if (data->e_tex)
		clean_str(&data->e_tex);
	exit(1);
}

void	exit_with_msg(t_data *data, char *msg)
{
	ft_putstr_fd(msg, 2);
	free_and_exit(data);
}
