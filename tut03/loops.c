// Answers the loop tutorial exercise.
// Joanna, September 2022

#include <stdio.h>

void a(void) {
    int i = 5;
    while (i > 0) {
        printf("%d\n", i);
        i--;
    }
}

void b(void) {
    int i = 1;
    while (i < 32) {
        printf("%d\n", i);
        i = i + i;
    }
}

void c(void) {
    int i = 0;
    while (i < 32) {
        printf("%d\n", i);
        i = i + 2;
    }
}

void d(void) {
    int i = 5;
    while (i >= 0) {
        printf("%d\n", i);
        i--;
    }
}

void e(void) {
    int i = 0;
    int keep_going = 1;
    while (keep_going == 1) {
        if (i > 3) {
            keep_going = 0;
        }
        i++;
    }
    printf("%d\n", i);
}

void f(void) {
    int i;
    while (i > 0) {
        printf("%d\n", i);
        i--;
    }

}

void g(void) {
    int i = 0;
    int max = 32;
    while (i < max) {
        printf("%d\n", i);
        max = max + 2;
    }

}

void h(void) {
    int i = 0;
    int keep_going = 0;
    while (keep_going == 1) {
        if (i > 3) {
            keep_going = 0;
        }
        i++;
    }
    printf("%d\n", i);
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
    } else if (procedure == 'e') {
        e();
    } else if (procedure == 'f') {
        f();
    } else if (procedure == 'g') {
        g();
    } else if (procedure == 'h') {
        h();
    } else {
        printf("Invalid procedure: %c\n", procedure);
    }

    return 0;
}
