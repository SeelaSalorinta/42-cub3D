#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structs.h"
# include "defines.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>

//main.c
char	*safe_strdup(t_data *data, char *src);
char	*ft_strdup_nl(const char *s1);

//process_file.c
void	process_file(t_data *data);

//free_and_exit.c
void	free_and_exit(t_data *data);
void	exit_with_msg(t_data *data, char *msg);

//parse_elements.c
void	parse_elements(t_data *data);

//check_file_lines.c
int		empty_line(char *line);
int		is_type_line(char *line);
int		is_map_line(char *line);

//atoi_with_error.c
int		atoi_with_error(char *str, int *error);

//atoi_positive.c
int		atoi_positive(char *str, int *error);

#endif
