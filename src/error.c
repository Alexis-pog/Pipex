/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: workplace <workplace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:41:58 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/23 12:16:41 by workplace        ###   ########.fr       */
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
	int i;
	i = ft_strlen(cmd);
	write(1,"you wrote : ",13);
	write(1,cmd,i);
	write(1,"\nmaybe try rewriting it\n",25);
	exit(1);
}