#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Runner function with parameter
void *thread_function(void *arg) {
    int *num = (int *)arg;  // Convert void* to int*
    printf("Thread received value: %d\n", *num);
    
    // Dynamically allocate memory for return value
    int *result = malloc(sizeof(int));
    *result = (*num) * 2;  // Example: Modify the received value

    pthread_exit((void *)result);
}

int main() {
    pthread_t thread;
    void *exit_status;
    int value = 1000; // Value to pass to thread

    // Create thread and pass &value as an argument
    if (pthread_create(&thread, NULL, thread_function, (void *)&value) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread, &exit_status) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    // Retrieve and print returned value
    int *returned_value = (int *)exit_status;
    printf("Thread exited with value: %d\n", *returned_value);

    // Free dynamically allocated memory
    free(returned_value);

    return 0;
}
