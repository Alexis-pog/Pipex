#include "pipex.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	c %= 256;
	str = (char *)s;
	while (str[i])
		i++;
	while (str[i] != c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&str[i]);
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


int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    int i = 0;
	while (strncmp("PATH=",envp[i], 5) != 0)
		i++;
    printf("%s",&envp[i][5]);
    return (0);
}