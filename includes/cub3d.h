/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:41:27 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 14:03:58 by jkarhu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structs.h"
# include "defines.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

//atoi_positive.c
int		atoi_positive(char *str, int *error);

//check_file_lines.c
int		empty_line(char *line);
int		type_line(char *line);
int		map_line(char *line);
int		row_len(char **map, int y);

//free_and_exit.c
void	free_and_exit(t_data *data);
void	exit_with_msg(t_data *data, char *msg);
void	clean_arr(char ***arr);

//game.c
void	game_loop(t_data *data);
int		close_window(t_data *data);
int		handle_keypress(int keycode, t_data *data);

//load_textures.c
void	load_textures(t_data *data);

//main.c
char	*safe_strdup(t_data *data, char *src);
char	*ft_strdup_nl(const char *s1);
void	calloc_array(t_data *data, char ***array, int lines);

//parse_colors.c
t_color	parse_colors(t_data *data, char *line);

//parse_elements.c
void	parse_elements(t_data *data);

//parse_map.c
void	parse_map(t_data *data, int y);

//process_file.c
void	process_file(t_data *data);

//raycast.c
int		render_frame(t_data *data);
void	draw_column(t_data *data, int x, t_ray *r);

//render_ray.c
void	render_ray(t_data *data, int x, double ray_dir_x, double ray_dir_y);

//rotations.c
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);

//tex_calc.c
double	calc_side_dist(double pos, int map, double delta, int neg);
int		calc_step(double ray_dir);
double	calc_wall_x(t_data *data, t_ray *r, double perp);
void	set_tex(t_data *data, t_ray *r);
double	calc_perp_dist(t_data *data, t_ray *r);

//tile_checks.c
int		is_walkable_tile(char c);
int		is_wall(char c);
int		is_void(char c);

//validate_map.c
void	validate_map(t_data *data);

#endif
