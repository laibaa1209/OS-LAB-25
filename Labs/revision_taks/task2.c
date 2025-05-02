#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10
int arr[SIZE];

void *sort_half(void *arg) {
    int start = *((int *)arg);
    int end = start + SIZE / 2;

    for (int i = start; i < end - 1; ++i) {
        for (int j = start; j < end - 1 - (i - start); ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    pthread_exit(NULL);
}

void merge() {
    int temp[SIZE];
    int i = 0, j = SIZE / 2, k = 0;

    while (i < SIZE / 2 && j < SIZE) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < SIZE / 2)
        temp[k++] = arr[i++];
    while (j < SIZE)
        temp[k++] = arr[j++];

    for (i = 0; i < SIZE; ++i)
        arr[i] = temp[i];
}

int main() {
    pthread_t t1, t2;
    int start1 = 0, start2 = SIZE / 2;

    printf("Original array:\n");
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_create(&t1, NULL, sort_half, &start1);
    pthread_create(&t2, NULL, sort_half, &start2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    merge();

    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
