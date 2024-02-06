/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:09:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 14:38:47 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#include "../../mlx/include/MLX42/MLX42.h"

void	render_scene(t_data *game);
void	pl_move(t_data *game, double dirx, double diry, double mv_speed);
void	pl_rotate(t_player *pl, double rot_speed);

void	m_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data	*game;
	
	game = param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
	{
		if (game->map_show)
			game->map_show = false;
		else
			game->map_show = true;
	}
}

void	movement(t_data *game)
{
	double		mv_speed;
	t_player	*pl;

	pl = &game->pl;
	mv_speed = game->mlx->delta_time * 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		pl_move(game, pl->pdirx, pl->pdiry, mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		pl_move(game, pl->pdirx, pl->pdiry, -mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		pl_move(game, (pl->pdirx * cos(deg_to_rad(90)) - pl->pdiry * sin(deg_to_rad(90))), 
				(pl->pdirx * sin(deg_to_rad(90)) + pl->pdiry * cos(deg_to_rad(90))), mv_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		pl_move(game, (pl->pdirx * cos(-deg_to_rad(90)) - pl->pdiry * sin(-deg_to_rad(90))), 
				(pl->pdirx * sin(-deg_to_rad(90)) + pl->pdiry * cos(-deg_to_rad(90))), mv_speed);
}

void	rotate(t_data *game)
{
	double		rot_speed;
	t_player	*pl;
	
	pl = &game->pl;
	rot_speed = game->mlx->delta_time * 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		pl_rotate(pl, rot_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		pl_rotate(pl, -rot_speed);
}

void	ft_hook(void *param)
{
	t_data		*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	movement(game);
	rotate(game);
	render_scene(game);
}