#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

FILE *tempFile;

void handle_sigint(int sig) {
    printf("\nSIGINT received. Cleaning up...\n");
    if (tempFile) {
        fclose(tempFile);
        remove("tempfile.txt");
        printf("Temporary file deleted.\n");
    }
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    tempFile = fopen("tempfile.txt", "w");
    if (!tempFile) {
        perror("Unable to create temp file");
        return 1;
    }

    int counter = 1;
    while (1) {
        fprintf(tempFile, "Line %d: Writing data...\n", counter++);
        fflush(tempFile);
        sleep(1);
    }

    return 0;
}
