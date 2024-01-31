/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:09:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/31 15:55:57 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#include "../../mlx/include/MLX42/MLX42.h"

void	render_mini(t_data *game);

void	rotate_left(t_player *pl, double rot_speed);
void	rotate_right(t_player *pl, double rot_speed);
void	mv_forward(t_data *game, t_player *pl);
void	mv_backward(t_data *game, t_player *pl);
void	mv_right(t_data *game, t_player *pl);
void	mv_left(t_data *game, t_player *pl);

bool	move_valid(t_data *game, int move, double dirx, double diry)
{
	if (game->map.map[(int)((game->pl.y + move * (diry * 2)))
		/ (int)game->map.sq_ysize][(int)((game->pl.x + move
			* (dirx * 2)) / (int)game->map.sq_xsize)] == '1')
		return (false);
	return (true);
}

// void	m_button(t_data *game)
// {
// 	if (game->m)
// 		game->m = false;
// 	else
// 		game->m = true;
// }

void	ft_hook(void *param)
{
	t_data		*game;
	t_player	*pl;
	double		rot_speed;

	game = param;
	pl = &game->pl;
	rot_speed = game->mlx->delta_time * 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && move_valid(game, 1, pl->pdirx, pl->pdiry))
		mv_forward(game, pl);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && move_valid(game, -1, pl->pdirx, pl->pdiry))
		mv_backward(game, pl);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(pl, rot_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(pl, rot_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		mv_right(game, pl);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		mv_left(game, pl);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_M))
	// 	m_button(game);
	reset_bg_mini(game, game->mini, game->ray * 2, 0x00000000);
	reset_bg(game->img, WSIZE);
	reset_bg(game->minimap, WSIZE);
	if (game->m)
		render2d(game);
	else
	{
		render3d(game);
		render_mini(game);
	}
}
