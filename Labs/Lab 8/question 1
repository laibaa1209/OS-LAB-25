# part a
```c
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main() {
    float *A = (float *)malloc(SIZE * sizeof(float));
    float *B = (float *)malloc(SIZE * sizeof(float));
    float *C = (float *)malloc(SIZE * sizeof(float));

    // Initialize the arrays A and B with some values
    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = i * 2.0f;
    }

    // Perform the operation C = A + B
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    // Optionally, print the result of the first few elements
    for (int i = 0; i < 5; i++) {
        printf("C[%d] = %.2f\n", i, C[i]);
    }

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}
```
