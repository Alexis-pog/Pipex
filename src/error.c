/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:41:58 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/28 16:55:48 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void file_void()
{
	write(1,"ERROR\n",6);
	write(1,"--> the file does not exist\n",28);
	write(1,"<<OR>>\n", 7);
	write(1,"--> you have misspelled the name\n",34);
	write(1,"<<OR>>\n", 7);
	write(1,"--> you do not have the permission to read the file\n",53);

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
