#include <stdio.h>

enum opal_card_type {
    ADULT,
    STUDENT,
    CONCESSION
};

struct person {
    int shoe_size;
    double height;
    char first_name_initial;
    enum opal_card_type card_type;
};

int main(void) {
    struct person tom;
    tom.shoe_size = 5;
    tom.height = 150.5;
    tom.first_name_initial = 'T';
    tom.card_type = ADULT;
    // Example of enum initialisation:
    // enum opal_card_type my_card_type = CONCESSION;
    printf(
        "Shoe size: %d, Height: %.1lfcm, First letter: %c, Card type: %d\n",
        tom.shoe_size, tom.height, tom.first_name_initial, tom.card_type
    );

    return 0;
}
