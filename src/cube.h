/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdalla-s <cdalla-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:46:19 by cdalla-s          #+#    #+#             */
/*   Updated: 2023/12/19 16:42:36 by cdalla-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	*filename;
    char	*no;	//north tex path
    char	*so;	//south tex path
    char	*we;	//west tex path
    char	*ea;	//east tex path
    int		f[3];		//floor tex path
    int		c[3];		//ceiling tex path
    char	**map;	//map values array
}				t_data;


int	parser (char *filename, t_data *game);

int file_size(char *filename);
int copy_file(char *filename, int count, char 	***file_copy);

int	north_id(char **file, int i, int j, t_data *game);
int	south_id(char **file, int i, int j, t_data *game);
int	west_id(char **file, int i, int j, t_data *game);
int	east_id(char **file, int i, int j, t_data *game);

#endif