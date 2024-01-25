/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 12:10:50 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/24 14:25:54 by cdalla-s      ########   odam.nl         */
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
void	calc_init_side_distx_3d(t_data *game, t_ray *ray, int mapx)
{
	if (ray->dirx < 0)
	{
		ray->step_x = -1;
		ray->side_distx = (game->pl.x / game->map.sq_xsize - mapx)
			* ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distx = (mapx + 1.0 - game->pl.x / game->map.sq_xsize)
			* ray->delta_x;
	}
}

//calculate initial distance from pl posiiton to first y
void	calc_init_side_disty_3d(t_data *game, t_ray *ray, int mapy)
{
	if (ray->diry < 0)
	{
		ray->step_y = -1;
		ray->side_disty = (game->pl.y / game->map.sq_ysize - mapy)
			* ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_disty = (mapy + 1.0 - game->pl.y / game->map.sq_ysize)
			* ray->delta_y;
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
		if (game->map.map[*mapy][*mapx] == '1')
			return ;
	}
}
