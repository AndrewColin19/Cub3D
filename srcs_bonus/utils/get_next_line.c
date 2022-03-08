/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:21:09 by lmataris          #+#    #+#             */
/*   Updated: 2022/02/24 15:14:33 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_dupcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	dst = ft_calloc(sizeof(char), size);
	if (!dst)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	free(src);
	return (dst);
}

char	*ft_copy(char *out, char *buf)
{
	char	*tmp;
	size_t	size;

	tmp = NULL;
	if (out == NULL)
	{
		out = ft_calloc(sizeof(char), 2);
		ft_strlcat(out, buf, 2);
	}
	else
	{
		size = ft_strlen(out);
		tmp = ft_strdup(out);
		free(out);
		out = ft_dupcpy(out, tmp, size + 2);
		ft_strlcat(out, buf, size + 2);
	}
	return (out);
}

char	*get_next_line(int fd)
{
	char	*out;
	char	buf;

	out = NULL;
	if (fd == -1)
		return (NULL);
	while (read(fd, &buf, 1) > 0)
	{
		out = ft_copy(out, &buf);
		if (buf == '\0')
			return (out);
	}
	return (out);
}
