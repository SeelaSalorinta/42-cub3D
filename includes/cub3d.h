#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structs.h"
# include "defines.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>

//atoi_positive.c
int		atoi_positive(char *str, int *error);

//atoi_with_error.c
int		atoi_with_error(char *str, int *error);

//check_file_lines.c
int		empty_line(char *line);
int		type_line(char *line);
int		map_line(char *line);

//free_and_exit.c
void	free_and_exit(t_data *data);
void	exit_with_msg(t_data *data, char *msg);

//main.c
char	*safe_strdup(t_data *data, char *src);
char	*ft_strdup_nl(const char *s1);
void	malloc_array(t_data *data, char ***array, int lines);

//parse_colors.c
t_color	parse_colors(t_data *data, char *line);

//parse_elements.c
void	parse_elements(t_data *data);

//parse_map.c
void	parse_map(t_data *data, int y);

//process_file.c
void	process_file(t_data *data);

//validate_map.c
void	validate_map(t_data *data);

#endif
