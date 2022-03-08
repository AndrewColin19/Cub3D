/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:53:28 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/07 13:18:13 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	coucou(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	get_color(t_map *m, int *c, char *s)
{
	char	**splited;
	int		i;

	if (c[0] != -1)
	{
		m->error = aff_error("Double color");
		return ;
	}
	splited = ft_split(s, ',');
	i = 0;
	while (splited[i])
	{
		if (i < 3)
		{
			c[i] = ft_atoi(splited[i]);
			if (c[i] < 0 || c[i] > 255)
				m->error = aff_error("Invalid color");
		}
		i++;
	}
	coucou(splited);
	if (i != 3 && !m->error)
		m->error = aff_error("Invalid format");
}

int	set_param(char **splited, t_cub *c)
{
	if (!ft_strcmp(splited[0], "NO") && !c->map.wall[0].img)
		c->map.wall[0] = init_t(c->mlx, splited[1]);
	else if (!ft_strcmp(splited[0], "EA") && !c->map.wall[1].img)
		c->map.wall[1] = init_t(c->mlx, splited[1]);
	else if (!ft_strcmp(splited[0], "WE") && !c->map.wall[2].img)
		c->map.wall[2] = init_t(c->mlx, splited[1]);
	else if (!ft_strcmp(splited[0], "SO") && !c->map.wall[3].img)
		c->map.wall[3] = init_t(c->mlx, splited[1]);
	else if (!ft_strcmp(splited[0], "DO") && !c->map.door.img)
		c->map.door = init_t(c->mlx, splited[1]);
	else if (!ft_strcmp(splited[0], "C"))
		get_color(&c->map, c->map.sky, splited[1]);
	else if (!ft_strcmp(splited[0], "F"))
		get_color(&c->map, c->map.floor, splited[1]);
	else
	{
		coucou(splited);
		return (1);
	}
	coucou(splited);
	return (0);
}

void	get_line(char **s, t_cub *c)
{
	int		i;
	int		j;
	char	**splited;

	i = 0;
	splited = ft_split(s[i], ' ');
	while (!check_line_param(splited) && !set_param(splited, c))
	{
		i++;
		splited = ft_split(s[i], ' ');
	}
	if (i < 6)
		c->map.error = aff_error("Invalid format");
	j = i;
	while (s[i])
		i++;
	c->map.grid = malloc(sizeof(char *) * (i - j + 1));
	i = j;
	j = 0;
	while (s[i])
		c->map.grid[j++] = ft_strdup(s[i++]);
	c->map.grid[j] = NULL;
	coucou(s);
}

int	get_map(char *file, t_cub *c)
{
	int		fd;
	char	*s;
	char	**splited;

	c->map.error = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (aff_error("Invalid file"));
	s = get_next_line(fd);
	if (!s)
		return (aff_error("Empty file"));
	splited = ft_split(s, '\n');
	get_line(splited, c);
	if (c->map.error || check_map(&c->map) || check_texture(&c->map))
		return (1);
	return (0);
}
