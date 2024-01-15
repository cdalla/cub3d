/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 11:05:29 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/15 15:16:29 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../mlx/include/MLX42/MLX42.h"
#include <math.h>

void ft_hook(void *param);

void error(void)
{
	printf("zio can!!!\n");
	exit(EXIT_FAILURE);
}

void init_player(t_data *game)
{
	int x = game->pl.x; //delete this and get initial pos from parser
	int y = game->pl.y;
	game->map.sq_xsize = wsize / game->map.xsize;
	game->map.sq_ysize = wsize / game->map.ysize;
	if (game->map.xsize > game->map.ysize)
		game->map.sq_size = game->map.sq_xsize;
	else
		game->map.sq_size = game->map.sq_ysize;
	game->pl.x = x * game->map.sq_xsize + (game->map.sq_xsize / 2);	//player X
	game->pl.y = y * game->map.sq_ysize + (game->map.sq_ysize / 2);	//player Y
	game->pl.x2D = x * game->map.sq_size + (game->map.sq_size / 2);
	game->pl.y2D = y * game->map.sq_size + (game->map.sq_size / 2);
	game->pl.ang = 20;	//player direction
	game->pl.pdirx = cos(degreesToRadiant(game->pl.ang)); //player direction ray X
	game->pl.pdiry = -sin(degreesToRadiant(game->pl.ang)); //player direction ray Y
	game->pl.size = 10;
	game->mlx = mlx_init(wsize * 2, wsize, "uauauiua", true);
	if (!game->mlx)
		error();
	game->img = mlx_new_image(game->mlx, wsize, wsize);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, wsize, 0) < 0))
		error();
	game->minimap = mlx_new_image(game->mlx, wsize, wsize);
	if (!game->minimap || (mlx_image_to_window(game->mlx, game->minimap, 0, 0) < 0))
		error();	
}

void render(t_data *game)
{
	init_player(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	printf("map sizex = %d, sizey = %d\n", game->map.xsize, game->map.ysize);
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_image(game->mlx, game->minimap);
	mlx_terminate(game->mlx);
}