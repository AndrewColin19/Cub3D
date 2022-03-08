/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:02:37 by acolin            #+#    #+#             */
/*   Updated: 2022/03/07 17:33:37 by lmataris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_anime_sprite(t_cub *c)
{
	if (c->anime)
	{
		draw_sprite(c);
		if (c->fps % 6 == 0)
			c->frame++;
		if (c->frame == 4)
		{
			c->frame = 0;
			c->anime = 0;
		}
	}
}

int	ft_mouse_event(int x, int y, void *param)
{
	t_cub	*cub;

	(void) y;
	cub = (t_cub *) param;
	if (x < WIDTH / 2)
		rotate(cub, R_SPEED);
	else if (x > WIDTH / 2)
		rotate(cub, -R_SPEED);
	mlx_mouse_move(cub->win, WIDTH / 2, HEIGHT / 2);
	return (1);
}

int	ft_close(void *param)
{
	(void) param;
	exit(0);
}
