/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:05:29 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/26 20:06:07 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void	ft_hook(void *param);

void	error(void)
{
	printf("zio can!!!\n");
	exit(EXIT_FAILURE);
}

void	init_mlx(t_data	*game)
{
	game->mlx = mlx_init(WSIZE * 2, WSIZE, "uauauiua", true);
	if (!game->mlx)
		error();
	game->img = mlx_new_image(game->mlx, WSIZE, WSIZE);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, WSIZE, 0) < 0))
		error();
	game->minimap = mlx_new_image(game->mlx, WSIZE, WSIZE);
	if (!game->minimap
		|| (mlx_image_to_window(game->mlx, game->minimap, 0, 0) < 0))
		error();
}

void	init_player(t_data *game)
{
	int	x;
	int	y;

	x = game->pl.x;
	y = game->pl.y;
	game->map.sq_xsize = WSIZE / game->map.xsize;
	game->map.sq_ysize = WSIZE / game->map.ysize;
	if (game->map.xsize > game->map.ysize)
		game->map.sq_size = game->map.sq_xsize;
	else
		game->map.sq_size = game->map.sq_ysize;
	game->pl.x = x * game->map.sq_xsize + (game->map.sq_xsize / 2);
	game->pl.y = y * game->map.sq_ysize + (game->map.sq_ysize / 2);
	game->pl.x2d = x * game->map.sq_size + (game->map.sq_size / 2);
	game->pl.y2d = y * game->map.sq_size + (game->map.sq_size / 2);
	game->pl.size = 10;
}

void	render(t_data *game)
{
	init_player(game);
	init_mlx(game);
	load_and_resize_all_textures(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	printf("map sizex = %d, sizey = %d\n", game->map.xsize, game->map.ysize);
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_image(game->mlx, game->minimap);
	mlx_terminate(game->mlx);
}
