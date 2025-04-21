#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *numbers;
int count;

float average;
int maximum;
int minimum;

void *calculate_average(void *arg) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    average = (float)sum / count;
    return NULL;
}

void *calculate_maximum(void *arg) {
    maximum = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return NULL;
}

void *calculate_minimum(void *arg) {
    minimum = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    count = argc - 1;
    numbers = malloc(count * sizeof(int));

    // Store input numbers
    for (int i = 0; i < count; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    // Declare threads
    pthread_t avg_thread, max_thread, min_thread;

    // Create threads
    pthread_create(&avg_thread, NULL, calculate_average, NULL);
    pthread_create(&max_thread, NULL, calculate_maximum, NULL);
    pthread_create(&min_thread, NULL, calculate_minimum, NULL);

    // Wait for threads to finish
    pthread_join(avg_thread, NULL);
    pthread_join(max_thread, NULL);
    pthread_join(min_thread, NULL);

    // Display results
    printf("The average value is %.2f.\n", average);
    printf("The minimum value is %d.\n", minimum);
    printf("The maximum value is %d.\n", maximum);

    free(numbers);
    return 0;
}

