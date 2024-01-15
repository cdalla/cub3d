/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:09:11 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/15 15:18:14 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

bool	move_valid(t_data *game, int move)//move == to -1 or 1
{
	if (game->map.map[(int)((game->pl.y + move * (game->pl.pdiry * 2)))/game->map.sq_ysize][(int)((game->pl.x + move * (game->pl.pdirx * 2))/game->map.sq_xsize)] == '1')
		return false;
	return true;
}

void	ft_hook(void *param)
{
	t_data *game;
	t_player *pl;
	
	game = param;
	pl = &game->pl;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) && move_valid(game, 1))
	{
		pl->x += pl->pdirx * 2;
		pl->y += pl->pdiry * 2;
		pl->x2D += pl->pdirx * 2; //to fix
		pl->y2D += pl->pdiry * 2; //to fix
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) && move_valid(game, -1))
	{
		pl->x -= pl->pdirx * 2;
		pl->y -= pl->pdiry * 2;
		pl->x2D -= pl->pdirx * 2; //to fix
		pl->y2D -= pl->pdiry * 2; //to fix
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		pl->ang += 2;
		pl->ang = fixAngle(pl->ang);
		pl->pdirx = cos(degreesToRadiant(pl->ang));
		pl->pdiry = -sin(degreesToRadiant(pl->ang));
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		pl->ang -= 2;
		pl->ang = fixAngle(pl->ang);
		pl->pdirx = cos(degreesToRadiant(pl->ang));
		pl->pdiry = -sin(degreesToRadiant(pl->ang));
	}
	printf("%f\n", game->mlx->delta_time);
	render2D(game);
	render3D(game);
}