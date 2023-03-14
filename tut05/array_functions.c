// A demonstration of arrays used with functions
// Joanna Lin, October 2022

#include <stdio.h>

#define SIZE 5

// The following function doesn't work
// void square(int x);
int square(int x);
void square_array(int length, int array[length]);
void print_array(int length, int array[length]);

int main(void) {
    int x = 10;
    printf("x before square function: %d\n", x);
    x = square(x);
    printf("x after square function: %d\n", x);

    int xs[SIZE] = {3, 1, 4, 1, 5};
    printf("xs before square function: ");
    print_array(SIZE, xs);
    square_array(SIZE, xs);
    printf("xs after square function: ");
    print_array(SIZE, xs);

}

// The void function could not achieve its purpose
// void square(int x) {

// Returns the square of the input
int square(int x) {
    return x * x;
}

// Prints the values of an integer array in one line,
// followed by a newline
void print_array(int length, int array[length]) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Squares all the values in the given array
void square_array(int length, int array[length]) {
    for (int i = 0; i < length; i++) {
        array[i] = square(array[i]);
    }
}
