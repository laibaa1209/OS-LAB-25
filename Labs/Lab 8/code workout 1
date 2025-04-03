// Part 1: Parameter Passing in pthread_create()
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int *num = (int *)arg; // Receiving the argument
    printf("Thread executing with argument: %d\n", *num);
    pthread_exit((void *)(*num * 2)); // Exiting with a modified valu
}

int main() {
    pthread_t thread;
    void *exit_status;
    int value = 10; // Example parameter

    pthread_create(&thread, NULL, thread_function, &value);
    pthread_join(thread, &exit_status);
    printf("Thread exited with status: %ld\n", (long)exit_status);

    return 0;
}

// Part 2: Using pthread_attr_init() to Set Thread Attributes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread executing...\n");
    pthread_exit((void *)42);
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    void *exit_status;

    pthread_attr_init(&attr); // Initialize thread attributes
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); // Ensure the thread is joinable
    
    pthread_create(&thread, &attr, thread_function, NULL);
    pthread_attr_destroy(&attr); // Destroy attributes after use
    
    pthread_join(thread, &exit_status);
    printf("Thread exited with status: %ld\n", (long)exit_status);
    
    return 0;
}

// Part 3: Using pthread_join() to Return Values
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int result = 100; // Example return value
    pthread_exit((void *)(long)result);
}

int main() {
    pthread_t thread;
    void *exit_status;

    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_join(thread, &exit_status);
    printf("Thread exited with status: %ld\n", (long)exit_status);
    
    return 0;
}
