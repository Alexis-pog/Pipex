/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_verif_funct2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:19:53 by acoquele          #+#    #+#             */
/*   Updated: 2022/04/20 11:22:52 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	count;

	if (!s || *s == '\0')
		return (NULL);
	count = 0;
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (ft_strlen((char *)s) - start < len)
		len = ft_strlen((char *)s) - start;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (len > 0)
	{
		sub_str[count] = s[start];
		start++;
		count++;
		if (len == 0)
			break ;
		len--;
	}
	sub_str[count] = '\0';
	return (sub_str);
}
