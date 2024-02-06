/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw2D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:07:21 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 12:52:06 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	draw_ray2d(t_data *game, double wallDist, double dirx, double diry)
{
	int	i;

	i = 0;
	while (i < (wallDist * game->map.sq_map))
	{
		mlx_put_pixel(game->map2d, game->pl.x_map + dirx * i, game->pl.y_map + diry * i, 0xFF0000FF);
		i++;
	}
}

void	draw_sq2d(t_data *game, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.sq_map - 1)
	{
		j = 0;
		while (j < game->map.sq_map - 1)
		{
			mlx_put_pixel(game->map2d, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_bg2d(t_data *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < game->map.ysize)
	{
		x = 0;
		j = 0;
		while (j < game->map.xsize)
		{
			if (game->map.array[i][j] == '1' || game->map.array[i][j] == ' ')
				draw_sq2d(game, x, y, 0x000000FF);
			else
				draw_sq2d(game, x, y, 0xFFFFFFFF);
			x += game->map.sq_map;
			j++;
		}
		y += game->map.sq_map;
		i++;
	}
	draw_pl2d(game, game->map2d, game->pl.x_map - game->pl.size / 2, game->pl.y_map - game->pl.size / 2);
}

