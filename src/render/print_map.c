#include "../cube.h"


extern mlx_image_t* image;
extern mlx_image_t* floortile;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

	void	ft_box(void* param __attribute__((unused)))
	{
		for (uint32_t i = 0; i < image->width; ++i)
		{
			for (uint32_t y = 0; y < image->height; ++y)
			{
				mlx_put_pixel(image, i, y, 4267405709);
			}
		}
		for (uint32_t i = 0; i < 10; ++i)
		{
			for (uint32_t y = 0; y < image->height; ++y)
			{
			mlx_put_pixel(image, i, y, 4123000123);
			}
		}
		for (uint32_t i = image->width - 10; i < image->width; ++i)
		{
			for (uint32_t y = 0; y < image->height; ++y)
			{
			mlx_put_pixel(image, i, y, 4123000123);
			}
		}
	}
