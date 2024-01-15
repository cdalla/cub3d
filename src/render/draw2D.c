/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw2D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:07:21 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/15 13:38:17 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>


void drawRay2D(t_data *game, double wallDist, double dirx, double diry)
{
	for (int i = 0; i < (wallDist * game->map.sq_size); i++) //draw direction line
	{
		mlx_put_pixel(game->minimap, game->pl.x2D + dirx * i, game->pl.y2D + diry * i, 0xFF0000FF); 
	}
}

void draw_sq2D(t_data *game, int x, int y, uint32_t color)
{
	for (int i = 0; i < game->map.sq_size - 1; i++)
	{
		for (int j = 0; j < game->map.sq_size - 1; j++)
		{
			mlx_put_pixel(game->minimap, x + i, y + j, color);
		}
	}
}

void drawBg2D(t_data *game)
{
	int y = 0;
	
	resetBg(game->minimap);
	for (int i = 0; i < game->map.ysize; i++)
	{
		int	x = 0;
		for (int j = 0; j < game->map.xsize; j++)
		{
			if (game->map.map[i][j] == '1' || game->map.map[i][j] == ' ')
				draw_sq2D(game, x, y, 0x00FF00FF);
			else
				draw_sq2D(game, x, y, 0xFFFFFFFF);
			x += game->map.sq_size;
		}
		y += game->map.sq_size;
	}
}

void drawPl2D(t_data *game)
{
	t_player *pl;
	
	pl = &game->pl;
	for (int i = 0; i < pl->size; i++)
	{
		for (int j = 0; j < pl->size; j++)
		{
			mlx_put_pixel(game->minimap, pl->x2D - pl->size/ 2 + i, pl->y2D - pl->size/ 2 + j, 0xFF0000FF);
		}
	}
	for (int i = 0; i < 20; i++) //draw direction line
		mlx_put_pixel(game->minimap, pl->x2D + pl->pdirx * i, pl->y2D + pl->pdiry * i, 0xFF0000FF); 
}
