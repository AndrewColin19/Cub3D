/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:23 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/02 16:00:15 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	change_door(t_map *map, int y, int x, char c)
{
	map->grid[y][x] = c;
	return (1);
}

void	init_data(t_cub *c, t_ray *r, int *texx)
{
	if (r->side <= 1)
		r->wallx = c->map.p.y + r->dist * r->dir_y;
	else
		r->wallx = c->map.p.x + r->dist * r->dir_x;
	r->wallx -= floor((r->wallx));
	*texx = (int)(r->wallx * (double)c->map.wall[r->side].w);
	if (r->side <= 1 && c->map.p.dir_x > 0)
		*texx = c->map.wall[r->side].w - *texx - 1;
	if (r->side > 1 && c->map.p.dir_y < 0)
		*texx = c->map.wall[r->side].w - *texx - 1;
}

int	player_use_door(int dir, t_cub *c, char a, char b)
{
	if (dir == 2)
		if (c->map.grid[(int)c->map.p.y][(int)c->map.p.x + 1] == a)
			return (change_door(&c->map, (int)c->map.p.y,
					(int)c->map.p.x + 1, b));
	if (dir == 4)
		if (c->map.grid[(int)c->map.p.y][(int)c->map.p.x - 1] == a)
			return (change_door(&c->map, (int)c->map.p.y,
					(int)c->map.p.x - 1, b));
	if (dir == 3)
		if (c->map.grid[(int)c->map.p.y + 1][(int)c->map.p.x] == a)
			return (change_door(&c->map, (int)c->map.p.y + 1,
					(int)c->map.p.x, b));
	if (dir == 1)
		if (c->map.grid[(int)c->map.p.y - 1][(int)c->map.p.x] == a)
			return (change_door(&c->map, (int)c->map.p.y - 1,
					(int)c->map.p.x, b));
	return (0);
}

int	player_view(t_player *p)
{
	double	x;

	x = 1 / sqrt(2);
	if (p->dir_y < -x)
		return (1);
	else if (p->dir_y > x)
		return (3);
	else if (p->dir_x > x)
		return (2);
	else if (p->dir_x < -x)
		return (4);
	return (0);
}
