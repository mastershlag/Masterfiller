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
}

int main(int argc, char *argv[])
{
  char ***out;

  printf("------------WELCOME------------\n\n");
  if (argc == 2)
  {
    out = ft_tabloteur(argv[1]);
    ft_contenutab(out);
  }
  else
    printf("tarace\n");
  printf("------------good------------\n");
  return 0;
}
