#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	load_and_resize_texture(t_data *game, char **side_path, mlx_image_t **s)
{
	mlx_texture_t	*texture;

	if (*side_path)
	{
		texture = mlx_load_png(*side_path);
		if (!texture)
			*s = NULL;
		else
		{
			*s = mlx_texture_to_image(game->mlx, texture);
			if (!*s)
				exit(1);
			mlx_delete_texture(texture);
		}
	}
	else
		*s = NULL;
}

void	load_and_resize_all_textures(t_data *game)
{
	load_and_resize_texture(game, &game->no, &game->no_img);
	load_and_resize_texture(game, &game->so, &game->so_img);
	load_and_resize_texture(game, &game->we, &game->we_img);
	load_and_resize_texture(game, &game->ea, &game->ea_img);
}

uint32_t	get_texture_color(int tex_x, int tex_y, mlx_image_t *texture)
{
	int pos;

	if (!texture)
		return (0xFFFFFFFF);
	if (tex_x < 0 || tex_y < 0 || tex_x >= (int)texture->width || tex_y >= (int)texture->height)
		return (0xFFFFFFFF);
	pos = (tex_y * texture->width + tex_x) * 4;
	return (texture->pixels[pos] << 24) | 
			(texture->pixels[pos + 1] << 16) | 
			(texture->pixels[pos + 2] << 8) | 
		(texture->pixels[pos + 3]);
}

uint32_t	get_color(int side, int tex_x, int tex_y, t_data *game)
{
	if (side == WEST)
		return (get_texture_color(tex_x, tex_y, game->we_img));
	else if (side == EAST)
		return (get_texture_color(tex_x, tex_y, game->ea_img));
	else if (side == NORTH)
		return (get_texture_color(tex_x, tex_y, game->no_img));
	else if (side == SOUTH)
		return (get_texture_color(tex_x, tex_y, game->so_img));
	else
		return (0xFFFFFFFF);
}

void	calculate_texture_info(t_data *game, t_ray *ray, t_tex *tex, int line_start)
{
	int	h;
	int	line_height;

	h = WSIZE;
	line_height = (int)(WSIZE / ray->wall_dist);
	if (ray->side == WEST || ray->side == EAST)
        tex->wall_x = game->pl.y + ray->wall_dist * ray->diry;
    else 
        tex->wall_x = game->pl.x + ray->wall_dist * ray->dirx;
    tex->wall_x -= floor(tex->wall_x);

    tex->tex_x = (int)(tex->wall_x * (double)texWidth);
    if(ray->side == EAST)
		tex->tex_x = texWidth - tex->tex_x - 1;
    if(ray->side == NORTH)
		tex->tex_x = texWidth - tex->tex_x - 1;

    tex->step = 1.0 * texHeight / line_height;
    tex->tex_pos = (line_start - h / 2 + line_height / 2) * tex->step;
}