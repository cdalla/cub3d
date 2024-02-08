/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:35:03 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/08 20:28:06 by kaltevog      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_id(char **file, int i, int j, t_data *game)
{
	if (!ft_strncmp(&file[i][j], "NO", 2))
		return (north_id(file, i, j + 2, game));
	else if (!ft_strncmp(&file[i][j], "SO", 2))
		return (south_id(file, i, j + 2, game));
	else if (!ft_strncmp(&file[i][j], "WE", 2))
		return (west_id(file, i, j + 2, game));
	else if (!ft_strncmp(&file[i][j], "EA", 2))
		return (east_id(file, i, j + 2, game));
	else if (!ft_strncmp(&file[i][j], "F", 1))
		return (floor_id(file, i, j + 1, game));
	else if (!ft_strncmp(&file[i][j], "C", 1))
		return (ceili_id(file, i, j + 1, game));
	else
		return (map_save(file, i, game));
}

int	fill_data(char **file, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		while (!ft_strlen(file[i]))
			i++;
		j = 0;
		while (is_space(file[i][j]))
			j++;
		i = check_id(file, i, j, game);
		if (!i)
			return (1);
	}
	return (0);
}

int	parser(char *filename, t_data *game)
{
	char	**file_copy;

	if (copy_file(filename, file_size(filename), &file_copy)
		|| fill_data(file_copy, game) || validate_data(game))
	{
		free_file_copy(file_copy);
		return (1);
	}
	free_file_copy(file_copy);
	return (0);
}
