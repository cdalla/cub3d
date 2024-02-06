/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:05:29 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 12:15:34 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	ft_hook(void *param);
void	m_keyhook(mlx_key_data_t keydata, void* param);
void	error(void);

void	draw_ray3d(t_data *game, t_ray *ray, int x);
void	draw_ray2d(t_data *game, double wallDist, double dirx, double diry);
void	draw_bg_mini(t_data *game);



void	init_mlx(t_data	*game)
{
	game->mlx = mlx_init(WSIZE, WSIZE, "uauauiua", true);
	if (!game->mlx)
		error();
	game->img3d = mlx_new_image(game->mlx, WSIZE, WSIZE);
	if (!game->img3d || (mlx_image_to_window(game->mlx, game->img3d, 0, 0) < 0))
		error();
	game->map2d = mlx_new_image(game->mlx, WSIZE, WSIZE);
	if (!game->map2d|| mlx_image_to_window(game->mlx, game->map2d, 0, 0) < 0)
		error();
	game->mini = mlx_new_image(game->mlx, game->ray * 2, game->ray * 2);
	if (!game->mini || (mlx_image_to_window(game->mlx, game->mini, WSIZE - (game->ray * 2), WSIZE - (game->ray * 2)) < 0)) //place it in bottom right corner
		error();
}

void	init_player(t_data *game)
{
	game->pl.x += 0.5;
	game->pl.y += 0.5;
	game->map_show = false;
	game->ray = WSIZE / 6;
	if (game->map.xsize > game->map.ysize)
		game->map.sq_map = WSIZE / game->map.xsize;
	else
		game->map.sq_map = WSIZE / game->map.ysize;
	game->map.sq_mini = game->ray / 5;
	game->pl.x_map = game->pl.x * game->map.sq_map;
	game->pl.y_map = game->pl.y * game->map.sq_map;
	game->pl.x_mini = game->pl.x * game->map.sq_mini;
	game->pl.y_mini = game->pl.y * game->map.sq_mini;
	game->pl.size = game->map.sq_map / 2;
}

void	reset_all_img(t_data *game)
{
	reset_img(game->mini, game->ray * 2);//reset img 3d
	reset_img(game->img3d, WSIZE);//reset img 3d
	reset_img(game->map2d, WSIZE);//reset img map
}

void	render_scene(t_data *game)
{
	t_ray	ray;
	int		x;
	
	reset_all_img(game);
	x = 0;
	if (game->map_show)
		draw_bg2d(game);
	else
		reset_bg_mini(game, game->mini);
	while (x < WSIZE)
	{
		calc_wall_dist(game, x, &ray);
		if (game->map_show)
			draw_ray2d(game, ray.wall_dist, ray.dirx, ray.diry);// map
		else
			draw_ray3d(game, &ray, x); //scene 3d
		x++;
	}
}

void	render(t_data *game)
{
	init_player(game);
	init_mlx(game);
	mlx_key_hook(game->mlx, &m_keyhook, game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->img3d);
	mlx_delete_image(game->mlx, game->map2d);
	mlx_delete_image(game->mlx, game->mini);
	mlx_terminate(game->mlx);
}
