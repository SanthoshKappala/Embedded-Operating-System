#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* serial_thread(void *data)
{
    printf("Serial Thread : Init Started\n");
    sleep(7);
    printf("Serial Thread : Init Finished\n");
    printf("Serial Thread : Main Functionality\n");
}

void* ether_thread(void *data) 
{
    printf("Ether Thread : Init Started\n");
    sleep(10);
    printf("Ether Thread : Init Finished\n");
    printf("Ether Thread : Main Functionality\n");
}

void* lcd_thread(void *data)
{
    printf("Lcd Thread : Init Started\n");
    sleep(8);
    printf("Lcd Thread : Init Finished\n");
    printf("Lcd Thread : Main Functionality\n");
}

int main(int argc, char const *argv[])
{
    pthread_t serial_id, ether_id, lcd_id;
    pthread_create(&serial_id, NULL, serial_thread, NULL);
    pthread_create(&ether_id, NULL, ether_thread, NULL);
    pthread_create(&lcd_id, NULL, lcd_thread, NULL);
    pthread_join(serial_id,NULL);
    pthread_join(ether_id, NULL);
    pthread_join(lcd_id, NULL);
    return 0;
}