/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 13:31:41 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/25 13:45:45 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

void	rotate_right(t_player *pl, double rot_speed)
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

void	rotate_left(t_player *pl, double rot_speed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = pl->pdirx;
	old_planex = pl->planex;
	pl->pdirx = old_dirx * cos(-rot_speed) - pl->pdiry * sin(-rot_speed);
	pl->pdiry = old_dirx * sin(-rot_speed) + pl->pdiry * cos(-rot_speed);
	pl->planex = old_planex * cos(-rot_speed) - pl->planey * sin(-rot_speed);
	pl->planey = old_planex * sin(-rot_speed) + pl->planey * cos(-rot_speed);
}
