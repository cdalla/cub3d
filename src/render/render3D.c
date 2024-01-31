/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render3D.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/31 12:56:45 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	draw_ray3d(t_data *game, t_ray *ray, int x);

//value of camerax between -1 (left side of screen) and 1 (right side),
//0 is the player direction 
void	calc_wall_dist3d(t_data *game, int x, t_ray *ray)
{
	double	camerax;
	int		mapx;
	int		mapy;

	mapy = (int)(game->pl.y / game->map.sq_ysize);
	mapx = (int)(game->pl.x / game->map.sq_xsize);
	camerax = 2 * x / (double)(WSIZE) - 1;
	ray->dirx = game->pl.pdirx + game->pl.planex * camerax;
	ray->diry = game->pl.pdiry + game->pl.planey * camerax;
	calc_delta_dist(ray);
	calc_init_side_distx(ray, mapx, game->pl.x / game->map.sq_xsize);
	calc_init_side_disty(ray, mapy, game->pl.y / game->map.sq_ysize);
	dda(game, ray, &mapx, &mapy);
	if (ray->side == 0 || ray->side == 1)
		ray->wall_dist = (ray->side_distx - ray->delta_x);
	else
		ray->wall_dist = (ray->side_disty - ray->delta_y);
}

void	render3d(t_data *game)
{
	t_ray	ray;
	int		x;

	//reset_bg(game->img);
	x = 0;
	while (x < WSIZE)
	{
		calc_wall_dist3d(game, x, &ray);
		draw_ray3d(game, &ray, x);
		x++;
	}
}
