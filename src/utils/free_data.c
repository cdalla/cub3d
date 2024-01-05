/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:56:33 by cdalla-s          #+#    #+#             */
/*   Updated: 2024/01/05 13:39:33 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_file_copy(char **file)
{
	int	i;

	i = 0;
	if (file)
	{
		while (file[i])
		{
			if (file[i])
				free(file[i]);
			i++;
		}
		free(file);
	}
}

void	free_data(t_data *game)
{
	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	if (game->ea)
		free(game->ea);
	free_file_copy(game->map);
}
