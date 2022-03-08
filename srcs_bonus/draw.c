/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:18:45 by acolin            #+#    #+#             */
/*   Updated: 2022/03/08 13:12:39 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_sprite(t_cub *c)
{
	int	x;
	int	y;
	int	sx;
	int	sy;

	y = 0;
	sy = HEIGHT - c->map.sprite[c->frame].h - 50;
	while (y < c->map.sprite[c->frame].h)
	{
		x = 0;
		sx = WIDTH / 2 - c->map.sprite[c->frame].w / 2;
		while (x < c->map.sprite[c->frame].w)
		{
			c->buffer[sy * WIDTH + sx] = c->map.sprite[c->frame].buffer[y
				* c->map.sprite[c->frame].w + x];
			sx++;
			x++;
		}
		sy++;
		y++;
	}
}

void	draw_wall(t_cub *c, t_ray *r, int start, int end)
{
	double	step;
	double	texpos;
	int		texy;
	int		texx;

	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	init_data(c, r, &texx);
	step = 1.0 * c->map.wall[r->side].h / r->h;
	texpos = (start - HEIGHT / 2 + r->h / 2) * step;
	while (start < end)
	{
		texy = (int)texpos & (c->map.wall[r->side].h - 1);
		texpos += step;
		c->buffer[start * WIDTH + r->nb] = c->map.wall[r->side].buffer[texy
			* c->map.wall[r->side].w + texx];
		start++;
	}
}

void	draw_door(t_cub *c, t_ray *r, int start, int end)
{
	double	step;
	double	texpos;
	int		texy;
	int		texx;

	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	init_data(c, r, &texx);
	step = 1.0 * c->map.door.h / r->h;
	texpos = (start - HEIGHT / 2 + r->h / 2) * step;
	while (start < end)
	{
		texy = (int)texpos & (c->map.door.h - 1);
		texpos += step;
		c->buffer[start * WIDTH + r->nb] = c->map.door.buffer[texy
			* c->map.door.w + texx];
		start++;
	}
}

void	draw_floor(t_cub *cub)
{
	int	x;
	int	color;
	int	mid;

	mid = WIDTH * HEIGHT / 2 - 1;
	x = HEIGHT * WIDTH - 1;
	color = create_trgb(0, cub->map.floor[0], cub->map.floor[1],
			cub->map.floor[2]);
	while (x >= mid)
		cub->buffer[x--] = color;
	color = create_trgb(0, cub->map.sky[0], cub->map.sky[1], cub->map.sky[2]);
	while (x >= 0)
		cub->buffer[x--] = color;
}

void	draw_texture(t_cub *c, t_ray *r, int start, int end)
{
	if (r->hit == 1)
		draw_wall(c, r, start, end);
	else if (r->hit == 2)
		draw_door(c, r, start, end);
}
