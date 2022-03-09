#include "pipex.h"

int main()
{
    int id = 0;
    int status;

    id = fork();

    if (id == 0)
        printf("hello\n");
    else
    {
        wait(&id);
        printf("goodbye\n");
    }
    return(0);
}