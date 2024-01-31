/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render2D.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:07 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/31 15:18:58 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	draw_ray2d(t_data *game, double wallDist, double dirx, double diry);

void	calc_wall_dist2d(t_data *game, int x, t_ray *ray)
{
	double	camerax;
	int		mapx;
	int		mapy;

	mapy = (int)(game->pl.y_map / game->map.sq_map);
	mapx = (int)(game->pl.x_map / game->map.sq_map);
	camerax = 2 * x / (double)(WSIZE) - 1;
	ray->dirx = game->pl.pdirx + game->pl.planex * camerax;
	ray->diry = game->pl.pdiry + game->pl.planey * camerax;
	calc_delta_dist(ray);
	calc_init_side_distx(ray, mapx, game->pl.x_map / game->map.sq_map);
	calc_init_side_disty(ray, mapy, game->pl.y_map / game->map.sq_map);
	dda(game, ray, &mapx, &mapy);
	if (ray->side == 0 || ray->side == 1)
		ray->wall_dist = (ray->side_distx - ray->delta_x);
	else
		ray->wall_dist = (ray->side_disty - ray->delta_y);
}

void	render2d(t_data *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	draw_bg2d(game);
	draw_pl2d(game);
	while (x < WSIZE)
	{
		calc_wall_dist2d(game, x, &ray);
		draw_ray2d(game, ray.wall_dist, ray.dirx, ray.diry);
		x++;
	}
}
