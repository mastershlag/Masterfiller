/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:56:36 by pharatyk          #+#    #+#             */
/*   Updated: 2018/12/14 13:56:39 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headmaster.h"

int		ft_minus(int i)
{
	return (i == 0 ? 0 : i - 1);
}

int		ft_plus(int i)
{
	return (i == 3 ? 3 : i + 1);
}

void	print_mat(char **mat, int mat_size)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < mat_size)
	{
		while (++j < mat_size)
			ft_putchar(mat[i][j]);
		ft_putchar('\n');
		j = -1;
	}
}
