/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmataris <lmataris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:19:08 by acolin            #+#    #+#             */
/*   Updated: 2022/03/07 18:07:41 by lmataris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	aff_error(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	return (1);
}

int	check_zero(t_map *map, int i, int j)
{
	if (i == 0 && map->grid[i][j] == '0')
		return (1);
	if (map->grid[i - 1][j] == ' ' || i == 0 || map->grid[i - 1][j] == '\0'
		|| (int)ft_strlen(map->grid[i - 1]) < j)
		return (1);
	if (map->grid[i][j + 1] == ' ' || map->grid[i][j + 1] == '\0')
		return (1);
	if (map->grid[i][j - 1] == ' ' || j == 0)
		return (1);
	if (map->grid[i + 1] != NULL)
	{
		if (map->grid[i + 1][j] == ' ' || map->grid[i + 1][j] == '\0'
			|| (int)ft_strlen(map->grid[i + 1]) < j)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	check_player(char c, int *p)
{
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
	{
		if (*p == 1)
			return (1);
		*p = 1;
		return (0);
	}
	return (0);
}

int	check_char(char c)
{
	if (c != '0' && c != '1')
	{
		if (c != 'N' && c != 'S'
			&& c != 'W' && c != 'E'
			&& c != ' ')
			return (1);
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map->grid[i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (check_char(map->grid[i][j]))
				return (aff_error("Invalid character"));
			else if (check_player(map->grid[i][j], &player))
				return (aff_error("Invalid number of player"));
			else if (map->grid[i][j] == '0')
				if (check_zero(map, i, j))
					return (aff_error("Map not closed"));
		}
		i++;
	}
	if (!player)
		return (aff_error("No player"));
	return (0);
}
