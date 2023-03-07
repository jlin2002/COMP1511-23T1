// A program that asks the user to enter temperatures until the input is CTRL+D
// Right after entering each temperature, the program prints
//   "High" if the temperature is over 30 degrees
//   "Moderate" if the temperature is over 20 degrees and less than or equal to
//   30 degrees
//   "Low" if the temperature is less than or equal to 20 degrees.
//   Then prompts the user to enter temperature again

// Joanna Lin, March 2023

#include <stdio.h>

int main(void) {
    // Task: Plan the program! The following line is a hint:
    // int result = scanf("%d", &temperature);

    // Initialise a variable to store temperature input.
    int temperature;
    // Prompt the user for a temperature.
    printf("Enter temperature: ");
    // Using scanf return in a loop...
    while (scanf("%d", &temperature) == 1) {
        // Use if statements to accomplish the above!
        if (temperature > 30) {
            printf("High\n");
        } else if (temperature > 20) {
            printf("Moderate\n");
        } else {
            printf("Low\n");
        }
        // Prompt the user for another temperature
        printf("Enter temperature: ");
    }

    return 0;
}
