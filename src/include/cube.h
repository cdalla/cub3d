/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 13:46:19 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/01/25 13:41:41 by cdalla-s      ########   odam.nl         */
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

# define PI 3.14159
# define FOV 60
# define WSIZE 1200
# define WEST 0
# define EAST 1
# define NORTH 2
# define SOUTH 3

typedef struct s_map
{
	int			xsize;
	int			ysize;
	double		sq_xsize;
	double		sq_ysize;
	double		sq_size;
	char		**map;
}				t_map;

typedef struct s_ray
{
	double	dirx;
	double	diry;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_dist;
	double	delta_x;
	double	delta_y;
	double	side_distx;
	double	side_disty;
}				t_ray;

typedef struct s_player
{
	double	x;	//player X
	double	y;	//player Y
	double	x2d;
	double	y2d;
	float	ang;	//player starting dir
	double	pdirx; //player direction X
	double	pdiry; //player direction Y
	double	planex;
	double	planey;
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
	double		frametime;
	t_player	pl;
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*minimap;
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

//RENDER UTILS
double	fix_angle(double a);
float	degrees_to_radiant(double a);
void	reset_bg(mlx_image_t *img);

//DIGITAL DIFFERENTIAL ANALYSIS
void	calc_delta_dist(t_ray *ray);
void	calc_init_side_distx_3d(t_data *game, t_ray *ray, int mapx);
void	calc_init_side_disty_3d(t_data *game, t_ray *ray, int mapy);
void	dda(t_data *game, t_ray *ray, int *mapx, int *mapy);

//RENDER DRAW
void	draw_bg2d(t_data *game);
void	draw_pl2d(t_data *game);
void	render3d(t_data *game);
void	render2d(t_data *game);

#endif