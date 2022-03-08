/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:46:53 by acolin            #+#    #+#             */
/*   Updated: 2022/03/08 13:12:05 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_key_action(int key_code, t_cub *cub)
{
	if (key_code == 53)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		exit(EXIT_SUCCESS);
	}
	else if (key_code == 14)
	{
		if (player_use_door(player_view(&cub->map.p), cub, 'D', 'O'))
			return (1);
		if (player_use_door(player_view(&cub->map.p), cub, 'O', 'D'))
			return (1);
	}
	else if (key_code == 49)
		if (cub->map.sprite[0].img && cub->map.sprite[1].img
			&& cub->map.sprite[2].img && cub->map.sprite[3].img)
				cub->anime = 1;
	return (1);
}

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
	ft_key_action(key_code, cub);
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
