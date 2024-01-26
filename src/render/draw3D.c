/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/26 20:45:48 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

uint32_t	fillbrick(int x, int y, mlx_image_t *texture)
{
	int			tex_x;
	int			tex_y;
	int			pos;
	uint32_t	color;

	tex_x = (x % texture->width);
	tex_y = (y % texture->height);
	pos = (tex_y * texture->width + tex_x) * 4;
	color = (texture->pixels[pos] << 24) | \
		(texture->pixels[pos + 1] << 16) | \
		(texture->pixels[pos + 2] << 8) | \
		(texture->pixels[pos + 3]);
	return (color);
}

uint32_t	get_color(int side, int x, int y, t_data *game)
{
	if (side == WEST)
		return (get_texture_color(x, y, game->we_img, 0x00FF00FF));
	else if (side == EAST)
		return (get_texture_color(x, y, game->ea_img, 0xFF0000FF));
	else if (side == NORTH)
		return (get_texture_color(x, y, game->no_img, 0x0000FFFF));
	else if (side == SOUTH)
		return (get_texture_color(x, y, game->so_img, 0xFFFF00FF));
	else
		return (0xFFFFFFFF);
}

void	draw_ray3d(t_data *game, t_ray *ray, int x)
{
	int	h;
	int	y;
	int	line_height;
	int	line_start;
	int	line_end;

	h = WSIZE;
	line_height = (int)(WSIZE / ray->wall_dist);
	line_start = (-line_height / 2) + (WSIZE / 2);
	if (line_start < 0)
		line_start = 0;
	line_end = line_height / 2 + WSIZE / 2;
	if (line_end >= h)
		line_end = h - 1;
	y = line_start;
	while (y < line_end)
	{
		if ((x) < WSIZE)
			mlx_put_pixel(game->img, x, y, get_color(ray->side, x, y, game));
		y++;
	}
}
