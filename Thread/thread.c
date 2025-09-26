#include <stdio.h>
#include <pthread.h>

pthread_t tid;

void *display(void *data)
{
    printf("This is the thread\n");
}

int main()
{
    printf("Before thread\n");
    pthread_create(&tid, NULL, display, NULL);
    sleep(1);
    printf("After thread\n");
    return 0;
}