// serial_addition.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main() {
    float *A = malloc(SIZE * sizeof(float));
    float *B = malloc(SIZE * sizeof(float));
    float *C = malloc(SIZE * sizeof(float));

    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = (SIZE - i) * 1.0f;
    }

    clock_t start = clock();

    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    clock_t end = clock();

    printf("Serial addition completed in %.3f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("C[0] = %.2f, C[%d] = %.2f\n", C[0], SIZE - 1, C[SIZE - 1]);

    free(A);
    free(B);
    free(C);

    return 0;
}

