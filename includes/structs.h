#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_data
{
	char	*file;
	char	**map;
	char	**og_file; //file with all lines
	char	*n_tex; //path to north texture
	char	*s_tex;
	char	*w_tex;
	char	*e_tex;
	int		map_height;//do we need?
	int		map_width;//do we need?
	t_color	floor; //floor color
	t_color	ceiling;
}	t_data;

#endif
