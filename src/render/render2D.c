/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render2D.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:07 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/25 13:44:25 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	draw_ray2d(t_data *game, double wallDist, double dirx, double diry);

//calculate initial distance from pl position to first x
void	calc_init_side_distx_2d(t_data *game, t_ray *ray, int mapx)
{
	if (ray->dirx < 0)
	{
		ray->step_x = -1;
		ray->side_distx = (game->pl.x2d / game->map.sq_size - mapx)
			* ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distx = (mapx + 1.0 - game->pl.x2d / game->map.sq_size)
			* ray->delta_x;
	}
}

//calculate initial distance from pl posiiton to first y
void	calc_init_side_disty_2d(t_data *game, t_ray *ray, int mapy)
{
	if (ray->diry < 0)
	{
		ray->step_y = -1;
		ray->side_disty = (game->pl.y2d / game->map.sq_size - mapy)
			* ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_disty = (mapy + 1.0 - game->pl.y2d / game->map.sq_size)
			* ray->delta_y;
	}
}

void	calc_wall_dist2d(t_data *game, int x, t_ray *ray)
{
	double	camerax;
	int		mapx;
	int		mapy;

	mapy = (int)(game->pl.y2d / game->map.sq_size);
	mapx = (int)(game->pl.x2d / game->map.sq_size);
	camerax = 2 * x / (double)(WSIZE) - 1;
	ray->dirx = game->pl.pdirx + game->pl.planex * camerax;
	ray->diry = game->pl.pdiry + game->pl.planey * camerax;
	calc_delta_dist(ray);
	calc_init_side_distx_2d(game, ray, mapx);
	calc_init_side_disty_2d(game, ray, mapy);
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

	reset_bg(game->minimap);
	draw_bg2d(game);
	draw_pl2d(game);
	while (x < WSIZE)
	{
		calc_wall_dist2d(game, x, &ray);
		draw_ray2d(game, ray.wall_dist, ray.dirx, ray.diry);
		x++;
	}
}
