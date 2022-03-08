/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:02:37 by acolin            #+#    #+#             */
/*   Updated: 2022/03/03 15:24:51 by lmataris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key_code, void *param)
{
	t_cub	*cub;

	cub = (t_cub *) param;
	if (key_code == 124)
		cub->map.p.move[0] = 1;
	else if (key_code == 123)
		cub->map.p.move[1] = 1;
	else if (key_code == 13)
		cub->map.p.move[2] = 1;
	else if (key_code == 1)
		cub->map.p.move[3] = 1;
	else if (key_code == 2)
		cub->map.p.move[4] = 1;
	else if (key_code == 0)
		cub->map.p.move[5] = 1;
	else if (key_code == 53)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	ft_key_release(int key_code, void *param)
{
	t_cub	*cub;

	cub = (t_cub *) param;
	if (key_code == 124)
		cub->map.p.move[0] = 0;
	else if (key_code == 123)
		cub->map.p.move[1] = 0;
	else if (key_code == 13)
		cub->map.p.move[2] = 0;
	else if (key_code == 1)
		cub->map.p.move[3] = 0;
	else if (key_code == 2)
		cub->map.p.move[4] = 0;
	else if (key_code == 0)
		cub->map.p.move[5] = 0;
	return (1);
}

int	ft_key(t_cub *cub)
{
	if (cub->map.p.move[0] == 1)
		rotate(cub, -R_SPEED);
	if (cub->map.p.move[1] == 1)
		rotate(cub, R_SPEED);
	if (cub->map.p.move[2] == 1)
		translate(cub, cub->map.p.dir_x * M_SPEED, cub->map.p.dir_y * M_SPEED);
	if (cub->map.p.move[3] == 1)
		translate(cub, cub->map.p.dir_x * -M_SPEED,
			cub->map.p.dir_y * -M_SPEED);
	if (cub->map.p.move[4] == 1)
		translate(cub, cub->map.p.plane_x * M_SPEED,
			cub->map.p.plane_y * M_SPEED);
	if (cub->map.p.move[5] == 1)
		translate(cub, cub->map.p.plane_x * -M_SPEED,
			cub->map.p.plane_y * -M_SPEED);
	return (1);
}

int	ft_close(void *param)
{
	(void) param;
	exit(0);
}
