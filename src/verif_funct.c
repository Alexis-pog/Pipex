/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:32:56 by acoquele          #+#    #+#             */
/*   Updated: 2022/02/28 16:56:03 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv)
{
	t_verif verif;
	
	init_verit_var(&verif);
	if (argc > 1)
	{
		if (access(argv[1],F_OK) != 0 || access(argv[1],R_OK) != 0)
			file_void();
		verif.verif = ft_strrchr(argv[1], '.');
		if (!verif.verif)
			error_name();
		printf("%s\n",verif.verif);
		verif.vrf_lenght = ft_strlen(verif.verif);
		if (verif.vrf_lenght != 4)
			error_name();
		if (ft_strncmp(verif.verif,".txt",verif.vrf_lenght) != 0)
			error_name();
		verif.fd = open(argv[1],O_RDONLY);
		if (read(verif.fd,verif.s,1) == 0)
			empty_file(verif.fd);
		verif.verif_nbr = access(argv[argc - 1],F_OK);
		printf("%d\n",verif.verif_nbr);
		printf("%s\n",verif.s);
	}
	else
		write(1,"missing arguments\n",18);
	return(0);
}

