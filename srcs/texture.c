/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:47:11 by acolin            #+#    #+#             */
/*   Updated: 2022/03/03 16:55:56 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
