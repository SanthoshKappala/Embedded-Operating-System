#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a,b;
sem_t sem_i2p, sem_p2i;

void* inputThread(void* data)
{
    while(1)
    {
        sem_wait(&sem_p2i);
        printf("Enter two numbers :");
        scanf("%d %d", &a, &b);
        sem_post(&sem_i2p);
    }
}

void* processingThread(void* data)
{
    while(1)
    {
        sem_wait(&sem_i2p);
        int sum=0;
        sum = a+b;
        printf("Sum : %d\n", sum);
        sem_post(&sem_p2i);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t inputTid, processingTid;
    sem_init(&sem_p2i, 0, 1);
    sem_init(&sem_i2p, 0, 0);
    pthread_create(&inputTid, NULL, inputThread, NULL);
    pthread_create(&processingTid, NULL, processingThread, NULL);
    pthread_join(inputTid, NULL);
    pthread_join(processingTid, NULL);
    sem_destroy(&sem_i2p);
    sem_destroy(&sem_p2i);
    return 0;
}