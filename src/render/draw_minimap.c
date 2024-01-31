/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisa <lisa@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 15:15:20 by lisa          #+#    #+#                 */
/*   Updated: 2024/01/31 15:16:39 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

bool	in_circle(t_data *game, int x, int y, int ray)
{
	if (pow((x - (int)game->pl.x_mini), 2) + pow((y - (int)game->pl.y_mini), 2) <= pow(ray, 2))
		return (true);
	return (false);
}

void	draw_ray_mini(t_data *game, double wallDist, double dirx, double diry)
{
	int	i;

	i = 0;
	while (i < (wallDist * game->map.sq_mini))
	{
		if (in_circle(game, game->pl.x_mini + dirx * i, game->pl.y_mini + diry * i, game->ray))
		{
			mlx_put_pixel(game->mini, game->ray + dirx * i, game->ray + diry * i, 0xFF0000FF);
		}
		i++;
	}
}

void	draw_sq_mini(t_data *game, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.sq_mini - 1)
	{
		j = 0;
		while (j < game->map.sq_mini - 1)
		{
			if (in_circle(game, x + i, y + j, game->ray))
			{
				mlx_put_pixel(game->mini, game->ray - (game->pl.x_mini - (x + i)), game->ray - (game->pl.y_mini - (y + j)), color);
			}
			j++;
		}
		i++;
	}
}

void	draw_bg_mini(t_data *game)
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
			if (game->map.map[i][j] == '1' || game->map.map[i][j] == ' ')
				draw_sq_mini(game, x, y, 0x000000FF);
			else
				draw_sq_mini(game, x, y, 0xFFFFFFFF);
			x += game->map.sq_mini;
			j++;
		}
		y += game->map.sq_mini;
		i++;
	}
}