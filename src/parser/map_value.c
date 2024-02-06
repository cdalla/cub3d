/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:37:23 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 12:06:00 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	map_border_valid(t_data *game, int len, int lines);

int	fill_map(t_data *game, int len, int j, int i)
{
	while (j < len)
	{
		game->map.array[i][j] = ' ';
		j++;
	}
	return (j);
}

void	map_size(char **file, int *len, int *lines)
{
	*lines = 0;
	*len = ft_strlen(file[*lines]);
	while (file[*lines])
	{
		if ((size_t)(*len) < ft_strlen(file[*lines]))
			*len = ft_strlen(file[*lines]);
		*lines = *lines + 1;
	}
}

int	copy_map(char **file, t_data *game, int len)
{
	int		i;
	int		j;
	char	**map;

	map = game->map.array;
	i = 0;
	while (file[i])
	{
		map[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!map[i])
			return (print_err_msg("parser", "malloc error"), 0);
		j = 0;
		while (file[i][j])
		{
			map[i][j] = file[i][j];
			j++;
		}
		if (j < len)
			j = j + fill_map(game, len, j, i);
		map[i][len] = '\0';
		i++;
	}
	map[i] = 0;
	return (i);
}

int	map_save(char **file, int i, t_data *game)
{
	map_size(&file[i], &game->map.xsize, &game->map.ysize);
	game->map.array = (char **)malloc((game->map.xsize + 1) * sizeof(char *));
	if (!game->map.array)
		return (print_err_msg("parser", "malloc error"), 0);
	i = i + copy_map(&file[i], game, game->map.xsize);
	if (map_border_valid(game, game->map.xsize, game->map.ysize))
		return (0);
	return (i);
}
