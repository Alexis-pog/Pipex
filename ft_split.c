/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:48:02 by acoquele          #+#    #+#             */
/*   Updated: 2022/03/15 14:53:38 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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

	if (!s || s == '\0')
		return (NULL);
	count = 0;
	if (start >= ft_strlen((char *)s))
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

int	count_word(char *s, char c)
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

void	*ft_split(char *s, char c, t_split *split)
{
	char	**tab;
	char	**tab2;
	char	*new_s;
	size_t	count;
   
	
    new_s = (char *)s;
	if (!new_s)
		return (NULL);
	count = count_word(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	split->tab = make_a_word(new_s, c, tab, count);
    return (0);
}




int main(int argc, char **argv, char **envp)
{ 
	char *b;
	int checker = 0;
	char *a = ft_strchr(envp[13],'/');
    t_split split;
	if (argc > 1)
	{
		if (argv[1][0] != '/')
		{
			ft_split(a,':',&split);
			int j = 0;
			while (split.tab[j])
				printf("%s\n",split.tab[j++]);
			split.tab[j] = NULL;
			b = ft_strjoin("/",argv[1]);
			j = 0;

			while(split.tab[j])
			{
				checker = access(ft_strjoin(split.tab[j], b), F_OK);
				printf("%d\n",checker);
				j++;
			}
			if (!split.tab[0])
				printf("good-job");
			printf("\n%s\n",b);
		}
		else
			if(access(argv[1], F_OK) == 0)
				printf("OK");
		else
			printf("you wrote this : %s",argv[1]);
	}
	return (0);
}
 if (argv[2][0] != '/')
		{
			split.i = 0;
            while(strncmp("PATH=",envp[split.i],5) != 0)
                split.i++;
            ft_split(&envp[split.i][5],':',&split);
			int j = 0;
			while (split.tab[j])
				printf("%s\n",split.tab[j++]);
			split.tab[j] = NULL;
			split.tmp1 = ft_strjoin("/",argv[2]);
			j = 0;

			while(split.tab[j])
			{
				split.checker = access(ft_strjoin(split.tab[j], split.tmp1), F_OK);
				printf("%d\n",split.checker);
				j++;
			}
			if (!split.tab[0])
				printf("good-job");
			printf("\n%s\n",split.tmp1);
		}
		else
        {
			if(access(argv[2], F_OK) == 0)
				printf("OK");
		    else
			    printf("you wrote this : %s",argv[2]);
        }
	}
}