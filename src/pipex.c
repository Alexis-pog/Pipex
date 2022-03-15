/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:46:30 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/15 19:52:58 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void exet_cmd(char *path,char *arg, t_split *split)
{

}


void verif_path(t_split *split, char **envp, char *cmd)
{
	int j = 0;
	split->i = 0;
	split->a = 0;
	if(cmd[0] == '/' && access(cmd,F_OK) == -1)
		wrongly_written(cmd);
	while(strncmp("PATH=",envp[split->i],5) != 0)
		split->i++;
	split->path = ft_split(&envp[split->i][5],':', split);
	while (split->path[j])
		j++;
	split->path[j] = NULL;
	split->tmp1 = ft_strjoin("/",cmd);
	j = 0;
	while(split->path[j])
	{
		split->checker = access(ft_strjoin(split->path[j], split->tmp1), F_OK);
		if(access(ft_strjoin(split->path[j], split->tmp1), F_OK) == 0)
			break;
		j++;
	}
	if(split->path[j] == NULL)
		wrongly_written(cmd);
	split->a = ft_strjoin(split->path[j], split->tmp1);
	free(split->tmp1);
	printf("\n%s\n",split->a);
	free_malloc(split->path,split->w_count);
	if(access(cmd, F_OK) == 0)
		printf("OK");
	printf("DONE");
}

int main(int argc, char **argv, char **envp)
{
	t_verif verif;
	t_split split;
	int i;

	split.index2 = 2;
	init_verit_var(&verif);
	if (argc > 1)
	{
		if (access(argv[1],F_OK) != 0 || access(argv[1],R_OK) != 0)
			file_void(1);
		verif.verif = ft_strrchr(argv[1], '.');
		verif.vrf_lenght = ft_strlen(verif.verif);
		if (verif.vrf_lenght != 4)
			error_name(1);
		if (ft_strncmp(verif.verif,".txt",verif.vrf_lenght) != 0)
			error_name(1);
		verif.fd = open(argv[1],O_RDONLY);
		if (read(verif.fd,verif.s,1) == 0)
			empty_file(verif.fd);
		printf("%d\n",verif.verif_nbr);
		printf("%s\n",argv[2]);
		while(split.index2 > argc - 2)
		{
			split.arg = ft_split(argv[i],' ', &split);
			split.cmd_count = split.w_count;
			verif_path(&split, envp, split.arg[0]);
			
			free_malloc(split.arg, split.cmd_count);
			split.index2++;
		}
	}
	else
		write(1,"missing arguments\n",18);
	return(0);
}
