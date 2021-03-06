/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:29:04 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 14:06:42 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_verif
{
	int		verif_nbr;
	int		fd;
	int		vrf_lenght;
	char	*verif;
	char	*s;
}	t_verif;

typedef struct s_split
{
	int		data;
	char	**way;
	char	**arg;
	char	*path;
	char	*tmp1;
	char	*checker;
	int		i;
	int		w_count;
	int		cmd_count;
	int		index;
	int		argc;
	int		j;
	int		flag_cmd;
	int		fd_in;
	int		fd_out;
	int		pipe[2];
	int		boolean;
	char	*infile;
	char	*outfile;
	pid_t	parent;
}	t_split;

/*Init var*/
void	init_verit_var(t_verif *verif, t_split *split, int argc);
void	init_in_out(t_split *split, char **argv);
/* HELP VERIF */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *c);
char	*ft_strrchr(const char *s, int c);
/* ERROR */
void	error_name(int i);
void	empty_file(int fd);
void	file_void(int i);
void	error_exit(char *c);
void	wrongly_written(char *cmd);
void	error_way(t_split *split);

/* FREE */
void	specific_free_plus_flag(t_split *split);
char	**free_malloc(char **tab);

/* useful funct */
int		count_word(char *s, char c, t_split *split);
void	verif_path(t_split *split, char **envp, char *cmd);
void	verif_path(t_split *split, char **envp, char *cmd);
void	else_verif_path(t_split *split, char *cmd);
void	loop_find_path(t_split *split);
void	verif_funct(t_verif *verif, char **argv);
char	**ft_split(char *s, char c,	t_split *split);
char	**make_a_word(char *s, char c, char **tab, size_t count);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

/* process related */
void	exet_cmd(t_split *split, char **envp);
void	start(t_split *split);
void	finish(t_split *split);
void	closein(t_split *split);
void	closeout(t_split *split);
void	parent_process(t_split *split);
void	child_process(t_split *split, char **envp);
#endif