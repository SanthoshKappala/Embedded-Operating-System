#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 20

int main()
{
    unsigned char buff[MAX_SIZE];
    int fdr;
    fdr=open("desdfifo",O_RDONLY);
    read(fdr, buff,sizeof(buff));
    printf("Received data : %s\n",buff);
    close(fdr);
    return 0;
}