/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:21 by cdalla-s          #+#    #+#             */
/*   Updated: 2024/01/05 13:40:15 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	adjacent_valid(t_data *game, int i, int j)
{
	if (is_space(game->map[i - 1][j - 1])
		|| is_space(game->map[i - 1][j])
		|| is_space(game->map[i - 1][j + 1])
		|| is_space(game->map[i][j - 1])
		|| is_space(game->map[i][j + 1])
		|| is_space(game->map[i + 1][j - 1])
		|| is_space(game->map[i + 1][j])
		|| is_space(game->map[i][j + 1]))
		return (1);
	return (0);
}

int	map_border_valid(t_data *game, int len, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j]) == '0')
			{
				if (i == 0 || i == lines)
					return (print_err_msg("parser", "map border not valid"), 1);
				else if (j == 0 || j == len)
					return (print_err_msg("parser", "map border not valid"), 1);
				else if (adjacent_valid(game, i, j))
					return (print_err_msg("parser", "map border not valid"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
