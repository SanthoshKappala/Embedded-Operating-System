#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t dev_init_barrier; 
void* serial_thread(void *data)
{
    printf("Serial Thread : Init Started\n");
    sleep(7);
    printf("Serial Thread : Init Finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Serial Thread : Main Functionality\n");
}

void* ether_thread(void *data) 
{
    printf("Ether Thread : Init Started\n");
    sleep(10);
    printf("Ether Thread : Init Finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Ether Thread : Main Functionality\n");
}

void* lcd_thread(void *data)
{
    printf("Lcd Thread : Init Started\n");
    sleep(8);
    printf("Lcd Thread : Init Finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Lcd Thread : Main Functionality\n");
}

int main(int argc, char const *argv[])
{
    pthread_t serial_id, ether_id, lcd_id;
    pthread_barrier_init(&dev_init_barrier,NULL,3);
    pthread_create(&serial_id, NULL, serial_thread, NULL);
    pthread_create(&ether_id, NULL, ether_thread, NULL);
    pthread_create(&lcd_id, NULL, lcd_thread, NULL);
    pthread_join(serial_id,NULL);
    pthread_join(ether_id, NULL);
    pthread_join(lcd_id, NULL);
    pthread_barrier_destroy(&dev_init_barrier);
    return 0;
}