/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 15:03:00 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/12 12:31:36 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	save_pl_data(t_data *game, int *player, int i, int j);

int	texture_valid(t_data *game)
{
	if (!game->no || !game->so || !game->we || !game->ea)
		return (print_err_msg("parser", "missing texture path"), 1);
	else if (access(game->no, R_OK) == -1)
		return (print_err_msg("parser", "north texture not available"), 1);
	else if (access(game->so, R_OK) == -1)
		return (print_err_msg("parser", "south texture not available"), 1);
	else if (access(game->we, R_OK) == -1)
		return (print_err_msg("parser", "west texture not available"), 1);
	else if (access(game->ea, R_OK) == -1)
		return (print_err_msg("parser", "east texture not available"), 1);
	return (0);
}

int	color_valid(t_data *game)
{
	if (game->f[0] == -1 && game->f[1] == -1 && game->f[2] == -1)
		return (print_err_msg("parser", "floor color not found"), 1);
	if (game->c[0] == -1 && game->c[1] == -1 && game->c[2] == -1)
		return (print_err_msg("parser", "ceiling color not found"), 1);
	if (game->f[0] > 255 || game->f[0] < 0
		|| game->f[1] > 255 || game->f[1] < 0
		|| game->f[2] > 255 || game->f[2] < 0)
		return (print_err_msg("parser", "color value not valid"), 1);
	if (game->c[0] > 255 || game->c[0] < 0
		|| game->c[1] > 255 || game->c[1] < 0
		|| game->c[2] > 255 || game->c[2] < 0)
		return (print_err_msg("parser", "color value not valid"), 1);
	return (0);
}

int	map_valid(t_data *game)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (ft_strchr_index("01NSEW", game->map.array[i][j]) == -1
				&& !is_space(game->map.array[i][j]))
				return (print_err_msg("parser", "invalid symbol in map"), 1);
			if (ft_strrchr("NSEW", game->map.array[i][j]) && !player)
				save_pl_data(game, &player, i, j);
			else if (ft_strrchr("NSEW", game->map.array[i][j]) && player)
				return (print_err_msg("parser", "starting pos doubled"), 1);
			j++;
		}
		i++;
	}
	if (game->pl.x == -1 && game->pl.y == -1)
		return (print_err_msg("parser", "starting pos missing"), 1);
	return (0);
}

int	validate_data(t_data *game)
{
	if (texture_valid(game) || color_valid(game) || map_valid(game))
		return (1);
	return (0);
}
