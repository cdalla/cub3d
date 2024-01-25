/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:09:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/25 13:33:25 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#include "../../mlx/include/MLX42/MLX42.h"

void	rotate_left(t_player *pl, double rot_speed);
void	rotate_right(t_player *pl, double rot_speed);
void	mv_forward(t_data *game, t_player *pl);
void	mv_backward(t_data *game, t_player *pl);

bool	move_valid(t_data *game, int move)
{
	if (game->map.map[(int)((game->pl.y + move * (game->pl.pdiry * 2)))
		/ (int)game->map.sq_ysize][(int)((game->pl.x + move
			* (game->pl.pdirx * 2)) / (int)game->map.sq_xsize)] == '1')
		return (false);
	return (true);
}

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
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) && move_valid(game, 1))
		mv_forward(game, pl);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) && move_valid(game, -1))
		mv_backward(game, pl);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(pl, rot_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(pl, rot_speed);
	render2d(game);
	render3d(game);
}
