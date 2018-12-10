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

#include "../includes/headmaster.h"

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
