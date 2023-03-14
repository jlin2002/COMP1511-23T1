// Demo of string functions
// T17A, July 2022

#include <stdio.h>

// Provided functions
int is_lowercase(char c);
int is_uppercase(char c);
int is_letter(char c);
char to_lowercase(char c);
char to_uppercase(char c);
int is_vowel(char c);

// Functions to implement
int count_lowercase(char *string);
void make_vowels_uppercase(char *string);
void delete_following_words(char *string);

int main(void) {
    // Correct output:
    // 9
    // nO sArCASm InTENdEd!!!
    // nO

    char string[] = "nO sArCaSm InTeNdEd!!!";
    printf("%d\n", count_lowercase(string));

    make_vowels_uppercase(string);
    printf("%s\n", string);

    delete_following_words(string);
    printf("%s\n", string);


    return 0;
}

/*** Functions to implement ***/

// Returns the number of lowercase letters in `char *string`
int count_lowercase(char *string) {
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (is_lowercase(string[i])) {
            count++;
        }
    }
    return count;
}

// Modifies `char *string` by converting all its vowels to uppercase
void make_vowels_uppercase(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (is_vowel(string[i])) {
            string[i] = to_uppercase(string[i]);
        }
    }
}

// Shortens a string so that it ends after the first word
// e.g. "This is a sentence" should turn into:
//      "This"
void delete_following_words(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            string[i] = '\0';
            return;
        }
    }
}

/*** Provided Functions (Read the comments to find out what they do!) ***/

// Returns : 1 if `c` is a lowercase letter
//         : 0 otherwise.
int is_lowercase(char c) {

    return 'a' <= c && c <= 'z';
}

// Returns : 1 if `c` is an uppercase letter
//         : 0 otherwise.
int is_uppercase(char c) {

    return 'A' <= c && c <= 'Z';
}

// Returns : 1 if `c` is a letter
//         : 0 otherwise.
int is_letter(char c) {

    return is_lowercase(c) || is_uppercase(c);
}

// Returns : `c` converted to lowercase, if it was an uppercase letter
//         : `c` unmodified, otherwise
char to_lowercase(char c) {
    if (is_uppercase(c)){
        return c - 'A' + 'a';
    }

    return c;
}

// Returns : `c` converted to uppercase, if it was a lowercase letter
//         : `c` unmodified, otherwise
char to_uppercase(char c) {
    if (is_lowercase(c)) {
        return c - 'a' + 'A';
    }

    return c;
}

// Returns : 1 if `c` is an uppercase or lowercase vowel
//         : 0 otherwise.
int is_vowel(char c) {
    char lower_c = to_lowercase(c);

    return lower_c == 'a' 
        || lower_c == 'e'
        || lower_c == 'i' 
        || lower_c == 'o' 
        || lower_c == 'u';
}
