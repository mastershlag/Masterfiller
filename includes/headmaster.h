#ifndef HEADMASTER_H
# define HEADMASTER_H

# include "libft.h"

typedef struct	s_position
{
	int	i;
	int	j;
}				t_position;

char			***ft_tabloteur(char *file);
void			ft_contenutab(char ***out);
int				backtrack(char **mat, int mat_size, char ***tetrimimos, char letter);
char			**init_mat(int mat_size);
void			print_mat(char **mat, int mat_size);
int				ft_minus(int i);
int				ft_plus(int i);
void			print_mat(char **mat, int mat_size);
#endif