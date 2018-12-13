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

void    ft_contenutab(char ***out)
{
	int   i;
	int   k;

	printf("\n OUT \n\n");
	i = -1;
	while (out[++i] && (k = -1) < 0)
	{
		while (out[i][++k])
		{
			printf("i = %d, %s : %d\n", i, out[i][k], k);
		}
		printf("-----------------------\n");
	}
	printf("|||||||||||||||||||||||\n\n");
}

int main(int argc, char *argv[])
{
	int i;
	char **mat;
	char ***out;

	i = 2;
	if (argc == 2)
	{
		if (!(out = ft_tabloteur(argv[1])))
		{
			ft_putstr("error\n");
			return (0);
		}
		// ft_contenutab(out);
		mat = init_mat(i);
		while (!(backtrack(mat, i, out, 'A')))
		{
			i++;
			//TO DO: free mat correctement
			mat = init_mat(i);
		}
		print_mat(mat, i);
	}
	else
		ft_putstr("usage: ./fillit [input file]\n");
	return (0);
}
