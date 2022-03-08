/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:50 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 13:13:57 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_cub	*cub)
{
	ft_key(cub);
	draw_floor(cub);
	raycasting(cub);
	return (1);
}

void	init_mlx(t_cub	*cub)
{
	int	x;

	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->buffer = (int *) mlx_get_data_addr(cub->img, &cub->bpp,
			&cub->sizel, &x);
	init_player(&cub->map);
	mlx_hook(cub->win, 2, 0, ft_key_press, cub);
	mlx_hook(cub->win, 3, 0, ft_key_release, cub);
	mlx_hook(cub->win, 17, 0, ft_close, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (aff_error("Usage : ./cub3D <PATH MAP>"));
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "Cub3D");
	cub.map.wall[0].img = NULL;
	cub.map.wall[1].img = NULL;
	cub.map.wall[2].img = NULL;
	cub.map.wall[3].img = NULL;
	cub.map.sky[0] = -1;
	cub.map.floor[0] = -1;
	if (check_ext(av[1]) || get_map(av[1], &cub))
		return (1);
	init_mlx(&cub);
	return (0);
}
