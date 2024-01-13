/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 13:46:19 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/13 12:14:15 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include "../../mlx/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

#define PI 3.14159
#define FOV 60

typedef	struct s_map
{
	int		xsize;
	int		ysize;
	int		sq_xsize;
	int		sq_ysize;
	int		sq_size;
	char	**map;
}				t_map;

typedef struct s_player
{
	double	x;	//player X
	double	y;	//player Y
	double	x2D;
	double	y2D;
	float	ang;	//player starting dir
	double	pdirx; //player direction X
	double	pdiry; //player direction Y
	int		size;
}				t_player;

typedef struct s_data
{
	char		*filename;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	t_player	pl;
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t *img;
	mlx_image_t *minimap;
}				t_data;

#define wsize 800
#define mapX  8      //map width
#define mapY  8      //map height

extern int maptest[8][8];




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

//RENDER UTILS
int fixAngle(int a);
float degreesToRadiant(int a);
void resetBg(mlx_image_t *img);

//RENDER DRAW
void drawBg2D(t_data *game);
void drawPl2D(t_data *game);
void render3D(t_data *game);
void render2D(t_data *game);

#endif