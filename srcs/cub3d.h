/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:29:00 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 13:05:56 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utils/utils.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# define WIDTH 1920
# define HEIGHT 1080
# define M_SPEED 0.09
# define R_SPEED 0.06
# define FOV 0.66
# define DIR 1.

typedef struct s_texture
{
	void	*img;
	int		*buffer;
	int		w;
	int		h;
	int		bpp;
	int		sizel;
	int		endian;
}	t_tex;

typedef struct s_ray
{
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	double	dist;
	int		hit;
	int		side;
	double	wallx;
	int		nb;
	int		h;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move[6];
}	t_player;

typedef struct s_map
{
	char		**grid;
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	int			floor[3];
	int			sky[3];
	t_tex		wall[4];
	int			error;
	t_player	p;
}	t_map;

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	int		*buffer;
	void	*img;
	int		sizel;
	int		bpp;
	t_map	map;
}	t_cub;

/*----------parsing---------*/
int		check_ext(char *file);
int		check_line_param(char **s);
int		get_map(char *file, t_cub *c);
int		check_texture(t_map *m);
int		test_file(char *file);
int		check_map(t_map *map);
int		create_trgb(int t, int r, int g, int b);
int		aff_error(char *msg);
/*----------player----------*/
void	rotate(t_cub *cub, double vitesse);
void	translate(t_cub *cub, double inc_x, double inc_y);
void	init_player(t_map *map);
/*----------drawing---------*/
t_tex	init_t(void *mlx, char *path);
void	init_texture(t_cub *c);
void	draw_floor(t_cub *cub);
void	draw_texture(t_cub *c, t_ray *r, int start, int end);
/*---------raycast----------*/
int		raycasting(t_cub *cub);
/*-----------event----------*/
int		ft_key_press(int key_code, void *param);
int		ft_key_release(int key_code, void *param);
int		ft_key(t_cub *cub);
int		ft_close(void *param);

#endif