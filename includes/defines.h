#ifndef DEFINES_H
# define DEFINES_H

typedef enum e_flag
{
	FALSE,
	TRUE,
	RED,
	GREEN,
	BLUE,
	DEFAULT = -2,
}	t_flag;

# define ERR_MALLOC	"Error: Memory allocation failed\n"
# define ERR_NO_TEX	"Error: All of the textures are not set\n"
# define ERR_EMPTY_LINE	"Error: Empty line on map\n"
# define ERR_NO_F	"Error: All of the floor colors are not set\n"
# define ERR_NO_C	"Error: All of the ceiling colors are not set\n"
# define ERR_NO_MAP	"Error: Map is not set\n"
# define ERR_INVALID_CHAR	"Error: Invalid character on map line\n"
# define ERR_IDENTIFIER	"Error: Unknown identifier\n"
# define ERR_C_DUP	"Error: Duplicate C identifier\n"
# define ERR_F_DUP	"Error: Duplicate F identifier\n"
# define ERR_COLORS	"Error: Invalid colors\n"
# define ERR_ELEMENTS	"Error: Elements in wrong order\n"
# define ERR_FILE	"Error: Invalid map file\n"
# define ERR_OPEN	"Error: Failed to open file\n"
# define ERR_USAGE	"Usage: ./cub3D [map.cub]\n"
# define ERR_NO_DUP	"Error: Duplicate NO identifier\n"
# define ERR_SO_DUP	"Error: Duplicate SO identifier\n"
# define ERR_WE_DUP	"Error: Duplicate WE identifier\n"
# define ERR_EA_DUP	"Error: Duplicate WE identifier\n"
# define ERR_INVALID_COLOR	"Error: Color needs to be 0-255\n"
# define ERR_MANY_PATHS	"Error: Too many paths in texture\n"
# define TOO_MANY_PLAYERS	"Error: Too many players spawn positions in map\n"
# define ERR_MAP_WALLS	"Error: Map not enclosed by walls\n"

#endif