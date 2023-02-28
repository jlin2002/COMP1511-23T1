// Answers the nested loop tutorial exercise
// Joanna, September 2022

#include <stdio.h>

#define SIZE 4

void a(void) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (row == col) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }
        row++;
        printf("\n");
    }
}

void b(void) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (col % 2 == 0) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }
        row++;
        printf("\n");
    }
}

void c(void) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (col != 1 && row != 1) {
                printf("O");
            } else {
                printf("X");

            }
            col++;
        }
        row++;
        printf("\n");
    }
}

void d(void) {
    int row = 0;
    while (row < SIZE) {
        printf("X");
        int col = 1;
        while (col < 3) {
            if (row == 0 || row == 3) {
                printf("X");
            } else {
                printf("O");
            }
            col++;
        }
        printf("X");
        row++;
        printf("\n");
    }
} 

int main(void) {
    printf("Choose procedure to run: ");
    char procedure;
    if (scanf(" %c", &procedure) != 1) {
        printf("No procedure given.\n");
        return 1;
    }

    if (procedure == 'a') {
        a();
    } else if (procedure == 'b') {
        b();
    } else if (procedure == 'c') {
        c();
    } else if (procedure == 'd') {
        d();
    } else {
        printf("Invalid procedure: %c\n", procedure);
    }

    return 0;
}
