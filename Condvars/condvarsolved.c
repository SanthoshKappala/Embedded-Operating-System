#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int event = 0;
pthread_mutex_t event_mutex;
pthread_cond_t event_cv;

void *waiting_thread(void *data)
{
    printf("Waiting thread : Grabbing the muitex\n");
    pthread_mutex_lock(&event_mutex);
    printf("Waiting thread : Got the mutex\n");
    while(event!=1)
    {
        printf("Waiting Thread : Waiting with condvar\n");
        pthread_cond_wait(&event_cv, &event_mutex);
        printf("Waiting Thread : Got the condvar\n");
    }
    printf("Waiting thread : Event is 1, done\n");
    pthread_mutex_unlock(&event_mutex);
    printf("Waiting thread : Released the mutex\n");
}

void *fire_event_thread(void *data)
{
    printf("Fire event thread : Grabbing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("Fire event thread : Got the mutex\n");
    event = 1;
    printf("Fire event thread : Event is 1, done\n");
    pthread_mutex_unlock(&event_mutex);
    printf("Fire event thread : Released the mutex\n");
    pthread_cond_signal(&event_cv); 
    printf("Fire event thread : Signalled the condvar\n");
    
}


int main(int argc, char const *argv[])
{
    pthread_t waiting, fire_event;
    pthread_mutex_init(&event_mutex, NULL);
    pthread_cond_init(&event_cv, NULL);
    pthread_create(&waiting, NULL, waiting_thread, NULL);
    pthread_create(&fire_event, NULL, fire_event_thread, NULL);
    pthread_join(waiting, NULL);
    pthread_join(fire_event, NULL);
    pthread_mutex_destroy(&event_mutex);
    pthread_cond_destroy(&event_cv);
    return 0;
}
