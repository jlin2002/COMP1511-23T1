// A program that asks the user enter temperatures, then prints them out and
// then prints the highest temperature. Assume all inputs are positive.

// Joanna Lin, March 2023

#include <stdio.h>
#define NUM_DAYS 7

int main(void) {
    // Task: Plan the program the program it!
    // Declare an integer array of size NUM_DAYS to store inputs
    int temperatures[NUM_DAYS];

    // Loop NUM_DAYS times, scanning a temperature and storing that input in an array
    printf("Enter temperatures:\n");
    for (int i = 0; i < NUM_DAYS; i++) {
        scanf("%d", &temperatures[i]);
    }

    // Declare a variable that will track the highest temperature
    int max_temperature = 0;

    // Loop through the inputs, printing them and keeping track of the maximum temperature
    printf("You entered: ");
    for (int i = 0; i < NUM_DAYS; i++) {
        printf("%d ", temperatures[i]);
        if (max_temperature < temperatures[i]) {
            max_temperature = temperatures[i];
        }
    }
    printf("\nMaximum: %d\n", max_temperature);
    
    return 0;
}

