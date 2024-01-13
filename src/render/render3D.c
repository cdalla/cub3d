/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render3D.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/13 12:14:04 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void drawRay3D(t_data *game, double wallDist, int x, int ang);

double calcWallDist3D(t_data *game, float ang, double *dirx, double *diry)
{
	float angle = fixAngle(ang);
	//printf("i = %f\n", angle);
	*dirx = cos(degreesToRadiant(angle));
	*diry = -sin(degreesToRadiant(angle));
	
	int mapXpos = (int)(game->pl.x / game->map.sq_xsize);
	int mapYpos = (int)(game->pl.y / game->map.sq_ysize);
	
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
		sideDistX = (game->pl.x / game->map.sq_xsize - mapXpos) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapXpos + 1.0 - game->pl.x / game->map.sq_xsize) * deltaDistX;
	}
	if (*diry < 0)
	{
		stepY = -1;
		sideDistY = (game->pl.y / game->map.sq_ysize - mapYpos) *deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapYpos + 1.0 - game->pl.y / game->map.sq_ysize) * deltaDistY;
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
		if (game->map.map[mapYpos][mapXpos] == '1' || game->map.map[mapYpos][mapXpos] == 'N')
			hit = 1;
	}
	
	if (side == 0)
		wallDist = sideDistX - deltaDistX;
	else
		wallDist = sideDistY - deltaDistY;

	return (wallDist);
}

void render3D(t_data *game)
{
	float	ang;
	int		x; //witdh of a ray on the screen
	double	wallDist;
	double	dirx;
	double	diry;
	
	ang = game->pl.ang;
	x = wsize + 1;
	resetBg(game->img);
	for (int i = -30; i <= 30; i += 1)
	{
		wallDist = calcWallDist3D(game, (int)ang + i, &dirx, &diry);
		drawRay3D(game, wallDist, x, (int)ang + i);
		x -= wsize / 60;
	}
}
