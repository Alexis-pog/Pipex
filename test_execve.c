/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:55:53 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/08 17:44:48 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    char *binarypath = "/usr/bin/whereis";
    char *const args[] = {"-as",argv[1], NULL};
    // char *const env[] = {"PATH=/Users/acoquele/.brew/bin:/Users/acoquele/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki",NULL};
    execve(binarypath, args, envp);
    return (0);
}

/*
PATH=/Users/acoquele/.brew/bin:/Users/acoquele/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
*/