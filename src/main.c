/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:56:47 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/22 15:45:11 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	free_data(&game);
	//system("leaks cub3d");
	return (0);
}
