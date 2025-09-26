#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;
    id = fork();
    if(id==0)
    {
        printf("Child Process\n");
    }
    else if(id>0)
    {
        printf("Parent Process\n");
    }
    else
    {
        perror("Fork Failed\n");
    }
    
    return 0;
}
