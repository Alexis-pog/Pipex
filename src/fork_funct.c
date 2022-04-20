/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:51:44 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/19 17:43:24 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void start(t_split *split)
{
	
	dup2(split->fd_in, STDIN_FILENO);
	dup2(split->pipe[1], STDOUT_FILENO);
	close(split->pipe[0]);
	if (split->boolean != 1)
		close(split->pipe[1]);
}
void finish(t_split *split)
{
	dup2(split->pipe[0], STDIN_FILENO);
	dup2(split->fd_out, STDOUT_FILENO);
	close(split->pipe[1]);
	close(split->fd_in);
}


void closein(t_split *split)
{
	close(split->pipe[1]);
	close(split->fd_in);
}

void closeout(t_split *split)
{
	close(split->fd_out);
	close(split->pipe[0]);
}



















/*
void middle_fork(t_split *split)
{
	if(split->boolean == 1)
	{    
		if(pipe(split->pipe) < 0)
				error_exit("program could not pipe correctly");
		middle(split->pipe,split->pipe2);
		split->boolean = 2;
	}
	else
	{
		if(pipe(split->pipe2) < 0)
				error_exit("program could not pipe correctly");
		middle(split->pipe2,split->pipe);
		split->boolean = 1;
	}
}

void middle(int *pipein, int *pipeout)
{
	if(dup2(pipein[0], STDIN_FILENO) < 0)
		file_void(2);
	if(dup2(pipeout[1], STDOUT_FILENO) < 0)
		file_void(2);
	close(pipein[1]);
	close(pipeout[0]);
}

void last(int *pipein, int *pipein2 ,t_split *split)
{
	if(dup2(pipein[0], STDIN_FILENO) < 0)
		file_void(2);
	if(dup2(split->fd_out, STDOUT_FILENO) < 0)
		file_void(2);
	close(pipein[1]);
	close(pipein2[0]);
	close(pipein2[1]);
	close(split->fd_in);
}
*/