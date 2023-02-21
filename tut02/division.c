// A program that requests two integers from the user and prints the
// the result of dividing the first integer by the second, using both
// integer and double division.

// Prints error if the provided denominator is zero.

// Joanna Lin, February 2023 

#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
};

void print_divide_by_zero_error(void) {
    printf("Cannot divide by zero!\n");
}

int main(void) {
    struct fraction frac;
    printf("Enter fraction: ");
    scanf("%d %d", &frac.numerator, &frac.denominator);
    if (frac.denominator == 0) {
        print_divide_by_zero_error();
        return 1;
    }

    int quotient = frac.numerator / frac.denominator;
    double frac_value = (frac.numerator * 1.) / frac.denominator;

    printf("You entered %d / %d = %lf (%d in C).\n", frac.numerator, frac.denominator, frac_value, quotient);
    return 0;
}
