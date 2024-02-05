/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/05 14:56:18 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>
#define texWidth 32
#define texHeight 32

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

void draw_ray3d(t_data *game, t_ray *ray, int x)
{
    int h, line_height, draw_start, draw_end, tex_x, y;
    double wallX;
    double step;
    double tex_pos;
    uint32_t color;

    h = WSIZE;
    line_height = (int)(h / ray->wall_dist);
    draw_start = (-line_height / 2) + (h / 2);
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + (h / 2);
    if (draw_end >= h)
        draw_end = h - 1;

    if (ray->side == WEST || ray->side == EAST)
        wallX = game->pl.y / game->map.sq_ysize + ray->wall_dist * ray->diry;
    else 
        wallX = game->pl.x / game->map.sq_xsize + ray->wall_dist * ray->dirx;
    wallX -= floor(wallX);

    tex_x = (int)(wallX * (double)texWidth);
    if(ray->side == 0 && ray->dirx > 0)
		tex_x = texWidth - tex_x - 1;
    if(ray->side == 1 && ray->diry < 0)
		tex_x = texWidth - tex_x - 1;

    step = 1.0 * texHeight / line_height;
    tex_pos = (draw_start - h / 2 + line_height / 2) * step;
    for (y = draw_start; y < draw_end; y++) {
        int tex_y = (int)tex_pos % texHeight;
        tex_pos += step;
        color = get_color(ray->side, tex_x, tex_y, game);
        mlx_put_pixel(game->img, x, y, color);
    }
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
