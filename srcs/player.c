/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:38:49 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 12:56:45 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	set_fov_dir(char c, int mod)
{
	if (mod)
	{
		if (c == 'N' || c == 'E')
			return (FOV);
		return (-FOV);
	}
	if (c == 'W' || c == 'N')
		return (-DIR);
	return (DIR);
}

void	rotate(t_cub *cub, double vitesse)
{
	double	dirx;
	double	planex;

	dirx = cub->map.p.dir_x;
	planex = cub->map.p.plane_x;
	cub->map.p.dir_x = cub->map.p.dir_x * cos(vitesse)
		- cub->map.p.dir_y * sin(-vitesse);
	cub->map.p.dir_y = dirx * sin(-vitesse)
		+ cub->map.p.dir_y * cos(-vitesse);
	cub->map.p.plane_x = cub->map.p.plane_x * cos(-vitesse)
		- cub->map.p.plane_y * sin(-vitesse);
	cub->map.p.plane_y = planex * sin(-vitesse)
		+ cub->map.p.plane_y * cos(-vitesse);
}

void	translate(t_cub *cub, double inc_x, double inc_y)
{
	if (cub->map.grid[(int)cub->map.p.y][(int)(cub->map.p.x + inc_x)] != '1')
		cub->map.p.x += inc_x;
	if (cub->map.grid[(int)(cub->map.p.y + inc_y)][(int)cub->map.p.x] != '1')
		cub->map.p.y += inc_y;
}

void	init_play_coor(t_map *map, int x, int y, char c)
{
	map->p.x = x + 0.5;
	map->p.y = y + 0.5;
	if (c == 'N' || c == 'S')
	{
		map->p.dir_x = 0.;
		map->p.dir_y = set_fov_dir(c, 0);
		map->p.plane_x = set_fov_dir(c, 1);
		map->p.plane_y = 0.;
	}
	else if (c == 'E' || c == 'W')
	{
		map->p.dir_x = set_fov_dir(c, 0);
		map->p.dir_y = 0.;
		map->p.plane_x = 0.;
		map->p.plane_y = set_fov_dir(c, 1);
	}
}

void	init_player(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			c = map->grid[i][j];
			if (c == 'N' || c == 'S'
				|| c == 'W' || c == 'E')
				init_play_coor(map, j, i, c);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 6)
		map->p.move[i++] = 0;
}
