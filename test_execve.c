/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: workplace <workplace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:55:53 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/17 16:39:29 by workplace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void path_recup(t_split *slpit)
{

}




int main(int argc, char **argv, char **envp)
{
    (void) argc;
    int j = 0;
    int i = access(argv[1], F_OK);
    t_split split;
    
    printf("%d",i);
    if (i == -1)
    {
        char *binarypath = "/usr/bin/whereis";
        char *const args[] = {" ",argv[1], NULL};
        // char *const env[] = {"PATH=/Users/acoquele/.brew/bin:/Users/acoquele/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki",NULL};
        execve(binarypath, args, envp);
    }
    else
    {
        char *binarypath = argv[1];
        char *const args[] = {"", NULL};
        // char *const env[] = {"PATH=/Users/acoquele/.brew/bin:/Users/acoquele/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki",NULL};
        execve(binarypath, args, envp);
    }

    return (0);
}

/*
PATH=/Users/acoquele/.brew/bin:/Users/acoquele/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
*/