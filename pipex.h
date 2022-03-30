#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_verif
{
	int verif_nbr;
	int fd;
	int vrf_lenght;
	char *verif;
	char *s;
} t_verif;

typedef struct s_split
{
	int data;
	char **path;
	char **arg;
	char *a;
	char *tmp1;
	int checker;
	int i;
	int w_count;
	int cmd_count;
	int index;
	int argc;
	int fd[1024];
	int fd_i;
	int fd_in;
	int fd_out;
	int pipe[2];
	char *infile;
	char *outfile;
	pid_t parent;
} t_split;


/*Init var*/
void	init_verit_var(t_verif *verif, t_split *split, int argc);
void	init_in_out(t_split *split, char **argv);

/* HELP VERIF */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *c);
char    *ft_strrchr(const char *s, int c);
/* ERROR */
void 	error_name(int i);
void	empty_file(int fd);
void	file_void(int i);
void 	wrongly_written(char *cmd);

/* useful funct */
void 	verif_path(t_split *split, char **envp, char *cmd);
char	**ft_split(char *s, char c,	t_split *split);
char	**make_a_word(char *s, char c, char **tab, size_t count);
char	*ft_strdup(char *s1);
char	*ft_substr(char  *s, unsigned int start, size_t len);
int		count_word(char *s, char c,t_split *split);
char	**free_malloc(char **tab, int count);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void 	verif_path(t_split *split, char **envp, char *cmd);
void	*ft_memset(void *str, int c, size_t n);
#endif