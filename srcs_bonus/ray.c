/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:00:08 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 11:48:22 by lmataris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_hit(char c)
{
	if (c == '1')
		return (1);
	else if (c == 'D')
		return (2);
	else if (c == 'P')
		return (3);
	return (0);
}

void	get_side(t_ray *r, t_map *m)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_x = (m->p.x - r->x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->x - m->p.x + 1.0) * r->delta_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_y = (m->p.y - r->y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->y - m->p.y + 1.0) * r->delta_y;
	}
}

void	init_ray(t_ray *r, t_map *map)
{
	double	c;

	c = 2 * r->nb / (double) WIDTH - 1;
	r->x = (int) map->p.x;
	r->y = (int) map->p.y;
	r->dir_x = map->p.dir_x + map->p.plane_x * c;
	r->dir_y = map->p.dir_y + map->p.plane_y * c;
	if (r->dir_y == 0)
		r->delta_x = 0;
	else if (r->dir_x == 0)
		r->delta_x = 1;
	else
		r->delta_x = fabs(1 / r->dir_x);
	if (r->dir_x == 0)
		r->delta_y = 0;
	else if (r->dir_y == 0)
		r->delta_y = 1;
	else
		r->delta_y = fabs(1 / r->dir_y);
	get_side(r, map);
	r->hit = 0;
	r->side = 0;
	r->dist = 0;
}

void	dda(t_ray *r, t_map *m)
{
	while (r->hit == 0)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->x += r->step_x;
			if (r->step_x == -1)
				r->side = 0;
			else
				r->side = 1;
		}
		else
		{
			r->side_y += r->delta_y;
			r->y += r->step_y;
			if (r->step_y == -1)
				r->side = 2;
			else
				r->side = 3;
		}
		r->hit = check_hit(m->grid[r->y][r->x]);
	}
}

void	raycasting(t_cub *cub)
{
	t_ray	r;
	double	ratio;

	ratio = ((double) WIDTH / (double) HEIGHT) / (4.0 / 3.0);
	r.nb = 0;
	while (r.nb < WIDTH)
	{
		init_ray(&r, &cub->map);
		dda(&r, &cub->map);
		r.dist = (r.x - cub->map.p.x + (1 - r.step_x) / 2) / r.dir_x;
		if (r.side == 0 || r.side == 1)
			r.dist = (r.x - cub->map.p.x + (1 - r.step_x) / 2) / r.dir_x;
		else
			r.dist = (r.y - cub->map.p.y + (1 - r.step_y) / 2) / r.dir_y;
		r.h = (int)((HEIGHT * ratio) / r.dist);
		draw_texture(cub, &r, -r.h / 2 + HEIGHT / 2, r.h / 2 + HEIGHT / 2);
		r.nb++;
	}
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	ft_anime_sprite(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}
