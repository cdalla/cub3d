/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_background.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kaltevog <kaltevog@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/08 20:53:13 by kaltevog      #+#    #+#                 */
/*   Updated: 2024/02/08 21:08:45 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"

void	draw_background(t_data *game, int line_start, int line_end, int x)
{
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	int			y;

	y = 0;
	ceiling_color = (game->c[0] << 24) | (game->c[1] << 16) \
	| (game->c[2] << 8) | 0xFF;
	floor_color = (game->f[0] << 24) | (game->f[1] << 16) \
	| (game->f[2] << 8) | 0xFF;
	while (y < line_start)
	{
		mlx_put_pixel(game->img3d, x, y, ceiling_color);
		y++;
	}
	y = line_end;
	while (y < WSIZE)
	{
		mlx_put_pixel(game->img3d, x, y, floor_color);
		y++;
	}
}
