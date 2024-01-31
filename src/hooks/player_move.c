/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 13:31:38 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/31 13:41:32 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

bool	move_valid(t_data *game, int move, double dirx, double diry);

void	mv_left(t_data *game, t_player *pl)
{
	double	dirx;
	double	diry;

	dirx = pl->pdirx * cos(-degrees_to_radiant(90)) - pl->pdiry * sin(-degrees_to_radiant(90));
	diry = pl->pdirx * sin(-degrees_to_radiant(90)) + pl->pdiry * cos(-degrees_to_radiant(90));
	if (move_valid(game, 1, dirx, diry))
	{
		pl->x += dirx * 2;
		pl->y += diry * 2;
		pl->x_map += dirx * (2 * (game->map.sq_map / game->map.sq_xsize));
		pl->y_map += diry * (2 * (game->map.sq_map / game->map.sq_ysize));
		pl->x_mini += dirx * (2 * (game->map.sq_mini / game->map.sq_xsize));
		pl->y_mini += diry * (2 * (game->map.sq_mini / game->map.sq_ysize));
	}
}

void	mv_right(t_data *game, t_player *pl)
{
	double	dirx;
	double	diry;

	dirx = pl->pdirx * cos(degrees_to_radiant(90)) - pl->pdiry * sin(degrees_to_radiant(90));
	diry = pl->pdirx * sin(degrees_to_radiant(90)) + pl->pdiry * cos(degrees_to_radiant(90));
	if (move_valid(game, 1, dirx, diry))
	{
		pl->x += dirx * 2;
		pl->y += diry * 2;
		pl->x_map += dirx * (2 * (game->map.sq_map / game->map.sq_xsize));
		pl->y_map += diry * (2 * (game->map.sq_map / game->map.sq_ysize));
		pl->x_mini += dirx * (2 * (game->map.sq_mini / game->map.sq_xsize));
		pl->y_mini += diry * (2 * (game->map.sq_mini / game->map.sq_ysize));
	}
}

void	mv_forward(t_data *game, t_player *pl)
{
	pl->x += pl->pdirx * 2;
	pl->y += pl->pdiry * 2;
	pl->x_map += pl->pdirx * (2 * (game->map.sq_map / game->map.sq_xsize));
	pl->y_map += pl->pdiry * (2 * (game->map.sq_map / game->map.sq_ysize));
	pl->x_mini += pl->pdirx * (2 * (game->map.sq_mini / game->map.sq_xsize));
	pl->y_mini += pl->pdiry * (2 * (game->map.sq_mini / game->map.sq_ysize));
}

void	mv_backward(t_data *game, t_player *pl)
{
	pl->x -= pl->pdirx * 2;
	pl->y -= pl->pdiry * 2;
	pl->x_map -= pl->pdirx * (2 * (game->map.sq_map / game->map.sq_xsize));
	pl->y_map -= pl->pdiry * (2 * (game->map.sq_map / game->map.sq_ysize));
	pl->x_mini -= pl->pdirx * (2 * (game->map.sq_mini / game->map.sq_xsize));
	pl->y_mini -= pl->pdiry * (2 * (game->map.sq_mini / game->map.sq_ysize));
}
