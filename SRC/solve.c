/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:39:15 by hmoulher          #+#    #+#             */
/*   Updated: 2018/12/13 14:39:20 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headmaster.h"

char		**init_mat(int mat_size)
{
	int i;
	int j;
	char **mat;

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
	int i;
	int j;
	int proceed;
	t_position position;

	i = 0;
	j = 0;
	proceed = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetriminos[i][j] >= 'A' && tetriminos[i][j] <= 'Z')
			{
				position.i = i;
				proceed = 1;
				break;
			}
			j++;
		}
		if (proceed == 1)
			break;
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tetriminos[i][j] >= 'A' && tetriminos[i][j] <= 'Z')
			{
				position.j = j;
				return (position);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (position);
}

void remove_letter(char **mat, int mat_size, char letter)
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

int 	put_tetriminos(char **mat, int mat_size, char **tetriminos, t_position position, char letter, int pos_i, int pos_j)
{
	int i;
	int j;
	int i2;
	int j2;
	int nbr;

	i = pos_i;
	j = pos_j;
	i2 = 0;
	j2 = 0;
	nbr = 0;
	while (i < mat_size && position.i + i2 < 4)
	{
		while (j < mat_size && position.j + j2 < 4)
		{
			if (tetriminos[position.i + i2][position.j + j2] == letter && mat[i][j] == '.')
			{
				mat[i][j] = tetriminos[position.i + i2][position.j + j2];
				nbr++;
				if (nbr == 4)
					return (1);
			}
			j++;
			j2++;
		}
		j = pos_j;
		j2 = 0;
		i++;
		i2++;
	}
	remove_letter(mat, mat_size, letter);
	return (0);
}

void print_mat(char **mat, int mat_size)
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

int backtrack(char **mat, int mat_size, char ***tetrimimos, char letter)
{
	int i;
	int j;
	t_position position;

	i = -1;
	j = -1;
	if (*tetrimimos == 0)
		return (1);
	position = search_tetriminos(*tetrimimos);
	while (++i < mat_size)
	{
		while (++j < mat_size)
		{
			if(mat[i][j] != '.')
				j++;
			if ((put_tetriminos(mat, mat_size, *tetrimimos, position, letter, i, j)))
			{
				if (backtrack(mat, mat_size, tetrimimos + 1, letter + 1))
					return (1);
			}
		}
		j = -1;
	}
	return (0);
}
