/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:05:29 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/31 15:57:08 by lisa          ########   odam.nl         */
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
	game->mlx = mlx_init(WSIZE, WSIZE, "uauauiua", true);
	if (!game->mlx)
		error();
	game->img = mlx_new_image(game->mlx, WSIZE, WSIZE);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		error();
	game->minimap = mlx_new_image(game->mlx, WSIZE, WSIZE);
	if (!game->minimap
		|| /*(mlx_image_to_window(game->mlx, game->minimap, WSIZE, 0) < 0) ||*/ (mlx_image_to_window(game->mlx, game->minimap, 0, 0) < 0))// to remove in both
		error();
	game->mini = mlx_new_image(game->mlx, game->ray * 2, game->ray * 2);
	if (!game->mini || (mlx_image_to_window(game->mlx, game->mini, WSIZE - (game->ray * 2), WSIZE - (game->ray * 2)) < 0)) //place it in bottom right corner
		error();
}

void	init_player(t_data *game)
{
	int	x;
	int	y;

	x = game->pl.x;
	y = game->pl.y;
	game->m = false;
	game->ray = 100;
	game->map.sq_xsize = WSIZE / game->map.xsize;
	game->map.sq_ysize = WSIZE / game->map.ysize;
	if (game->map.xsize > game->map.ysize)
		game->map.sq_map = game->map.sq_xsize;
	else
		game->map.sq_map = game->map.sq_ysize;
	game->map.sq_mini = 20;
	game->pl.x = x * game->map.sq_xsize + (game->map.sq_xsize / 2);
	game->pl.y = y * game->map.sq_ysize + (game->map.sq_ysize / 2);
	game->pl.x_map = x * game->map.sq_map + (game->map.sq_map / 2);
	game->pl.y_map = y * game->map.sq_map + (game->map.sq_map / 2);
	game->pl.x_mini = x * game->map.sq_mini + (game->map.sq_mini / 2);
	game->pl.y_mini = y * game->map.sq_mini + (game->map.sq_mini / 2);
	game->pl.size = game->map.sq_map / 2;
}

void	m_button(t_data *game)
{
	if (game->m)
		game->m = false;
	else
		game->m = true;
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data *game;
	
	game = param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		m_button(game);
}

void	render(t_data *game)
{
	init_player(game);
	init_mlx(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	printf("map sizex = %d, sizey = %d\n", game->map.xsize, game->map.ysize);
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_image(game->mlx, game->minimap);
	mlx_delete_image(game->mlx, game->mini);
	mlx_terminate(game->mlx);
}
