/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:57:48 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/08 13:11:34 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_ok(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (m->grid[++i])
	{
		j = -1;
		while (m->grid[i][++j])
		{
			if (m->grid[i][j] == 'D' && m->door.img == NULL)
				return (1);
		}
	}
	return (0);
}

int	check_ext(char *file)
{
	if (!ft_strcmp(file + (ft_strlen(file) - 4), ".cub"))
		return (0);
	return (aff_error("Invalid file"));
}

int	check_line_param(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (i >= 3)
		return (1);
	return (0);
}

int	test_file(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (1);
	if (read(fd, &c, 1) <= 0)
		return (1);
	close(fd);
	return (0);
}

int	check_texture(t_map *m)
{
	int	i;
	int	c;

	i = -1;
	while (++i < 4)
	{
		if (m->wall[i].img == NULL)
			return (aff_error("Invalid PATH for wall"));
	}
	c = check_ok(m);
	if (c == 1)
		return (aff_error("Invalid PATH for door"));
	return (0);
}
