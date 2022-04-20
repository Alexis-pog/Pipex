/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:26:03 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 13:26:59 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	loop_find_path(t_split *split)
{
	while (split->way[split->j])
	{
		split->checker = ft_strjoin(split->way[split->j], split->tmp1);
		if (access(split->checker, F_OK) == 0)
			break ;
		free(split->checker);
		split->j++;
	}
}

void	specific_free_plus_flag(t_split *split)
{
	free(split->tmp1);
	if (split->way[split->j] != NULL)
		free(split->checker);
	free_malloc(split->way);
	split->flag_cmd = 0;
}

void	error_way(t_split *split)
{
	char	*cmd;

	cmd = "a";
	wrongly_written(cmd);
	split->boolean = 2;
}

void	else_verif_path(t_split *split, char *cmd)
{
	split->flag_cmd = -1;
	split->path = cmd;
}

void	verif_funct(t_verif *verif, char **argv)
{
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
		file_void(0);
	verif->fd = open(argv[1], O_RDONLY);
	if (read(verif->fd, verif->s, 1) == 0)
		empty_file(verif->fd);
	close(verif->fd);
}
