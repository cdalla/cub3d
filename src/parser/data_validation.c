/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:03:00 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/20 16:35:06 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int texture_valid(t_data *game)
{
	if (!game->no || !game->so || !game->we || !game->ea)
		return (1); //data empty msg
	else if (access(game->no, R_OK) == -1)
		return (1); //file not exist or read permission denied
	else if (access(game->so, R_OK) == -1)
		return (1); //file not exist or read permission denied
	else if (access(game->we, R_OK) == -1)
		return (1); //file not exist or read permission denied
	else if (access(game->ea, R_OK) == -1)
		return (1); //file not exist or read permission denied
	return (0);
}

int	color_valid(t_data *game)
{
	if (game->f[0] > 255 || game->f[0] < 0 ||
		game->f[1] > 255 || game->f[1] < 0 ||
		game->f[2] > 255 || game->f[2] < 0)
		return (1); //color value not valid
	if (game->c[0] > 255 || game->c[0] < 0 ||
		game->c[1] > 255 || game->c[1] < 0 ||
		game->c[2] > 255 || game->c[2] < 0)
		return (1); //color value not valid
	return (0);
}

int map_border_valid(t_data *game, int len, int lines)
{
	int	i;
	i = 0;
	while(game->map[0][i] && game->map[lines - 1][i])
	{
		if (game->map[0][i] != '1' || game->map[lines - 1][i] != '1')
			return (1); //borders open
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int map_valid(t_data *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr_index("01NSEW", game->map[i][j]) == -1)
				return (1); //invalid symbol in map
			j++;
		}
		i++;
	}
	
	return (0);
}

int	validate_data(t_data *game)
{
	if (/*texture_valid(game) ||*/ color_valid(game) || map_valid(game))
		return (1); //data not valid
	return (0);
}