#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_SIZE 20
int main()
{
    unsigned char buff[MAX_SIZE];
    pid_t id;
    int fd[2];
    //fd[0] is for reading
    //fd[1] is for writing
    pipe(fd);
    id=fork();

    if(id==0)
    {
        close(fd[1]);
        printf("Child process\n");
        read(fd[0], buff, sizeof(buff));
        printf("Child : Received data :%s\n",buff);
    }
    else
    {
        close(fd[0]);
        printf("Parent process\n");
        write(fd[1],"CDAC Hyderabad\n",15);
    }
    return 0;
}