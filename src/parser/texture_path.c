/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:54:57 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/19 16:37:49 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"


int	is_space(int c);

int	north_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i]))
		{
			while (is_space(file[i][j]))
				j++;
			if (file[i][j])
			{
				game->no = ft_strdup(&file[i][j]);
				if (!game->no)
					return (0); //0 index is error
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i); //if arrives here it is the last line so file[i] == 0
}


int	south_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i]))
		{
			while (is_space(file[i][j]))
				j++;
			if (file[i][j])
			{
				game->so = ft_strdup(&file[i][j]);
				if (!game->so)
					return (0); //0 index is error
				return (i + 1);
			}
		}
		i++;
		j = 0;
	}
	return (i); //if arrives here it is the last line so file[i] == 0
}

int	west_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i]))
		{
			while (is_space(file[i][j]))
				j++;
			if (file[i][j])
			{
				game->we = ft_strdup(&file[i][j]);
				if (!game->we)
					return (0); //0 index is error
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i); //if arrives here it is the last line so file[i] == 0
}

int	east_id(char **file, int i, int j, t_data *game)
{
	while (file[i])
	{
		if (ft_strlen(file[i]))
		{
			while (is_space(file[i][j]))
				j++;
			if (file[i][j])
			{
				game->ea = ft_strdup(&file[i][j]);
				if (!game->ea)
					return (0); //0 index is error
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i); //if arrives here it is the last line so file[i] == 0
}