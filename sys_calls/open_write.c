#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd=open("desd.txt", O_CREAT | O_WRONLY);
    if(fd==-1)
    {
        perror("Error opening file\n");
        return -1;
    }
    else
    {
        write(fd,"CDAC Hyderabad, DESD\n", 20);
        close(fd);
        return 0;
    }
    
}