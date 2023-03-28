// A brief introduction to malloc
// Task 0: Figure out which library malloc comes from
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

int main(void) {
    // Task 1: Allocate memory for a double
    double *d = malloc(sizeof(double));
    // Task 2: Allocate memory for an integer array of size 10
    int* array = malloc(SIZE * sizeof(int));
    // Task 3: Set the integer array elements to 1.
    for (int i = 0; i < SIZE; i++) {
        array[i] = 1;
    }
    return 0;
}
