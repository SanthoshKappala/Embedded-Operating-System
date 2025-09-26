#include <stdio.h>
#include <pthread.h>

pthread_t tid;
pthread_attr_t attr;

void *display(void *data)
{
    printf("This is the thread\n");
}

int main()
{
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    printf("Before thread creation\n");
    pthread_create(&tid, &attr, display, NULL);
    pthread_attr_destroy(&attr);
    printf("After thread creation\n");
    pthread_join(tid, NULL);
    return 0;
}