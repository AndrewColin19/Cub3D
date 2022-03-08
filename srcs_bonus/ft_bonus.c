/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:15:29 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/07 17:16:14 by lmataris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_pix(t_cub *c, int color, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < MM_S)
	{
		j = 0;
		while (j < MM_S)
		{
			c->buffer[(y + i) * WIDTH + x + j] = color;
			j++;
		}
		i++;
	}
}

int	choose_color(char c, int v, int b)
{
	if (b)
	{
		if (c == '1' || c == ' ')
			return (MM_COLOR_WALL);
		if (c == 'D' || c == 'O')
			return (0x89a8ff);
		else
			return (MM_COLOR_BACK);
	}
	else
	{
		if (v < 0)
			return (0);
		else
			return (v);
	}
}

int	fill_void_i(t_cub *c, int x)
{
	int		ii;
	int		jj;

	ii = 0;
	while (x < 0)
	{
		jj = 0;
		while (jj < 10)
			draw_pix(c, MM_COLOR_WALL,
				MM_X + (MM_S * ii), MM_Y + (MM_S * jj++));
		x++;
		ii++;
	}
	return (ii);
}

int	fill_void_j(t_cub *c, int x)
{
	int		ii;
	int		jj;

	jj = 0;
	while (x < 0)
	{
		ii = 0;
		while (ii < 10)
			draw_pix(c, MM_COLOR_WALL,
				MM_X + (MM_S * ii++), MM_Y + (MM_S * jj));
		x++;
		jj++;
	}
	return (jj);
}

void	draw_minimap(t_cub *c)
{
	int	i;
	int	j;
	int	ii;
	int	jj;

	j = (int)c->map.p.y - MM_FOG;
	jj = fill_void_j(c, j);
	j = choose_color(0, j, 0);
	while (jj < MM_SIZE)
	{
		i = (int)c->map.p.x - MM_FOG;
		ii = fill_void_i(c, i);
		i = choose_color(0, i, 0);
		while (ii < MM_SIZE)
		{
			draw_pix(c, choose_color(c->map.grid[j][i], 0, 1),
				MM_X + (MM_S * ii++), MM_Y + (MM_S * jj));
			if (c->map.grid[j][i + 1] != '\0')
				i++;
		}
		if (c->map.grid[j + 1] != NULL)
			j++;
		jj++;
	}
	draw_pix(c, MM_PLAYER, MM_X + (MM_S * 5), MM_Y + (MM_S * 5));
}
