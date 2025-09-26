#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_rwlock_t count_rwlock;

void* read1(void *data)
{
    int i;
    printf("Read 1: Entering Critical Section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Read 1: Inside Critical Section\n");
    i=count+10;
    printf("Read 1: %d\n", count);
    printf("Read 1: Leaving Critical Section\n");
    pthread_rwlock_unlock(&count_rwlock);
    printf("Read 1: Left Critical Section\n");
}

void* read2(void *data)
{
    int n;
    printf("Read 2: Entering Critical Section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Read 2: Inside Critical Section\n");
    n= count+20;    
    printf("Read 2: %d\n", count);
    printf("Read 2: Leaving Critical Section\n");
    pthread_rwlock_unlock(&count_rwlock);
    printf("Read 2: Left Critical Section\n");
}

void* write(void *data)
{ 
    printf("Write: Entering Critical Section\n");
    pthread_rwlock_wrlock(&count_rwlock);
    printf("Write: Inside Critical Section\n");
    count++;
    printf("Write: Leaving Critical Section\n");
    pthread_rwlock_unlock(&count_rwlock);
    printf("Write: Left Critical Section\n");
}

int main()
{
    pthread_t r1, r2, w;
    pthread_rwlock_init(&count_rwlock,NULL);
    pthread_create(&r1, NULL, read1, NULL);
    pthread_create(&r2, NULL, read2, NULL);
    pthread_create(&w, NULL, write, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w, NULL);
    pthread_rwlock_destroy(&count_rwlock);
    return 0;
}