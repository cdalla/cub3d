/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render2D.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:07 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/15 13:36:58 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void drawRay2D(t_data *game, double wallDist, double dirx, double diry);

double calcWallDist2D(t_data *game, float ang, double *dirx, double *diry)
{
	float angle = fixAngle(ang);
	//printf("i = %f\n", angle);
	*dirx = cos(degreesToRadiant(angle));
	*diry = -sin(degreesToRadiant(angle));
	
	int mapXpos = (int)(game->pl.x2D / game->map.sq_size);
	int mapYpos = (int)(game->pl.y2D / game->map.sq_size);
	
	//printf("initial mapx = %d, mapy = %d,\n", mapXpos, mapYpos); 
	//printf("initial dirx = %f, diry = %f\n", *dirx, *diry);
	
	double sideDistX;
	double sideDistY;
	
	double deltaDistX = sqrt(1 + (*diry / *dirx) * (*diry / *dirx));
	double deltaDistY = sqrt(1 + (*dirx / *diry) * (*dirx / *diry));
	// double deltaDistX = fabs(1 / dirx);
	// double deltaDistY = fabs(1 / diry);
	//printf("delta distX = %f\n", deltaDistX);
	//printf("delta distY = %f\n", deltaDistY);
	double wallDist;
	
	int stepX;
	int	stepY;
	
	int	hit = 0;
	int	side;
	
	if (*dirx < 0)
	{
		stepX = -1;
		sideDistX = (game->pl.x2D / game->map.sq_size - mapXpos) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapXpos + 1.0 - game->pl.x2D / game->map.sq_size) * deltaDistX;
	}
	if (*diry < 0)
	{
		stepY = -1;
		sideDistY = (game->pl.y2D / game->map.sq_size - mapYpos) *deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapYpos + 1.0 - game->pl.y2D / game->map.sq_size) * deltaDistY;
	}
	//DDA
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapXpos += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapYpos += stepY;
			side = 1;
		}
		//remove 'N' check
		if (game->map.map[mapYpos][mapXpos] == '1')
			hit = 1;
	}
	
	if (side == 0)
		wallDist = sideDistX - deltaDistX;
	else
		wallDist = sideDistY - deltaDistY;
		
	return (wallDist);
}

void render2D(t_data *game)
{
	float ang = game->pl.ang;
	double wallDist;
	double	dirx;
	double	diry;
	resetBg(game->minimap);
	drawBg2D(game);
	drawPl2D(game);
	for (int i = -30; i <= 30; i += 1)
	{
		wallDist = calcWallDist2D(game, (int)ang + i, &dirx, &diry);
		drawRay2D(game, wallDist, dirx, diry);
	}
}
