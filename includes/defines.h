/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:42:28 by ssalorin          #+#    #+#             */
/*   Updated: 2025/10/15 14:42:25 by ssalorin         ###   ########.fr       */
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
# define ERR_MALLOC	"Error\nMemory allocation failed\n"
# define ERR_NO_TEX	"Error\nAll of the textures are not set\n"
# define ERR_EMPTY_LINE	"Error\nEmpty line on map\n"
# define ERR_NO_F	"Error\nAll of the floor colors are not set\n"
# define ERR_NO_C	"Error\nAll of the ceiling colors are not set\n"
# define ERR_NO_MAP	"Error\nMap is not set\n"
# define ERR_INVALID_CHAR	"Error\nInvalid character on map line\n"
# define ERR_IDENTIFIER	"Error\nUnknown identifier\n"
# define ERR_C_DUP	"Error\nDuplicate C identifier\n"
# define ERR_F_DUP	"Error\nDuplicate F identifier\n"
# define ERR_COLOR_FORMAT	"Error\nInvalid color. Use R,G,B format.\n"
# define ERR_FILE	"Error\nInvalid map file. Must be [map].cub file\n"
# define ERR_OPEN	"Error\nFailed to open file\n"
# define ERR_USAGE	"Error\nUsage\n./cub3D [map.cub]\n"
# define ERR_NO_DUP	"Error\nDuplicate NO identifier\n"
# define ERR_SO_DUP	"Error\nDuplicate SO identifier\n"
# define ERR_WE_DUP	"Error\nDuplicate WE identifier\n"
# define ERR_EA_DUP	"Error\nDuplicate EA identifier\n"
# define ERR_INVALID_COLOR	"Error\nColor needs to be 0-255\n"
# define ERR_MANY_PATHS	"Error\nToo many paths in texture\n"
# define ERR_MANY_PLAYERS	"Error\nToo many players spawn positions in map\n"
# define ERR_NO_PLAYER	"Error\nYou must have one player in map\n"
# define ERR_MAP_WALLS	"Error\nMap not enclosed or contains inner spaces\n"

#endif
