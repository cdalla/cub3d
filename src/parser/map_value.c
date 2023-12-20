/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:37:23 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/20 16:31:43 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int map_border_valid(t_data *game, int len, int lines);

int	fill_map(t_data *game, int len, int j, int i)
{
	while (j < len)
	{
		game->map[i][j] = '1';
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
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		game->map[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!game->map[i])
			return (0); //malloc error
		j = 0;
		while (file[i][j])
		{
			if (is_space(file[i][j]))
				game->map[i][j] = '1';
			else
				game->map[i][j] = file[i][j];
			j++;
		}
		if (j < len)
			j = j + fill_map(game, len, j, i);
		game->map[i][j] = '\0';
		i++;
	}
	game->map[i] = 0;
	return (i);
}

int	map_save(char **file, int i, t_data *game)
{
	int	len;
	int	lines;

	map_size(&file[i], &len, &lines);
	game->map = (char **)malloc((lines + 1) * sizeof(char *));
	if (!game->map)
		return (0); //malloc error
	i = i + copy_map(&file[i], game, len);
	if (map_border_valid(game, len, lines))
		return (0); //map borders not valid error msg
	return (i);
}
