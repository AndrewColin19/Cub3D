/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:23 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 13:14:19 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
