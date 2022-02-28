#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct s_verif
{
	int verif_nbr;
	int fd;
	int vrf_lenght;
	char *verif;
	char *s;
} t_verif;


/*Init var*/
void	init_verit_var(t_verif *verif);

/* HELP VERIF */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *c);
char    *ft_strrchr(const char *s, int c);
/* ERROR */
void 	error_name();
void	empty_file(int fd);
void	file_void();

#endif