/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:46:19 by cdalla-s          #+#    #+#             */
/*   Updated: 2024/01/05 13:39:11 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	char	*filename;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
}				t_data;

//UTILS
int		is_space(int c);
int		ft_strchr_index(const char *s, int c);
void	print_err_msg(char *game_part, char *err_msg);
void	free_file_copy(char **file);
void	free_data(t_data *game);

//PARSER
int		parser(char *filename, t_data *game);
int		file_size(char *filename);
int		copy_file(char *filename, int count, char ***file_copy);
int		map_save(char **file, int i, t_data *game);
int		validate_data(t_data *game);

//TEXTURE AND MAP VALUES
int		north_id(char **file, int i, int j, t_data *game);
int		south_id(char **file, int i, int j, t_data *game);
int		west_id(char **file, int i, int j, t_data *game);
int		east_id(char **file, int i, int j, t_data *game);
int		floor_id(char **file, int i, int j, t_data *game);
int		ceili_id(char **file, int i, int j, t_data *game);

#endif