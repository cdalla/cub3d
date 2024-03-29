/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 10:38:59 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/06 11:23:13 by lisa          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_err_msg(char *game_part, char *err_msg)
{
	write(2, "Error: ", 7);
	write(2, game_part, ft_strlen(game_part));
	write(2, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
}

void	error(void)
{
	exit(EXIT_FAILURE);
}
