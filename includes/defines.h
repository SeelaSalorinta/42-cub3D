/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:42:28 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 13:53:06 by jkarhu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define SCREEN_W 800
# define SCREEN_H 600
# define MOVE_SPEED 0.5
# define ERR_MALLOC	"Error\n Memory allocation failed\n"
# define ERR_NO_TEX	"Error\n All of the textures are not set\n"
# define ERR_EMPTY_LINE	"Error\n Empty line on map\n"
# define ERR_NO_F	"Error\n All of the floor colors are not set\n"
# define ERR_NO_C	"Error\n All of the ceiling colors are not set\n"
# define ERR_NO_MAP	"Error\n Map is not set\n"
# define ERR_INVALID_CHAR	"Error\n Invalid character on map line\n"
# define ERR_IDENTIFIER	"Error\n Unknown identifier\n"
# define ERR_C_DUP	"Error\n Duplicate C identifier\n"
# define ERR_F_DUP	"Error\n Duplicate F identifier\n"
# define ERR_COLOR_FORMAT	"Error\n Invalid color. Use R,G,B format.\n"
# define ERR_ELEMENTS	"Error\n Elements in wrong order\n"
# define ERR_FILE	"Error\n Invalid map file. Must be [map].cub file\n"
# define ERR_OPEN	"Error\n Failed to open file\n"
# define ERR_USAGE	"Usage\n ./cub3D [map.cub]\n"
# define ERR_NO_DUP	"Error\n Duplicate NO identifier\n"
# define ERR_SO_DUP	"Error\n Duplicate SO identifier\n"
# define ERR_WE_DUP	"Error\n Duplicate WE identifier\n"
# define ERR_EA_DUP	"Error\n Duplicate EA identifier\n"
# define ERR_INVALID_COLOR	"Error\n Color needs to be 0-255\n"
# define ERR_MANY_PATHS	"Error\n Too many paths in texture\n"
# define TOO_MANY_PLAYERS	"Error\n Too many players spawn positions in map\n"
# define ERR_NO_PLAYER	"Error\n You must have one player in map\n"
# define ERR_MAP_WALLS	"Error\n Map not enclosed by walls\n"

#endif
