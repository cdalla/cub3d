/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_minimap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisa <lisa@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 15:15:25 by lisa          #+#    #+#                 */
/*   Updated: 2024/01/31 15:55:48 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	draw_ray_mini(t_data *game, double wallDist, double dirx, double diry);
void	draw_bg_mini(t_data *game);

void	calc_wall_dist_mini(t_data *game, int x, t_ray *ray)
{
	double	camerax;
	int		mapx;
	int		mapy;

	mapy = (int)(game->pl.y_mini / game->map.sq_mini);
	mapx = (int)(game->pl.x_mini / game->map.sq_mini);
	camerax = 2 * x / (double)(WSIZE) - 1;
	ray->dirx = game->pl.pdirx + game->pl.planex * camerax;
	ray->diry = game->pl.pdiry + game->pl.planey * camerax;
	calc_delta_dist(ray);
	calc_init_side_distx(ray, mapx, game->pl.x_mini / game->map.sq_mini);
	calc_init_side_disty(ray, mapy, game->pl.y_mini / game->map.sq_mini);
	dda(game, ray, &mapx, &mapy);
	if (ray->side == 0 || ray->side == 1)
		ray->wall_dist = (ray->side_distx - ray->delta_x);
	else
		ray->wall_dist = (ray->side_disty - ray->delta_y);
}

void	render_mini(t_data *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	reset_bg_mini(game, game->mini, game->ray * 2, 0x000000FF);
	draw_bg_mini(game);
	while (x < WSIZE)
	{
		calc_wall_dist_mini(game, x, &ray);
		draw_ray_mini(game, ray.wall_dist, ray.dirx, ray.diry);
		x++;
	}
}