#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>          /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>

typedef struct 
{
    pid_t pid;
    pid_t ppid;
}attr;

attr *ptr;

int main(int argc, char const *argv[])
{ 
    int shmfd;
    shmfd = shm_open("/desdshm",O_CREAT|O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
    if (-1 == shmfd)
    {
        perror("Shm open\n");
        return EXIT_FAILURE;
    }

    ftruncate(shmfd, sizeof(ptr));
    ptr = (void *)mmap(NULL, sizeof(ptr), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (ptr == (void *)-1)
    {
        perror("Error mapping\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Received Succesfully\n");
    }
    printf("child id is  %d\n", ptr->pid);
    printf("parent id is %d\n", ptr->ppid);
    return 0;
}
