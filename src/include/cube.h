/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 13:46:19 by cdalla-s      #+#    #+#                 */
/*   Updated: 2024/02/12 13:32:55 by kaltevog      ########   odam.nl         */
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

//change WSIZE to make the windowsize bigger(slower) or smaller(quicker).
# define PI 3.14159
# define WSIZE 600
# define WEST 0
# define EAST 1
# define NORTH 2
# define SOUTH 3
# define TEXWIDTH 32
# define TEXHEIGHT 32

typedef struct s_tex
{
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	tex_pos;
}				t_tex;

typedef struct s_map
{
	int			xsize;
	int			ysize;
	double		sq_mini;
	double		sq_map;
	char		**array;
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
	double	x;
	double	y;
	double	x_map;
	double	y_map;
	double	x_mini;
	double	y_mini;
	double	pdirx;
	double	pdiry;
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
	mlx_image_t	*no_img;
	mlx_image_t	*so_img;
	mlx_image_t	*we_img;
	mlx_image_t	*ea_img;
	int			f[3];
	int			c[3];
	int			ray;
	double		frametime;
	bool		map_show;
	t_player	pl;
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*map2d;
	mlx_image_t	*img3d;
	mlx_image_t	*mini;
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
float	deg_to_rad(double a);
void	reset_img(mlx_image_t *img, int size);
void	reset_bg_mini(t_data *game, mlx_image_t *img);
bool	in_circle(t_data *game, int x, int y, int ray);

//DIGITAL DIFFERENTIAL ANALYSIS
void	calc_wall_dist(t_data *game, int x, t_ray *ray);
void	calc_delta_dist(t_ray *ray);
void	calc_init_side_distx(t_ray *ray, int mapx, double pl_x);
void	calc_init_side_disty(t_ray *ray, int mapy, double pl_y);
void	dda(t_data *game, t_ray *ray, int *mapx, int *mapy);

//RENDER DRAW
void	draw_bg2d(t_data *game);
void	draw_pl2d(t_data *game, mlx_image_t *img, int x, int y);
void	draw_fl_ceil(t_data *game);
void	render3d(t_data *game);
void	render2d(t_data *game);
void	draw_ray_mini(t_data *game, double wallDist, double dirx, double diry);
void	calculate_texture_info(t_data *game, t_ray *ray, t_tex *tex, int start);

#endif