#include "../includes/cub3d.h"

static void	clean_arr(char ***arr)
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

void	free_and_exit(t_data *data)
{
	if (data->og_file)
		clean_arr(&data->og_file);
	if (data->map)
		clean_arr(&data->map);
	exit(1);
}