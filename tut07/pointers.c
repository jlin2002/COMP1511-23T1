// Basic demo of pointers!
// <CLASS>, <MONTH YEAR>

#include <stdio.h>

void increment(int *ptr);

int main(void) {
    int x = 10;
    printf("x: %d\n", x);

    /*

    // Task 1: Initialise a pointer to x called x_ptr
    int *x_ptr = &x;
    // Task 2: Change the value of x via the pointer
    *x_ptr = 11; 
    printf("x: %d\n", x);

    */

    increment(&x);
    printf("x: %d\n", x);
    return 0;
}

// Task 3: Implement this function.
// Change parameter types as needed.
void increment(int *ptr) {
    *ptr = *ptr + 1;
}
