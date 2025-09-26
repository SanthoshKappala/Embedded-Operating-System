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
        printf("Child Process ID is %d\n", getpid());
        printf("Child Process Parent ID is %d\n", getppid());
    }
    else if(id>0)
    {
        printf("Parent Process\n");
        sleep(10);
        printf("Parent Process ID is %d\n", getpid());
        printf("Parent Process Parent ID is %d\n", getppid());
    }
    else{
        perror("Fork failed\n");
    }
    return 0;
}