/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 12:12:31 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/13 12:13:53 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"

void resetBg(mlx_image_t *img)
{
	for (int i = 0; i < wsize; i++)
	{
		for (int j = 0; j < wsize; j++)
		{
			mlx_put_pixel(img, i, j, 0x00000000);
		}
	}
}

int fixAngle(int a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

float degreesToRadiant(int a)
{
	return (a * PI / 180);
}