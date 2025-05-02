#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CUSTOMERS 5
#define NUM_CHEFS 2

sem_t chef_sem;
pthread_mutex_t order_mutex;

int order_count = 0;

void *customer_thread(void *arg) {
    pthread_mutex_lock(&order_mutex);
    int my_order = ++order_count;
    printf("Customer %ld placed order #%d\n", (long)arg, my_order);
    pthread_mutex_unlock(&order_mutex);
    return NULL;
}

void *chef_thread(void *arg) {
    while (1) {
        sem_wait(&chef_sem);
        pthread_mutex_lock(&order_mutex);
        if (order_count == 0) {
            pthread_mutex_unlock(&order_mutex);
            sem_post(&chef_sem);
            break;
        }
        printf("Chef %ld is preparing order #%d\n", (long)arg, order_count--);
        pthread_mutex_unlock(&order_mutex);
        sleep(1);
        sem_post(&chef_sem);
    }
    return NULL;
}

int main() {
    pthread_t customers[NUM_CUSTOMERS], chefs[NUM_CHEFS];
    sem_init(&chef_sem, 0, NUM_CHEFS);
    pthread_mutex_init(&order_mutex, NULL);

    for (long i = 0; i < NUM_CUSTOMERS; i++)
        pthread_create(&customers[i], NULL, customer_thread, (void *)i);

    for (int i = 0; i < NUM_CUSTOMERS; i++)
        pthread_join(customers[i], NULL);

    for (long i = 0; i < NUM_CHEFS; i++)
        pthread_create(&chefs[i], NULL, chef_thread, (void *)i);

    for (int i = 0; i < NUM_CHEFS; i++)
        pthread_join(chefs[i], NULL);

    pthread_mutex_destroy(&order_mutex);
    sem_destroy(&chef_sem);

    return 0;
}
