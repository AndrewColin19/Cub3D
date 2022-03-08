/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:58:08 by lmataris          #+#    #+#             */
/*   Updated: 2022/03/03 16:10:19 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*tab;
	unsigned char	*a;
	size_t			n;

	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	a = (unsigned char *) tab;
	n = nmemb * size;
	while (n)
	{
		*a = (unsigned char) 0;
		a++;
		n--;
	}
	return ((void *)tab);
}

static int	ft_overflow(int neg)
{
	if (neg < 0)
		return (0);
	return (-1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{	
	int		neg;
	long	num;

	num = 0;
	neg = 1;
	while (*nptr == ' ' || *nptr == '\n'
		|| *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if ((num * 10 + (*nptr - '0')) / 10 != num)
			return (ft_overflow(neg));
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return (num * neg);
}
