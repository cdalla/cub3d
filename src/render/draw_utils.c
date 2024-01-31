/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:31 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/31 15:54:24 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	reset_bg(mlx_image_t *img, int size)
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

void	reset_bg_mini(t_data *game, mlx_image_t *img, int size, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (pow((i - (int)game->ray), 2) + pow((j - (int)game->ray), 2) <= pow((int)game->ray, 2))
				mlx_put_pixel(img, i, j, color);
			else	
				mlx_put_pixel(img, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

double	fix_angle(double a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

float	degrees_to_radiant(double a)
{
	return (a * PI / 180);
}
