/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 15:04:41 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void		draw_ray_mini(t_data *game, double wallDist, double dirx, double diry);
uint32_t	get_color(int side, int tex_x, int tex_y, t_data *game);
void		calculate_texture_info(t_data *game, t_ray *ray, t_tex *tex, int line_start);

void	draw_fl_ceil(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WSIZE)
	{
		y = 0;
		while (y < WSIZE)
		{
			if (y < WSIZE / 2)
				mlx_put_pixel(game->img3d, x, y, 0x0000FFFF);
			else
				mlx_put_pixel(game->img3d, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}

void	calculate_height(t_ray *ray, int *line_start, int *line_end)
{
	int	h;
	int	line_height;

	h = WSIZE;
	line_height = (int)(WSIZE / ray->wall_dist);
	*line_start = (-line_height / 2) + (WSIZE / 2);
	if (*line_start < 0)
		*line_start = 0;
	*line_end = line_height / 2 + WSIZE / 2;
	if (*line_end >= h)
		*line_end = h - 1;
}


//calculate lowest and highest pixel to fill in current vertical line
//draw the line with color based on cardinals direction
void	draw_ray3d(t_data *game, t_ray *ray, int x)
{
	t_tex	tex;
	int		line_start;
	int		line_end;
	int		y;

	calculate_height(ray, &line_start, &line_end);
	calculate_texture_info(game, ray, &tex, line_start);
	y = line_start;
	while (y < line_end)
	{
        tex.tex_pos += tex.step;
		mlx_put_pixel(game->img3d, x, y, get_color(ray->side, tex.tex_x, (int)tex.tex_pos % texHeight, game));
		y++;
	}
	draw_ray_mini(game, ray->wall_dist, ray->dirx, ray->diry);
}
