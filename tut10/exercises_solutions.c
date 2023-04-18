#include <stdio.h>
#include <stdlib.h>

#define STR_LENGTH 100

struct node {
  struct node *next;
  int data;
};

/*** FUNCTIONS TO IMPLEMENT ***/
void challenge_0(void);
int challenge_1(int length, int array[]);
int challenge_2(struct node *head);
void challenge_3(int length, int array[]);
void challenge_4(void);
void challenge_5(void);
struct node *challenge_6(struct node *list1, struct node *list2);

/*** PROVIDED FUNCTIONS ***/
struct node *create_node(int data);
struct node *append(struct node *head, int data);
void print_list(struct node *head);

int main(void) {
    // Write any code here to debug your "challenge" functions...
    // E.g...
    // struct node *head = append(NULL, 17);
    // head = append(head, 34);
    // head = append(head, 30);
    // if (challenge_2(head) == 2) {
    //   printf("Challenge 2: Success\n");
    // } else {
    //   printf("Challenge 2: Fail\n");
    // }
    struct node *list1 = append(NULL, 3);
    append(list1, 4);
    append(list1, 7);

    struct node *list2 = append(NULL, 8);
    append(list2, 9);
    append(list2, 3);
    print_list(challenge_6(list1, list2));
    return 0;
}

/*** FUNCTIONS TO IMPLEMENT ***/
// Challenge 0: echo twice.
// Write a procedure that scans in a line of input
// and then prints it twice.
void challenge_0(void) {
    char string[STR_LENGTH];
    fgets(string, STR_LENGTH, stdin);
    printf("%s", string);
    printf("%s", string);
}

// Challenge 1: Count bigger
// Return the number of "bigger" values in an array 
// (i.e. greater than 99 or less than -99).
int challenge_1(int length, int array[]) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] < -99 || array[i] > 99) {
            count++;
        }
    }
    return count;
}

// Challenge 2: Count favourite
// Return the number of elements divisible by 17
// in the linked list
int challenge_2(struct node *head) {
    int count = 0;
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->data % 17 == 0) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

// Challenge 3: Reverse array
// Reverse the elements of the array, given its
// length.
void challenge_3(int length, int array[]) {
    // Solution 1
    // for (int i = 0; i < length / 2; i++) {
    //     int temp = array[i];
    //     array[i] = array[length - 1 - i];
    //     array[length - 1 - i] = temp;
    // }

    // Solution 2
    int *reverse_array = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        reverse_array[length - 1 - i] = array[i];
    }

    for (int i = 0; i < length; i++) {
        array[i] = reverse_array[i];
    }
    free(reverse_array);
}

// Challenge 4: Scan and print 5
// Write a procedure that scans numbers until CTRL-D
// and prints out the last 5 integers scanned in
// in the order they were scanned in.
// You may assume you will get at least 5 inputs.
void challenge_4(void) {
    int num;
    int i = 0;
    int last_five[5] = {};
    while (scanf("%d", &num) == 1) {
        last_five[i % 5] = num;
        i++;
    }

    for (int j = 0; j < 5; j++) {
        printf("%d ", last_five[(i + j) % 5]);
    }
    printf("\n");
}

// Challenge 5: Print missing lowercase letters
// Write a procedure that scans in a line and prints
// all the lower case letters that do not occur in that
// line in alphabetical order.
void challenge_5(void) {
    int is_present[26] = {};
    char string[STR_LENGTH];
    fgets(string, STR_LENGTH, stdin);
    for (int i = 0; string[i] != '\0'; i++) {
        if ('a' <= string[i] && string[i] <= 'z') {
            is_present[string[i] - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!is_present[i]) {
            printf("%c", i + 'a');
        }
    }
    printf("\n");
}

// Challenge 6: Linked list addition
// Given two numbers written as a linked list,
// return a new list representing their sum.
// For example, given the lists
// 3 -> 4 -> 7 -> X and 8 -> 9 -> 3 -> X
// The function should return a new list
// 1 -> 4 -> 1 -> 1 -> X
// because 743 + 398 = 1141
struct node *challenge_6(struct node *list1, struct node *list2) {
    struct node *answer = NULL;
    struct node *answer_curr = NULL;
    // Start at first node, take the sum, keep track of a carry, create a node out of the sum
    // and keep going until we reach the end of one of the lists
    int carry = 0;
    struct node *curr1 = list1;
    struct node *curr2 = list2;
    while (curr1 != NULL && curr2 != NULL) {
        int curr_sum = curr1->data + curr2->data + carry;
        carry = curr_sum / 10;
        struct node *sum_node = create_node(curr_sum % 10);
        if (answer == NULL) {
            answer = sum_node;
        } else {
            answer_curr->next = sum_node; 
        }
        answer_curr = sum_node;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    // Collect the remaining nodes of the list we haven't yet exhausted and put it in our
    // solution
    while (curr1 != NULL) {
        int curr_sum = curr1->data + carry;
        carry = curr_sum / 10;
        answer_curr->next = create_node(curr_sum % 10);
        answer_curr = answer_curr->next;
        curr1 = curr1->next;
    }
    
    while (curr2 != NULL) {
        int curr_sum = curr2->data + carry;
        carry = curr_sum / 10;
        answer_curr->next = create_node(curr_sum % 10);
        answer_curr = answer_curr->next;
        curr2 = curr2->next;
    }
    
    // Add on the carry if any left
    if (carry != 0) {
        answer_curr->next = create_node(carry);
    }
    
    return answer; 
}


/*** PROVIDED FUNCTIONS ***/
struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Appends a node containing given data to the provided
// list. Returns the head of the new list
struct node *append(struct node *head, int data) {
  struct node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  struct node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
  return head;
}

void print_list(struct node *head) {
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d -> ", curr->data);
    }
    printf("X\n");
}
