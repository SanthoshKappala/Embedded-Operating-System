#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char str[25];
    int fd;
    fd=open("desd.txt", O_CREAT | O_RDWR);
    if(fd==-1)
    {
        perror("Error opening file\n");
        return -1;
    }
    else
    {
        read(fd, str, 25);
        printf("%s\n",str);
        close(fd);
        return 0;
    }
}