// A program that takes a year as input, and prints out whether
// it is a leap year or not.

// <CLASS>, <MONTH YEAR>

#include <stdio.h>

void print_leap_year(void) {
    printf("A leap year.\n");
}

void print_not_leap_year(void) {
    printf("Not a leap year.\n");
}

int main(void) {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    if (year % 400 == 0) {
        print_leap_year();
    } else if (year % 100 == 0) {
        print_not_leap_year();
    } else if (year % 4 == 0) {
        print_leap_year();
    } else {
        print_not_leap_year();
    }
    return 0;
}
