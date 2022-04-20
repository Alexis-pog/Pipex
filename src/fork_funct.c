/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:51:44 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 11:02:02 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	start(t_split *split)
{
	dup2(split->fd_in, STDIN_FILENO);
	dup2(split->pipe[1], STDOUT_FILENO);
	close(split->pipe[0]);
	if (split->boolean != 1)
		close(split->pipe[1]);
}

void	finish(t_split *split)
{
	dup2(split->pipe[0], STDIN_FILENO);
	dup2(split->fd_out, STDOUT_FILENO);
	close(split->pipe[1]);
	close(split->fd_in);
}

void	closein(t_split *split)
{
	close(split->pipe[1]);
	close(split->fd_in);
}

void	closeout(t_split *split)
{
	close(split->fd_out);
	close(split->pipe[0]);
}
