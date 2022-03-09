/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:41:58 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/08 13:32:31 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void file_void()
{
	perror("error");
	exit(0);
}

void empty_file(int fd)
{
	write(1,"the file is empty\n",18);
	close(fd);
	exit(0);
}

void error_name()
{
	write(1,"must be a .txt file\n",20);
	exit(0);
}
