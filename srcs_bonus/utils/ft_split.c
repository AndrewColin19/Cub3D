/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:53:22 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/03 13:47:29 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			nb_words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb_words);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(n + 1);
	if (!new)
		return (0);
	while (s[i] && i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		i;
	int		j;
	int		k;
	int		nb_words;

	nb_words = count_words(s, c);
	splited = malloc((nb_words + 1) * sizeof(char *));
	if (!splited)
		return (0);
	i = 0;
	k = 0;
	while (k < nb_words)
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		splited[k] = ft_strndup(s + j, i - j);
		k++;
	}
	splited[nb_words] = 0;
	return (splited);
}
