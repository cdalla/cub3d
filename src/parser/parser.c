/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:03 by cdalla-s          #+#    #+#             */
/*   Updated: 2024/01/05 13:40:25 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_file(char **file);//to remove testing purpose

/*
typedef struct s_id
{
	char	*name;
	int		(*fn)(t_data *, char **, int, int)
}				t_id;

	const t_id id[6] = {{"NO", &no_id}, {"SO", &so_id}, {"EA", &ea_id}, {"WE", &we_id},
	{"F", &f_id}, {"C", &c_id}};
*/
// debug purpose - to be removed
void	print_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

//debug purpose - to be removed
void	print_data(t_data *game)
{
	printf("North: %s\n", game->no);
	printf("South: %s\n", game->so);
	printf("West: %s\n", game->we);
	printf("East: %s\n", game->ea);
	printf("Floor: %d, %d, %d\n", game->f[0], game->f[1], game->f[2]);
	printf("Ceiling: %d, %d, %d\n", game->c[0], game->c[1], game->c[2]);
	printf("Map:\n\n");
	print_map(game);
}

//return i = 0 for error
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
	return (0);
}

int	fill_data(char **file, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		while (!ft_strlen(file[i])) //skip empty lines
			i++;
		j = 0;
		while (is_space(file[i][j])) //skip spaces
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
	print_data(game); //test purpose
	free_file_copy(file_copy);
	return (0);
}
