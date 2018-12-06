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

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int verif_file(int fd)
{
  int i;
  int nb;
  int ret;
  char buff[21];

  while(1)
  {
    i = -1;
    nb = 0;
    ret = read(fd, buff, 21);
    buff[ret] = '\0';
    while (buff[++i] != '\0')
      if (buff[i] == '#')
      {
        if(buff[i - 1] == '.' && buff[i + 1] == '.' &&
          buff[i - 5] == '.' && buff[i + 5] == '.')
          return (0);
        nb++;
      }
    if(nb != 4 || ret < 20)
      return (0);
    if(ret == 20)
      break ;
  }
  return (1);
}

int main(int argc, char const *argv[])
{
  int fd;

  if (argc == 2)
  {
    fd = open(argv[1], O_RDONLY);
    if(!(verif_file(fd)))
      printf("nope\n");
    else
      printf("ok\n");
  }
  return (0);
}
