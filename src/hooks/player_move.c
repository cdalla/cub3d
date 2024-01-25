/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 13:31:38 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/25 13:45:06 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

void	mv_forward(t_data *game, t_player *pl)
{
	pl->x += pl->pdirx * 2;
	pl->y += pl->pdiry * 2;
	pl->x2d += pl->pdirx * (2 * (game->map.sq_size / game->map.sq_xsize));
	pl->y2d += pl->pdiry * (2 * (game->map.sq_size / game->map.sq_ysize));
}

void	mv_backward(t_data *game, t_player *pl)
{
	pl->x -= pl->pdirx * 2;
	pl->y -= pl->pdiry * 2;
	pl->x2d -= pl->pdirx * (2 * (game->map.sq_size / game->map.sq_xsize));
	pl->y2d -= pl->pdiry * (2 * (game->map.sq_size / game->map.sq_ysize));
}
