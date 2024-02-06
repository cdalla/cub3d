/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:31 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 11:58:03 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

//reset all pixel of an image
void	reset_img(mlx_image_t *img, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(img, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

//conversion of degrees to radiant value
float	deg_to_rad(double a)
{
	return (a * PI / 180);
}

void	draw_pl2d(t_data *game, mlx_image_t *img, int x, int y)
{
	t_player	*pl;
	int			i;
	int			j;

	i = 0;
	pl = &game->pl;
	while (i < pl->size)
	{
		j = 0;
		while (j < pl->size)
		{
			mlx_put_pixel(img, x + i, y + j, 0xFF0000FF);
			j++;
		}
		i++;
	}
}
