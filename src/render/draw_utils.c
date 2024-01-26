/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:31 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/26 20:40:45 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"

void	reset_bg(mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WSIZE)
	{
		j = 0;
		while (j < WSIZE)
		{
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

uint32_t	get_texture_color(int x, int y, mlx_image_t *texture, uint32_t col)
{
	if (texture)
		return (fillbrick(x, y, texture));
	else
		return (col);
}