#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;
    printf("Before fork\n");
    printf("Process ID is        %d\n", getpid());
    printf("Parent Process ID is %d\n", getppid());

    id = fork();
    printf("After fork \n");
    printf("Process ID is        %d\n", getpid());
    printf("Parent Process ID is %d\n", getppid());
    return 0;
}
