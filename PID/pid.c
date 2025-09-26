#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{   
    pid_t pid;
    pid_t ppid;

    pid=getpid();
    ppid=getppid();

    printf("Process ID is %d\n",pid);
    printf("Parent process ID is %d\n", ppid);
    return 0;    
}