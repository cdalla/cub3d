/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3D.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:17 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/15 15:47:48 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void drawRay3D(t_data *game, double wallDist, int x, int ang)
{
	int fixedAng;

	fixedAng = game->pl.ang - ang;
	wallDist = wallDist * cos(degreesToRadiant(fixAngle(fixedAng)));
	int h = wsize;
	int lineHeight = (int)(wsize / wallDist);
	
    //calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + wsize / 2;
    if(drawStart < 0)
		drawStart = 0;
    int drawEnd = lineHeight / 2 + wsize / 2;
    if(drawEnd >= h)
		drawEnd = h - 1;
	
	for (int i = 0; i < wsize/FOV; i++)
	{
		for (int y = drawStart; y <= drawEnd; y++)
		{
			if ((x + i) < wsize)
				mlx_put_pixel(game->img, x + i, y, 0xFF0000FF);
		}
	}
}