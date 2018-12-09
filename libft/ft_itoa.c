/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:42:49 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/13 10:42:52 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg(int *n, int *isneg)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*isneg = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*out;
	int		cpn;
	int		len;
	int		isneg;

	cpn = n;
	len = 2;
	isneg = 0;
	ft_neg(&n, &isneg);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (cpn /= 10)
		len++;
	len = (len + isneg);
	if (!(out = (char *)malloc(sizeof(char) * len)))
		return (0);
	out[--len] = 0;
	while (len-- > 0)
	{
		out[len] = n % 10 + '0';
		n = n / 10;
	}
	if (isneg == 1)
		out[0] = '-';
	return (out);
}
