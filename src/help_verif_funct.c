/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_verif_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: workplace <workplace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:43:50 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/22 11:02:13 by workplace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int ft_strlen(char *c)
{
	int i = 0;
	if (!c)
		return(0);
	while(c[i])
		i++;
	return(i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s1_chr;
	char	*s2_chr;
	size_t	i;

	i = 0;
	s1_chr = (char *)s1;
	s2_chr = (char *)s2;
	while (s1_chr[i] && s2_chr[i] && i < n - 1 && s1_chr[i] == s2_chr[i])
	{
		i++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1_chr[i] - (unsigned char)s2_chr[i]);
}

char    *ft_strrchr(const char *s, int c)
{
	char    *str;
	int        i;

	i = 0;
	c %= 256;
	str = (char *)s;
	while (str[i])
		i++;
	while (str[i] != c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return (&str[i]);
}

void	init_in_out(t_split *split, char **argv)
{
	split->infile = argv[1];
	split->outfile = argv[split->argc];
}

void init_verit_var(t_verif *verif, t_split *split, int argc)
{
	verif->verif_nbr = 0;
	verif->vrf_lenght = 0;
	verif->verif = "";
	verif->s = malloc(1);
	verif->fd = 0;
	split->index = 2;
	split->fd_i = 0;
	split->argc = argc;
	ft_memset(split->fd,0,sizeof(split->fd));
	free(verif->s);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	c %= 256;
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (!c)
		return ((char *)str);
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;

	count = -1;
	while (++count < n)
	{
		*(unsigned char *)(str + count) = (unsigned char)c;
	}
	return (str);
}