/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/25 13:42:36 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

uint32_t	get_color(int side)
{
	if (side == WEST)
		return (0x00FF00FF);
	else if (side == EAST)
		return (0xFF0000FF);
	else if (side == NORTH)
		return (0x0000FFFF);
	else
		return (0xFFFF00FF);
}

//calculate lowest and highest pixel to fill in current vertical line
//draw the line with color based on cardinals direction
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
			mlx_put_pixel(game->img, x, y, get_color(ray->side));
		y++;
	}
}
