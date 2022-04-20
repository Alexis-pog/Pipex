/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:41:58 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 15:02:17 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	file_void(int i)
{
	perror ("error");
	exit (WEXITSTATUS(i));
}

void	empty_file(int fd)
{
	int	i;

	write (1, "the file is empty\n", 18);
	close (fd);
	exit (WEXITSTATUS(i));
}

void	error_name(int i)
{
	write (1, "must be a .txt file\n", 20);
	i++;
	exit (WEXITSTATUS(i));
}

void	wrongly_written(char *cmd)
{
	(void)cmd;
	write (1, "command not found\n", 18);
}

void	error_exit(char *c)
{
	int	i;

	write (1, c, ft_strlen(c));
	exit (WEXITSTATUS(i));
}
