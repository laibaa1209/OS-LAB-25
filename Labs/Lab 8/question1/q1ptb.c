#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREAD_COUNT 10

float A[SIZE], B[SIZE], C[SIZE];

void *add(void *arg) {
    int index = *(int *)arg;
    int start = index * (SIZE / THREAD_COUNT);
    int end = (index + 1) * (SIZE / THREAD_COUNT);

    for (int i = start; i < end; i++) {
        C[i] = A[i] + B[i];
    }
    return NULL;
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = (SIZE - i) * 1.0f;
    }

    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, add, &thread_ids[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("C[0] = %.2f\n", C[0]);
    printf("C[%d] = %.2f\n", SIZE - 1, C[SIZE - 1]);

    return 0;
}

