/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:39:15 by hmoulher          #+#    #+#             */
/*   Updated: 2018/12/16 10:44:33 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headmaster.h"

char				**init_mat(int size)
{
	int		i;
	int		j;
	char	**mat;

	i = -1;
	j = -1;
	if (!(mat = (char**)malloc(sizeof(char*) * size + 1)))
		return (0);
	mat[size] = 0;
	while (++i < size)
	{
		if (!(mat[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (0);
		while (++j < size)
			mat[i][j] = '.';
		mat[i][j] = 0;
		j = -1;
	}
	return (mat);
}

static t_position	search_tetriminos(char **tetriminos)
{
	int			i;
	int			j;
	int			check;
	t_position	position;

	i = -1;
	j = -1;
	check = 0;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (tetriminos[i][j] != '.' && check == 0)
			{
				check = 1;
				position.i = i;
				position.j = j;
				position.chr = tetriminos[i][j];
			}
			if (tetriminos[i][j] != '.' && check == 1 && j < position.j)
				position.j = j;
		}
		j = -1;
	}
	return (position);
}

static void			remove_letter(char **mat, int size, char letter)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
			if (mat[i][j] == letter)
				mat[i][j] = '.';
		j = -1;
	}
}

static int			ft_insert(char **mat, int size, char **out, t_position pos)
{
	int j;
	int i2;
	int j2;
	int nbr;

	j = pos.j2 - 1;
	i2 = -1;
	j2 = -1;
	nbr = 0;
	while (pos.i2 < size && pos.i + ++i2 < 4)
	{
		while (++j < size && pos.j + ++j2 < 4)
			if (out[pos.i + i2][pos.j + j2] == pos.chr && mat[pos.i2][j] == '.')
			{
				mat[pos.i2][j] = out[pos.i + i2][pos.j + j2];
				if (++nbr == 4)
					return (1);
			}
		j = pos.j2 - 1;
		j2 = -1;
		pos.i2++;
	}
	return (0);
}

int					backtrack(char **mat, int size, char ***out, char letter)
{
	int			i;
	int			j;
	t_position	position;

	i = -1;
	j = -1;
	if (*out == 0)
		return (1);
	position = search_tetriminos(*out);
	while (++i < size)
	{
		while (++j < size)
		{
			position.i2 = i;
			position.j2 = j;
			if ((ft_insert(mat, size, *out, position)))
				if (backtrack(mat, size, out + 1, letter + 1))
					return (1);
			remove_letter(mat, size, position.chr);
		}
		j = -1;
	}
	return (0);
}
