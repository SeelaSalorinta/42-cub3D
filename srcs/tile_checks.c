/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:24:06 by ssalorin          #+#    #+#             */
/*   Updated: 2025/10/15 15:24:36 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_walkable_tile(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

int	is_void(char c)
{
	if (c == ' ' || c == '\0')
		return (1);
	else
		return (0);
}
