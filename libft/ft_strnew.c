/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:47:50 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/13 10:47:51 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;

	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(out, '\0', size + 1);
	return (out);
}
