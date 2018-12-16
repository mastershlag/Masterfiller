/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:13:43 by hmoulher          #+#    #+#             */
/*   Updated: 2018/12/06 11:13:46 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headmaster.h"

static void		ft_freetab3(char ***lol)
{
	int		i;
	int		j;

	i = -1;
	while (lol[++i] && (j = -1) < 0)
	{
		while (lol[i][++j])
			free(lol[i][j]);
		free(lol[i]);
	}
	free(lol);
}

static void		ft_freetab2(char **lol)
{
	int		i;

	i = -1;
	while (lol[++i])
		free(lol[i]);
	free(lol);
}

static int		mastermain(int i, char ***out)
{
	char	**mat;

	if (!(mat = init_mat(i)))
	{
		ft_putstr("error\n");
		return (0);
	}
	while (!(backtrack(mat, i, out, 'A')))
	{
		ft_freetab2(mat);
		if (!(mat = init_mat(++i)))
			return (0);
	}
	print_mat(mat, i);
	ft_freetab3(out);
	ft_freetab2(mat);
	return (1);
}

int				main(int argc, char *argv[])
{
	int		i;
	char	***out;

	i = 2;
	if (argc == 2)
	{
		if (!(out = ft_tabloteur(argv[1])))
		{
			ft_putstr("error\n");
			return (0);
		}
		if (!(mastermain(i, out)))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage: ./fillit [input file]\n");
	return (0);
}
