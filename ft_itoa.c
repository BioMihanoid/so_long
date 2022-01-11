/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmilan <gmilan@.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:41:38 by gmilan            #+#    #+#             */
/*   Updated: 2022/01/11 17:15:38 by gmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_min(int *n)
{
	if (*n == INT_MIN)
	{
		*n = -INT_MAX;
		return (1);
	}
	return (0);
}

static size_t	ft_len_nbr(int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	ft_check_sign_and_zero_neg(int *n)
{
	if (*n < 0 && *n != -0)
	{
		*n = -*n;
		return ('-');
	}
	return ('0');
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	l;
	size_t	len;
	int		fix_int_min;

	fix_int_min = ft_check_min(&n);
	len = ft_len_nbr(n);
	s = (char *) malloc(len + 1);
	if (!s)
		return (NULL);
	s[0] = ft_check_sign_and_zero_neg(&n);
	l = len;
	s[len] = '\0';
	while (n)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (fix_int_min)
		s[l - 1] = '8';
	return (s);
}
