#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signum) {
    fprintf(stdout, "Caught SIGINT signal (%d)\n", signum);
    exit(0);
}

void user_handler(int signum) {
    fprintf(stdout, "Caught user-defined signal SIGUSR1 (%d)\n", signum);
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        printf("Error setting up signal handler for SIGINT\n");
        return 1;
    }

    if (signal(SIGUSR1, user_handler) == SIG_ERR) {
        printf("Error setting up signal handler for SIGUSR1\n");
        return 1;
    }

    printf("Running... Press Ctrl+C to send SIGINT or send SIGUSR1 externally\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

