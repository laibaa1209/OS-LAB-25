#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  // for sleep

#define NUM_TELLERS 3
#define NUM_CUSTOMERS 10

int balance = 1000;
pthread_mutex_t lock;

void *serve_customer(void *arg) {
    long teller_id = (long)arg;

    for (int i = 0; i < NUM_CUSTOMERS / NUM_TELLERS; i++) {
        int change = (rand() % 201) - 100;  // Random between -100 and +100

        pthread_mutex_lock(&lock);
        balance += change;
        printf("Teller %ld processed transaction: %+d | New balance: %d\n",
               teller_id, change, balance);
        pthread_mutex_unlock(&lock);

        sleep(1); // Simulate transaction time
    }

    return NULL;
}

int main() {
    pthread_t tellers[NUM_TELLERS];
    pthread_mutex_init(&lock, NULL);

    // Create threads for each teller
    for (long i = 0; i < NUM_TELLERS; i++) {
        pthread_create(&tellers[i], NULL, serve_customer, (void *)i);
    }

    // Wait for all tellers to finish
    for (int i = 0; i < NUM_TELLERS; i++) {
        pthread_join(tellers[i], NULL);
    }

    printf("Final balance: %d\n", balance);
    pthread_mutex_destroy(&lock);
    return 0;
}

