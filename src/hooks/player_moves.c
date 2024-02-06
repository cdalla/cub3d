/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_moves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 13:31:38 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 12:06:14 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

bool	move_valid(t_data *game, double dirx, double diry, double mv_speed)
{
	if (game->map.array[(int)(game->pl.y + (diry * mv_speed))]
		[(int)(game->pl.x + (dirx * mv_speed))] == '1')
		return (false);
	return (true);
}

void	pl_move(t_data *game, double dirx, double diry, double mv_speed)
{
	t_player *pl;

	pl = &game->pl;
	if (move_valid(game, dirx, diry, mv_speed))
	{
		pl->x += dirx * mv_speed;
		pl->y += diry * mv_speed;
		pl->x_mini = pl->x * game->map.sq_mini;
		pl->y_mini = pl->y * game->map.sq_mini;
		pl->x_map = pl->x * game->map.sq_map;
		pl->y_map = pl->y * game->map.sq_map;
	}
}

void	pl_rotate(t_player *pl, double rot_speed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = pl->pdirx;
	old_planex = pl->planex;
	pl->pdirx = old_dirx * cos(rot_speed) - pl->pdiry * sin(rot_speed);
	pl->pdiry = old_dirx * sin(rot_speed) + pl->pdiry * cos(rot_speed);
	pl->planex = old_planex * cos(rot_speed) - pl->planey * sin(rot_speed);
	pl->planey = old_planex * sin(rot_speed) + pl->planey * cos(rot_speed);
}
