/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabloteur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:56:25 by pharatyk          #+#    #+#             */
/*   Updated: 2018/12/10 16:56:29 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headmaster.h"

static int	ft_masterchecker(char ***out, int k)
{
	int		i;
	int		j;
	int		cpt;

	k = -1;
	while (out[++k] && (j = -1) < 0)
	{
		cpt = 0;
		while (out[k][++j] && (i = -1) < 0)
			while (out[k][j][++i])
				if (out[k][j][i] != '.')
				{
					if (out[k][ft_minus(j)][i] != '.' && ft_minus(j) != j)
						cpt++;
					if (out[k][ft_plus(j)][i] != '.' && ft_plus(j) != j)
						cpt++;
					if (out[k][j][ft_minus(i)] != '.' && ft_minus(i) != i)
						cpt++;
					if (out[k][j][ft_plus(i)] != '.' && ft_plus(i) != i)
						cpt++;
				}
		if (cpt != 8 && cpt != 6)
			return (0);
	}
	return (1);
}

static int	ft_verif_file(int fd)
{
	int		i;
	int		nb;
	int		ret;
	int		k;
	char	buff[22];

	k = 0;
	while (1)
	{
		i = -1;
		nb = 0;
		ret = read(fd, buff, 21);
		buff[ret] = '\0';
		while (buff[++i] != '\0')
			if (buff[i] == '#')
				nb++;
		if (buff[20] && buff[20] != '\n')
			return (0);
		if (nb != 4 || ret < 20)
			return (0);
		k++;
		if (ret == 20)
			break ;
	}
	return (k);
}

static char	*ft_strmasterdup(const char *s, int k)
{
	char	*s2;
	int		i;

	i = 0;
	if (k > 25)
		return (0);
	while (s[i] != '\0')
		i++;
	if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '.')
			s2[i] = s[i];
		else if (s[i] == '#')
			s2[i] = 'A' + k;
		else
			return (0);
	}
	s2[i] = 0;
	return (s2);
}

static int	ft_tabcreator(char ***out, int fd, char *file, int k)
{
	char	*line;
	int		flag;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	flag = 0;
	k = 0;
	while ((ft_get_next_line(fd, &line)) != 0)
	{
		if (*line)
		{
			if (!(out[k][flag] = ft_strmasterdup(line, k)))
				return (0);
			flag++;
		}
		if (!*line)
		{
			out[k][flag] = 0;
			k++;
			flag = 0;
		}
	}
	close(fd);
	free(line);
	return (1);
}

char		***ft_tabloteur(char *file)
{
	char	***out;
	int		fd;
	int		k;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	if (!(k = ft_verif_file(fd)))
		return (0);
	close(fd);
	if (!(out = (char***)malloc(sizeof(char**) * k + 1)))
		return (0);
	out[k] = 0;
	while (--k > -1)
	{
		if (!(out[k] = (char**)malloc(sizeof(char*) * 5)))
			return (0);
		out[k][4] = 0;
	}
	if (!(ft_tabcreator(out, fd, file, k)))
		return (0);
	if (!(ft_masterchecker(out, k)))
		return (0);
	return (out);
}
