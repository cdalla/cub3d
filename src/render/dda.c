/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 12:10:50 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 12:06:30 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

//calculate distance between one x and next, one y and next
void	calc_delta_dist(t_ray *ray)
{
	if (ray->dirx == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->dirx);
	if (ray->diry == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->diry);
}

//calculate initial distance from pl position to first x
void	calc_init_side_distx(t_ray *ray, int map_x, double pl_x)
{
	if (ray->dirx < 0)
	{
		ray->step_x = -1;
		ray->side_distx = (pl_x - map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distx = (map_x + 1.0 - pl_x) * ray->delta_x;
	}
}

//calculate initial distance from pl posiiton to first y
void	calc_init_side_disty(t_ray *ray, int map_y, double pl_y)
{
	if (ray->diry < 0)
	{
		ray->step_y = -1;
		ray->side_disty = (pl_y - map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_disty = (map_y + 1.0 - pl_y) * ray->delta_y;
	}
}

//calculation loop to find the distance to the first wall on the map
void	dda(t_data *game, t_ray *ray, int *mapx, int *mapy)
{
	while (1)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_x;
			*mapx += ray->step_x;
			if (ray->dirx < 0)
				ray->side = WEST;
			else
				ray->side = EAST;
		}
		else
		{
			ray->side_disty += ray->delta_y;
			*mapy += ray->step_y;
			if (ray->diry < 0)
				ray->side = NORTH;
			else
				ray->side = SOUTH;
		}
		if (game->map.array[*mapy][*mapx] == '1')
			return ;
	}
}

//value of camerax between -1 (left side of screen) and 1 (right side),
//0 is the player direction 
void	calc_wall_dist(t_data *game, int x, t_ray *ray)
{
	double	camerax;
	int		mapx;
	int		mapy;

	mapy = (int)game->pl.y;
	mapx = (int)game->pl.x;
	camerax = 2 * x / (double)(WSIZE) - 1;
	ray->dirx = game->pl.pdirx + game->pl.planex * camerax;
	ray->diry = game->pl.pdiry + game->pl.planey * camerax;
	calc_delta_dist(ray);
	calc_init_side_distx(ray, mapx, game->pl.x);
	calc_init_side_disty(ray, mapy, game->pl.y);
	dda(game, ray, &mapx, &mapy);
	if (ray->side == 0 || ray->side == 1)
		ray->wall_dist = (ray->side_distx - ray->delta_x);
	else
		ray->wall_dist = (ray->side_disty - ray->delta_y);
}