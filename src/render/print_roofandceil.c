#include "../cube.h"
extern mlx_image_t* image;
extern mlx_image_t* floortile;

void	draw_borders_help(mlx_image_t *floortile)
{
	uint32_t	i;
	uint32_t	y;

	i = 0;
	while (i < floortile->width)
	{
		y = 0;
		while (y < 10)
		{
			mlx_put_pixel(floortile, i, y, 4123000123);
			y++;
		}
		i++;
	}
	i = 0;
	while (i < floortile->width)
	{
		y = floortile->height - 10;
		while (y < floortile->height)
		{
			mlx_put_pixel(floortile, i, y, 4123000123);
			y++;
		}
		i++;
	}
}

void	draw_borders(mlx_image_t *floortile)
{
	uint32_t	i, y;

	i = 0;
	while (i < 10)
	{
		y = 0;
		while (y < floortile->height)
		{
			mlx_put_pixel(floortile, i, y, 4123000123);
			y++;
		}
		i++;
	}
	i = floortile->width - 10;
	while (i < floortile->width)
	{
		y = 0;
		while (y < floortile->height)
		{
			mlx_put_pixel(floortile, i, y, 4123000123);
			y++;
		}
		i++;
	}
	draw_borders_help(floortile);
}

void	background(void *param __attribute__((unused)))
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < floortile->width)
	{
		y = 0;
		while (y < (floortile->height / 2))
		{
			mlx_put_pixel(floortile, x, y, 6187136);
			y++;
		}
		y = floortile->height / 2;
		while (y < floortile->height)
		{
			mlx_put_pixel(floortile, x, y, 4267405709);
			y++;
		}
		x++;
	}
	draw_borders(floortile);
}
