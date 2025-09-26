#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fdw;
    fdw=open("desdfifo",O_WRONLY);
    write(fdw, "CDAC Hyderabad\n",15);
    close(fdw);
    return 0;
}