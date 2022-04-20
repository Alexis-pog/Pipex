/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:46:30 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 10:54:32 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void exet_cmd(t_split *split, char **envp)
{
	if (split->index == 2)
	{
		if(pipe(split->pipe) < 0)
			error_exit("program could not pipe correctly");
	}
	split->parent = fork();
	if (split->parent < 0)
		file_void(2);
	if(!split->parent)
		child_process(split, envp);
	else
		parent_process(split);
	if (split->flag_cmd == 0)
		free(split->path);

}

void parent_process(t_split *split)
{
	if (split->index == 2)
		closein(split);
	else if (split->index == split->argc - 2)
		closeout(split);
}
void child_process(t_split *split, char **envp)
{
	if (split->index == 2)
	{
		start(split);
		if (execve(split->path, split->arg ,envp) == -1)
			exit(42);
	}
	else 
	{	
		finish(split);
		if (execve(split->path, split->arg ,envp) == -1)
			exit(42);
	}
}


void verif_path(t_split *split, char **envp, char *cmd)
{
	int j = 0;
	if(access(cmd, F_OK) == -1)
	{
		if(cmd[0] == '/' && access(cmd,F_OK) == -1)	
			wrongly_written(cmd);
		while(strncmp("PATH=",envp[split->i],5) != 0)
			split->i++;
		split->way = ft_split(&envp[split->i][5],':', split);
		while (split->way[j])
			j++;
		split->way[j] = NULL;
		split->tmp1 = ft_strjoin("/",cmd);
		j = 0;
		while(split->way[j])
		{
			split->checker = ft_strjoin(split->way[j], split->tmp1);
			if(access(split->checker, F_OK) == 0)
				break;
			free(split->checker);
			j++;
		}
		if(split->way[j] == NULL)
		{
			wrongly_written(cmd);
			split->boolean = 2;
		}
		split->path = ft_strjoin(split->way[j], split->tmp1);
		free(split->tmp1);
		free(split->checker);
		free_malloc(split->way);
		split->flag_cmd = 0;
	}
	else
	{
		split->flag_cmd = -1;
		split->path = cmd;
	}
}

void	verif_funct(t_verif *verif, char **argv)
{
	if (access(argv[1],F_OK) != 0 || access(argv[1],R_OK) != 0)
			file_void(0);
	verif->fd = open(argv[1],O_RDONLY);
	if (read(verif->fd,verif->s,1) == 0)
		empty_file(verif->fd);
	close(verif->fd);
}

int main(int argc, char **argv, char **envp)
{
	t_verif verif;
	t_split split;
	if (argc == 5)
	{
		init_verit_var(&verif,&split,argc);
		init_in_out(&split,argv);
		verif_funct(&verif, argv);
		while(split.index < argc - 1)
		{
			split.arg = ft_split(argv[split.index],' ', &split);
			if (!split.arg)
				file_void(2);
			verif_path(&split, envp, split.arg[0]);
			exet_cmd(&split,envp);
			free_malloc(split.arg);
			split.index++;
		}
		wait(0);
		wait(0);
	}
	else
		write(1,"missing or too much arguments\n",30);
	return(0);
}
