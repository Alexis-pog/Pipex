#include "pipex.h"

/*
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
	dup2(j[1],i[1]);
	close(j[1]);
	printf("\n");
	i[0] = read(i[1],s,1);
	write(i[0],s,1);

	close(i[1]);
	close(i[0]);
	close(j[0]);
}
*/

int child_porcess(int argc, char **argv, char **envp, int fd_in, int fd_out, int end[2])
{
    (void) argc;
    int j = 0;
    int i = access(argv[1], F_OK);
    char *binarypath = "/usr/bin/sed";
    char *const args[] = {" ","s/l/e/g", NULL};
    dup2(fd_in, 0);
	dup2(end[1], 1);
	close(end[0]);
	close(fd_in);
	execve(binarypath, args, envp);
    return (0);
}

int main(int argc, char **argv, char **envp)
{
	int end[2];
	int fd_in;
	int fd_out;
	char *s;
	pid_t parent;
	fd_in = open(argv[1],O_RDONLY);
	fd_out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipe(end);
	parent = fork();
	if (!parent)
		child_porcess(argc,argv,envp, fd_in, fd_out, end);
	else
	{
		wait(0);
		dup2(fd_out, 0);
		dup2(end[0],end[1]);
	}
return (0);
}
