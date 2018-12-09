#include "libft.h"

// int		

static char	*ft_strmasterdup(const char *s, int k)
{
	char	*s2;
	int		i;

	i = 0;
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
			return 0;
	}
	s2[i] = 0;
	return (s2);
}


static char ***ft_tabloteur(char *file)
{
	char ***out;
	char *line;
	int	fd;
	int k;
	int flag;
	int i = 0;

	k = 0;
	flag = 1;
	if ((fd = open(file, O_RDONLY, S_IRWXU)) <= 0)
		return NULL;
	while ((ft_get_next_line(fd, &line)) != 0)
	{
		printf("%d : %s  ->  ", i, line);
		if (!*line && flag == 1)
			printf("ERROR_FILE\n");
		if (*line)
		{
			if (ft_strlen(line) != 4)
				printf("ERROR_FILE\n");
			if (flag > 5)
				printf("ERROR_FILE\n");
		}
		if (*line && flag != 1)
		{
			flag++;
			printf("flag = %d\n", flag);
		}
		if (*line && flag == 1)
		{
			k++;
			flag++;
			printf("%d \n", k);
		}
		if (!*line)
		{
			flag = 1;
			printf("newline\n");
		}
		i++;
	}
	printf("%d flag = %d\n", k, flag);
	close(fd);
	if (!(out = (char***)malloc(sizeof(char**) * k + 1)))
		return 0;
	out[k] = 0;
	printf("k1 = %d\n", k);
	while (--k > -1)
	{
		printf("\\o/ %d\n", k);
		if (!(out[k] = (char**)malloc(sizeof(char*) * 5)))
			return NULL;
		out[k][4] = 0;
	}
	printf("k = %d\n", k);


	// printf("\n round bonus\n\n");
	// char lol[] = "PAUL";
	// i = -1;
	// while (++i < 4 && (k = -1) < 0)
	// {
	// 	while (++k < 4)
	// 	{
	// 		out[i][k] = ft_strdup(lol);
	// 	}
	// }

	printf("\n round 2\n\n");
	if ((fd = open(file, O_RDONLY, S_IRWXU)) <= 0)
		return NULL;
	i = 0;
	flag = 0;
	k = 0;
	while ((ft_get_next_line(fd, &line)) != 0)
	{
		printf("%d : %s  ->  ", i, line);
		if (*line)
		{
			if (!(out[k][flag] = ft_strmasterdup(line, k)))
			{
				printf("ERROR_FILE\n");
				return 0;
			}
			printf("k = %d flag = %d\n", k, flag);
			flag++;
		}
		if (!*line)
		{
			out[k][flag] = 0;
			printf("k = %d flag = %d\n", k, flag);
			k++;
			flag = 0;
		}
		i++;
	}
	close(fd);


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
	// ft_checker();
	return (out);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		ft_tabloteur(argv[1]);
	else
		printf("tarace\n");
	return 0;
}
