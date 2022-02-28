#include "pipex.h"


int main()
{
    int j[2];
    char *s;
    pid_t id;
    
    s = malloc(1);
    free(s);
    pipe(j);
    id = fork();

    if (id != 0)
    {
        j[1] = open("text.txt",O_RDWR); 
        j[0] = read(j[1],s,1);
        write(j[0],s,1);
    }
    
   
    printf("%d\n",j[1]);
    printf("%d\n",j[0]);
    
    j[0] = read(j[1],s,1);
    write(j[0],s,1);

    close(j[1]);
}