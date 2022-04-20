/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:17:42 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 15:08:15 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_in_out(t_split *split, char **argv)
{
	split->infile = argv[1];
	split->outfile = argv[split->argc - 1];
	split->fd_in = open(split->infile, O_RDONLY);
	split->fd_out = open(split->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (split->fd_out < 0)
		file_void(2);
}

void	init_verit_var(t_verif *verif, t_split *split, int argc)
{
	verif->verif_nbr = 0;
	verif->vrf_lenght = 0;
	verif->verif = "";
	verif->s = "";
	verif->fd = 0;
	split->index = 2;
	split->flag_cmd = 0;
	split->i = 0;
	split->way = 0;
	split->argc = argc;
	split->w_count = 0;
	split->cmd_count = 0;
	split->boolean = 1;
	split->j = 0;
}
