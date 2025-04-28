#include "../cub3d.h"

void	parse_map(char *file)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Failed to open map file\n", 2);
		exit(1);
	}
}