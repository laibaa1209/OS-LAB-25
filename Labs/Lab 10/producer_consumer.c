#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

sem_t mutex, empty, full;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // Generate a random item
        sem_wait(&empty);    // Wait if buffer is full
        sem_wait(&mutex);    // Lock the buffer

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);    // Unlock the buffer
        sem_post(&full);     // Signal that an item is added

        sleep(rand() % 3);   // Simulate time taken to produce
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);     // Wait if buffer is empty
        sem_wait(&mutex);    // Lock the buffer

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);    // Unlock the buffer
        sem_post(&empty);    // Signal that a slot is now free

        sleep(rand() % 3);   // Simulate time taken to consume
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

