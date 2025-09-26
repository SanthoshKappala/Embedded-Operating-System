#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec\n");
    execl("/usr/bin/ls","/usr/bin/ls", NULL);
    printf("After exec\n");
    return 0;
}