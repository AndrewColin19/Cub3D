/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:50 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/07 16:05:04 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	loop(t_cub *c)
{
	ft_key(c);
	draw_floor(c);
	raycasting(c);
	if (c->fps < 60)
		c->fps++;
	else
		c->fps = 0;
	return (1);
}

void	init_hook(t_cub *c)
{
	mlx_mouse_hide();
	mlx_hook(c->win, 2, 0, ft_key_press, c);
	mlx_hook(c->win, 3, 0, ft_key_release, c);
	mlx_hook(c->win, 6, 0, ft_mouse_event, c);
	mlx_hook(c->win, 17, 0, ft_close, c);
	mlx_loop_hook(c->mlx, loop, c);
}

void	init_mlx(t_cub *cub)
{
	int	x;

	init_player(&cub->map);
	cub->buffer = (int *) mlx_get_data_addr(cub->img, &cub->bpp,
			&cub->sizel, &x);
	init_hook(cub);
	init_sprite(cub);
	draw_floor(cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (aff_error("Usage : ./cub3D <PATH MAP>"));
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "Cub3D");
	cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
	cub.map.door.img = NULL;
	cub.map.sky[0] = -1;
	cub.map.floor[0] = -1;
	cub.anime = 0;
	cub.frame = 0;
	if (check_ext(av[1]) || get_map(av[1], &cub))
		return (1);
	init_mlx(&cub);
	return (0);
}
