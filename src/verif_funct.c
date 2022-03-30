/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: workplace <workplace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:32:56 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/21 15:06:16 by workplace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*main_str;
	int		i;
	int		i2;

	if (!s1)
		return (NULL);
	i = 0;
	i2 = 0;
	main_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!main_str)
		return (NULL);
	while (s1[i])
	{
		main_str[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		main_str[i] = s2[i2];
		i++;
		i2++;
	}
	main_str[i] = '\0';
	return (main_str);
}


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

char	*ft_substr(char  *s, unsigned int start, size_t len)
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

int	count_word(char *s, char c, t_split *split)
{
	size_t	count;
	size_t	index;

	index = 0;
	count = 0;
	while (s[index] == c && s[index])
		index++;
	while (s[index])
	{
		if (s[index] == c)
			count++;
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
			index++;
	}
	if (!s[0])
		count = 0;
	else if (s[index - 1] != c)
		count++;
	split->w_count = count;
	return (count);
}

char	**free_malloc(char **tab, int count)
{	
	while (tab[--count])
		free(tab[count]);
	free (tab);
	return (NULL);
}

char	**make_a_word(char *s, char c, char **tab, size_t count)
{
	size_t	str_index;
	size_t	word_index;
	size_t	y_index;

	str_index = 0;
	word_index = 0;
	y_index = 0;
	while (y_index < count)
	{
		while (s[str_index] == c)
			str_index++;
		word_index = str_index;
		while (s[word_index + 1] != c && s[word_index + 1])
			word_index++;
		tab[y_index] = ft_substr(s, str_index, word_index - str_index + 1);
		if (!tab[y_index])
			return (free_malloc(tab, y_index));
		str_index = word_index + 1;
		y_index++;
	}
	tab[y_index] = 0;
	return (tab);
}

char	**ft_split(char *s, char c, t_split *split)
{
	char	**tab;
	char	*new_s;
	size_t	count;

    new_s = (char *)s;
	if (!new_s)
		return (NULL);
	count = count_word(s, c, split);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
    return (make_a_word(new_s, c, tab, count));
}