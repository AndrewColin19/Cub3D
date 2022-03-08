/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:11 by acolin            #+#    #+#             */
/*   Updated: 2022/03/08 13:10:10 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_tex	init_t(void *mlx, char *path)
{
	t_tex	t;

	if (!test_file(path))
	{
		t.img = mlx_xpm_file_to_image(mlx, path, &t.w, &t.h);
		t.buffer = (int *) mlx_get_data_addr(t.img, &t.bpp, &t.sizel,
				&t.endian);
		return (t);
	}
	else
	{
		t.img = NULL;
		t.buffer = NULL;
		return (t);
	}
}

void	init_sprite(t_cub *c)
{
	c->map.sprite[0] = init_t(c->mlx, "./texture/bras/sp1.xpm");
	c->map.sprite[1] = init_t(c->mlx, "./texture/bras/sp2.xpm");
	c->map.sprite[2] = init_t(c->mlx, "./texture/bras/sp3.xpm");
	c->map.sprite[3] = init_t(c->mlx, "./texture/bras/sp4.xpm");
}
