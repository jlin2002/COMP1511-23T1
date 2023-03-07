// A demonstration of arrays

// Joanna Lin, March 2023

#include <stdio.h>

#define SIZE 10

void print_array(int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    // Task 1: Create an integer array called 'numbers' of size SIZE.
    // Initialise all elements to 0.
    int numbers[SIZE] = {};

    // Task 2: Print the elements of the array.
    print_array(SIZE, numbers);

    // Task 3: Initialise the elements of the array to 1, 2, 3...
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }

    // Task 4: Print the elements of the array.
    print_array(SIZE, numbers);

    // Task 5: Create a function that prints elements of an array and use it.

    return 0;
}
