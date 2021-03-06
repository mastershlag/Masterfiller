/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headmaster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:24:01 by pharatyk          #+#    #+#             */
/*   Updated: 2018/12/14 14:24:05 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADMASTER_H
# define HEADMASTER_H

# include "libft.h"

typedef struct	s_position
{
	int		i;
	int		j;
	int		i2;
	int		j2;
	char	chr;
}				t_position;

char			***ft_tabloteur(char *file);
void			ft_contenutab(char ***out);
int				backtrack(char **mat, int mat_size,
	char ***tetrimimos, char letter);
char			**init_mat(int mat_size);
void			print_mat(char **mat, int mat_size);
int				ft_minus(int i);
int				ft_plus(int i);
void			print_mat(char **mat, int mat_size);
#endif
