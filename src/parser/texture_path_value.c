/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:54:57 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/22 15:47:36 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	north_id(char **file, int i, int j, t_data *game)
{
	if (game->no)
		return (print_err_msg("parser", "NO doubled"), 0);
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
					return (print_err_msg("parser", "malloc error"), 0);
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i);
}

int	south_id(char **file, int i, int j, t_data *game)
{
	if (game->so)
		return (print_err_msg("parser", "SO doubled"), 0);
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
					return (print_err_msg("parser", "malloc error"), 0);
				return (i + 1);
			}
		}
		i++;
		j = 0;
	}
	return (i);
}

int	west_id(char **file, int i, int j, t_data *game)
{
	if (game->we)
		return (print_err_msg("parser", "WE doubled"), 0);
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
					return (print_err_msg("parser", "malloc error"), 0);
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i);
}

int	east_id(char **file, int i, int j, t_data *game)
{
	if (game->ea)
		return (print_err_msg("parser", "EA doubled"), 0);
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
					return (print_err_msg("parser", "malloc error"), 0);
				return (++i);
			}
		}
		i++;
		j = 0;
	}
	return (i);
}
