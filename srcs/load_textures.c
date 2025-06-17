#include "../includes/cub3d.h"

static void	load_one_texture(t_data *data, char *path, t_img *img)
{
	int w, h;

	img->ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (!img->ptr)
		exit_with_msg(data, "Error loading texture");

	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, &img->endian);
	img->width = w;
	img->height = h;
}

void	load_textures(t_data *data)
{
	load_one_texture(data, data->n_tex, &data->n_img);
	load_one_texture(data, data->s_tex, &data->s_img);
	load_one_texture(data, data->w_tex, &data->w_img);
	load_one_texture(data, data->e_tex, &data->e_img);
}
