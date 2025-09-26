#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <unistd.h>
#include <sys/types.h>

#define MSG_SIZE 512

struct mq_attr attr;
mqd_t mqd;

typedef struct 
{
    pid_t pid;
    pid_t ppid;
}attr_struct;

attr_struct attr_pid;

int main(int argc, char const *argv[])
{
    int send_ret;

    attr.mq_maxmsg = 5;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags=0;

    attr_pid.pid = getpid();
    attr_pid.ppid = getppid();

    printf("%d\n", attr_pid.pid);
    printf("%d\n", attr_pid.ppid);

    mqd = mq_open("/mymq",O_CREAT |O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP, &attr);

    if(mqd == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    send_ret = mq_send(mqd,(const char *)&attr_pid, sizeof(attr_pid), 0);
    
    if (-1 == send_ret)
    {
        perror("error sending\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Message sent successfully\n");
    }
    
    mq_close(mqd);
    return 0;
}