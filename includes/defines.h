#ifndef DEFINES_H
# define DEFINES_H

typedef enum e_flag
{
	RED,
	GREEN,
	BLUE,
	DEFAULT = -1,
	TRUE = 1,
	FALSE = 0,
}	t_flag;

#define ERR_MALLOC	"Error: Memory allocation failed\n"
#define ERR_NO_TEX	"Error: All of the textures are not set\n"
#define ERR_EMPTY_LINE	"Error: Empty line on map\n"
#define ERR_NO_F	"Error: All of the floor colors are not set\n"
#define ERR_NO_C	"Error: All of the ceiling colors are not set\n"
#define ERR_NO_MAP	"Error: Map is not set\n"
#define ERR_MAP_LINE	"Error: Invalid map line\n"
#define ERR_IDENTIFIER	"Error: Unknown identifier\n"
#define ERR_C_DUP	"Error: Duplicate C identifier\n"
#define ERR_F_DUP	"Error: Duplicate F identifier\n"
#define ERR_COLORS	"Error: Invalid colors\n"
#define ERR_ELEMENTS	"Error: Elements in wrong order\n"
#define ERR_FILE	"Error: Invalid map file\n"
#define ERR_OPEN	"Error: Failed to open file\n"
#define ERR_USAGE	"Usage: ./cub3D [map.cub]\n"

#endif