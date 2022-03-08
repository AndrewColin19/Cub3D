/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:29:00 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 12:31:19 by lmataris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define MM_COLOR_WALL 0x000000
# define MM_COLOR_BACK 0xE0CDA9
# define MM_PLAYER 0xA286D3
# define MM_X 1650
# define MM_Y 20
# define MM_SIZE 10
# define MM_S 25
# define MM_FOG 5

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
	int			floor[3];
	int			sky[3];
	t_tex		wall[4];
	t_tex		door;
	t_tex		sprite[4];
	int			op_door;
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
	int		fps;
	int		anime;
	int		frame;
	t_map	map;
}	t_cub;

/*----------parsing---------*/
int		check_ext(char *file);
int		check_line_param(char **s);
int		get_map(char *file, t_cub *c);
int		check_map(t_map *map);
int		aff_error(char *err);
/*----------player----------*/
void	rotate(t_cub *cub, double vitesse);
void	translate(t_cub *cub, double inc_x, double inc_y);
void	init_player(t_map *map);
int		player_use_door(int dir, t_cub *c, char a, char b);
int		player_view(t_player *p);
/*----------drawing---------*/
void	init_sprite(t_cub *c);
int		test_file(char *path);
t_tex	init_t(void *mlx, char *path);
int		create_trgb(int t, int r, int g, int b);
int		check_texture(t_map *m);
void	init_data(t_cub *c, t_ray *r, int *texx);
void	draw_floor(t_cub *cub);
void	draw_texture(t_cub *c, t_ray *r, int start, int end);
void	draw_sprite(t_cub *c);
void	draw_minimap(t_cub *c);
void	ft_anime_sprite(t_cub *c);
/*---------raycast----------*/
void	raycasting(t_cub *cub);
/*-----------event----------*/
int		ft_key_press(int key_code, void *param);
int		ft_key_release(int key_code, void *param);
int		ft_key(t_cub *cub);
int		ft_mouse_event(int x, int y, void *param);
int		ft_close(void *param);
/*------------mlx-----------*/
int		mlx_mouse_hide(void);
int		mlx_mouse_move(void *win_ptr, int x, int y);

#endif