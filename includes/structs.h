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
	t_color	floor; //floor color
	t_color	ceiling;
}	t_data;

#define ERR_MALLOC	"Error: Memory allocation failed\n"
#define ERR_TEXT	"Error: All of the textures are not set\n"
#define ERR_EMPTY_LINE	"Error: Empty line on map\n"
#define ERR_F_COLORS	"Error: All of the floor colors are not set\n"
#define ERR_C_COLORS	"Error: All of the ceiling colors are not set\n"
#define ERR_IDENTIFIER	"Error: Unknown identifier\n"
#define ERR_C_DUP	"Error: Duplicate C identifier\n"
#define ERR_F_DUP	"Error: Duplicate F identifier\n"
#define ERR_COLORS	"Error: Invalid colors\n"

#endif
