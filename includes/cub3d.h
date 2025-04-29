#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structs.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>

//process_file.c
void	process_file(t_data *data);

//free_and_exit.c
void	free_and_exit(t_data *data);

//parse_elements.c
void	parse_elements(t_data *data);

//check_file_lines.c
int		empty_line(char *line);
int		is_type_line(char *line);
int		is_map_line(char *line);

#define ERR_MALLOC	"Error: Memory allocation failed\n"

#endif
