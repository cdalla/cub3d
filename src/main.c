/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 13:56:47 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/04 17:04:12 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
mlx_image_t* image;
mlx_image_t* floortile;

int32_t mlx_initial() {
	mlx_t* mlx;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Carlo&Kaay", true))) {
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 50, 50))) {
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(floortile = mlx_new_image(mlx, WIDTH, HEIGHT))) {
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1) {
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, floortile, 0, 0) == -1) {
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_box, mlx);
	mlx_loop_hook(mlx, background, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);


	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char	**argv)
{
	t_data	game;

	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
		return (print_err_msg("parser", "invalid input"), 1);
	game.no = 0;
	game.we = 0;
	game.so = 0;
	game.ea = 0;
	game.map = 0;
	if (parser(argv[1], &game))
	{
		free_data(&game);
		return (1);
	}
	//start game
	mlx_initial();
	free_data(&game);
	//system("leaks cub3d");
	return (0);
}
