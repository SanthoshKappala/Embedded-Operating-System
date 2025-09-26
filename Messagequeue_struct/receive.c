#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <unistd.h>
#include <sys/types.h>

#define MSG_SIZE 128

struct mq_attr attr;
mqd_t mqd;
unsigned int prio; 

typedef struct 
{
    pid_t pid;
    pid_t ppid;
}attr_struct;

attr_struct attr_pid;

int main(int argc, char const *argv[])
{
    ssize_t recv_ret;
    attr.mq_maxmsg = 5;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags=0;
    mqd = mq_open("/mymq",O_CREAT |O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP, &attr);

    if(mqd == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    recv_ret = mq_receive(mqd,(char *)&attr_pid, 1024, &prio);

    if (recv_ret == -1)
    {
        perror("Error receiving\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Received Successfully\n");
    }

    printf("ID is %d\nParent ID is %d\n",attr_pid.pid,attr_pid.ppid);
    mq_close(mqd);
    return 0;
}