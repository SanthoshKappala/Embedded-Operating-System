#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct 
{
    int n1;
    int n2;

    int add;
    int sub;
    int mul;
    int div;
}pipe1;

pipe1 s1;

typedef struct 
{
    int a;
    int b;
    
    int add;
    int sub; 
    int mul;
    int div;
}pipe2;

pipe2 s2;

int main(int argc, char const *argv[])
{
    s1.n1 = 20;
    s1.n2 = 10;

    pid_t id;
    int fd[2], fd1[2];
    int pipe_ret = pipe(fd);
    pipe(fd1);
    if (pipe_ret == -1) 
    {
        perror("Error in creating pipe\n");
        exit(EXIT_FAILURE);
    }
    else{
    id =fork();
    if (id == -1)
    {
        perror("Error in forking\n");
        exit(EXIT_FAILURE);
    }
    
    if (id == 0)
    {
        printf("Child process\n");
        read(fd[0],&s2, sizeof(s2));
        s2.add = s2.a + s2.b;
        s2.sub = s2.a - s2.b;
        s2.mul = s2.a * s2.b;
        s2.div = s2.a / s2.b;
        printf("In Child : add is %d, sub is %d, mul is %d, div is %d\n", s2.add, s2.sub, s2.mul, s2.div);
        write(fd1[1],&s2, sizeof(s2));
    }
    else
    {
        printf("Parent process\n");
        write(fd[1],&s1, sizeof(s1));
        read(fd1[0],&s1, sizeof(s1));
        printf("In Parent : add is %d, sub is %d, mul is %d, div is %d\n", s1.add, s1.sub, s1.mul, s1.div);
    }
    }
    return 0;
}
