/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:41:58 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/19 17:19:34 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void file_void(int i)
{
	perror("error");
	exit(i);
}

void empty_file(int fd)
{
	write(1,"the file is empty\n",18);
	close(fd);
	exit(1);
}

void error_name(int i)
{
	write(1,"must be a .txt file\n",20);
	i++;
	exit(1);
}


void wrongly_written(char *cmd)
{
	(void)cmd;	
	write(1,"command not found\n",18);
	// exit(1);
}

void error_exit(char *c)
{
	write(1,c,ft_strlen(c));
	exit(1);
}