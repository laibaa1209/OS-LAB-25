#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Runner function with parameter
void *thread_function(void *arg) {
    int *num = (int *)arg;  // Convert void* to int*
    printf("Thread received value: %d\n", *num);
    
    pthread_exit((void *)42);
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;  // Thread attribute variable
    void *exit_status;
    int value = 100; // Value to pass to thread

    // Initialize thread attributes
    if (pthread_attr_init(&attr) != 0) {
        perror("pthread_attr_init failed");
        return 1;
    }

    // Set thread as joinable (default behavior, but demonstrating how to set attributes)
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE) != 0) {
        perror("pthread_attr_setdetachstate failed");
        return 1;
    }

    // Create thread using the initialized attributes
    if (pthread_create(&thread, &attr, thread_function, (void *)&value) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    // Destroy thread attributes after use
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish
    if (pthread_join(thread, &exit_status) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Thread exited with status: %ld\n", (long)exit_status);

    return 0;
}
