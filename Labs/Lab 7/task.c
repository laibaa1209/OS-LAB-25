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
    void *exit_status;
    int value = 26; // Value to pass to thread

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

    printf("Thread exited with status: %ld\n", (long)exit_status);

    return 0;
}

