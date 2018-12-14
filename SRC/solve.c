/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:39:15 by hmoulher          #+#    #+#             */
/*   Updated: 2018/12/14 14:46:47 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headmaster.h"

char		**init_mat(int mat_size)
{
	int		i;
	int		j;
	char	**mat;

	i = -1;
	j = -1;
	mat = (char**)malloc(sizeof(char*) * mat_size);
	while (++i < mat_size)
	{
		mat[i] = (char*)malloc(sizeof(char) * mat_size);
		while (++j < mat_size)
			mat[i][j] = '.';
		j = -1;
	}
	return (mat);
}

t_position	search_tetriminos(char **tetriminos)
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

void		remove_letter(char **mat, int mat_size, char letter)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < mat_size)
	{
		while (++j < mat_size)
			if (mat[i][j] == letter)
				mat[i][j] = '.';
		j = -1;
	}
}

int			put_tetriminos(char **mat, int size, char **out, t_position pos)
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
	remove_letter(mat, size, pos.chr);
	return (0);
}

int			backtrack(char **mat, int mat_size, char ***tetrimimos, char letter)
{
	int			i;
	int			j;
	t_position	position;

	i = -1;
	j = -1;
	if (*tetrimimos == 0)
		return (1);
	position = search_tetriminos(*tetrimimos);
	while (++i < mat_size)
	{
		while (++j < mat_size)
		{
			if (mat[i][j] != '.')
				j++;
			position.i2 = i;
			position.j2 = j;
			if ((put_tetriminos(mat, mat_size, *tetrimimos, position)))
				if (backtrack(mat, mat_size, tetrimimos + 1, letter + 1))
					return (1);
		}
		j = -1;
	}
	return (0);
}
