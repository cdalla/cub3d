/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_pl_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 13:49:26 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 12:19:21 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	pl_to_north(t_player *pl)
{
	pl->pdirx = 0;
	pl->pdiry = -1;
	pl->planex = 0.66;
	pl->planey = 0;
}

void	pl_to_south(t_player *pl)
{
	pl->pdirx = 0;
	pl->pdiry = 1;
	pl->planex = -0.66;
	pl->planey = 0;
}

void	pl_to_east(t_player *pl)
{
	pl->pdirx = 1;
	pl->pdiry = 0;
	pl->planex = 0;
	pl->planey = 0.66;
}

void	pl_to_west(t_player *pl)
{
	pl->pdirx = -1;
	pl->pdiry = 0;
	pl->planex = 0;
	pl->planey = -0.66;
}

void	save_pl_data(t_data *game, int *player, int i, int j)
{
	*player = 1;
	game->pl.x = j;
	game->pl.y = i;
	if (game->map.array[i][j] == 'N')
		pl_to_north(&game->pl);
	else if (game->map.array[i][j] == 'S')
		pl_to_south(&game->pl);
	else if (game->map.array[i][j] == 'E')
		pl_to_east(&game->pl);
	else if (game->map.array[i][j] == 'W')
		pl_to_west(&game->pl);
}
