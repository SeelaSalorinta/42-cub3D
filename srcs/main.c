#include "../cub3d.h"

static void	validate_filename(char *file)
{
	int	i;

	i = (int)ft_strlen(file);
	if (i < 4)
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		exit(1);
	}
	if (file[i - 4] != '.' || file[i - 3] != 'c'
		|| file[i - 2] != 'u' || file[i - 1] != 'b')
	{
		ft_putstr_fd("File is not a .cub file\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3D [map.cub]\n", 2);
		return (1);
	}
	validate_filename(argv[1]);
	parse_map(argv[1]);
}