#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_strlen(char *c)
{
	int i = 0;
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

void error_name()
{
	write(1,"must be a .txt file\n",20);
	exit(0);
}

void empty_file(int fd)
{
	write(1,"the file is empty\n",18);
	close(fd);
	exit(0);
}

void file_void()
{
	write(1,"ERROR\n",6);
	write(1,"the file does not exist\n",24);
	write(1,"or\n", 3);
	write(1,"check the name to see if you have not misspelled it\n",53);
	exit(0);
}

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	int verif_nbr;
	int fd;
	int vrf_lenght = 0;
	char *verif = "";
	char *s;
	if (argc > 1)
	{
		if (access(argv[1],F_OK) != 0 && access(argv[1],R_OK) != 0)
			file_void();
		verif = ft_strrchr(argv[1], '.');
		if (!verif)
			error_name();
		printf("%s\n",verif);
		vrf_lenght = ft_strlen(verif);
		if (vrf_lenght != 4)
			error_name();
		if (ft_strncmp(verif,".txt",vrf_lenght) != 0)
			error_name();
		fd = open(argv[1],O_RDONLY);
		if (read(fd,s,1) == 0)
			empty_file(fd);
		verif_nbr = access(argv[argc - 1],F_OK);
		printf("%d\n",j);
	}
	else
		write(1,"missing arguments\n",18);
	return(0);
}

