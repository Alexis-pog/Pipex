#include "pipex.h"


int main()
{
	int j[2];
	int i[2];
	char *s;
	pid_t id;
	
	s = malloc(1);
	free(s);
	pipe(j);
	pipe(i);

	j[1] = open("text.txt",O_RDWR); 
	j[0] = read(j[1],s,1);
	write(j[0],s,1);
	printf("\n");
	i[1] = dup(j[1]);
	i[0] = read(i[1],s,1);
	write(i[0],s,1);

	close(i[1]);
	close(i[0]);
	close(j[1]);
	close(j[0]);
}