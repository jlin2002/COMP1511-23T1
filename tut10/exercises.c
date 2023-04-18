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
void challenge_0(void) {}

// Challenge 1: Count bigger
// Return the number of "bigger" values in an array 
// (i.e. greater than 99 or less than -99).
int challenge_1(int length, int array[]) {
    return 0;
}

// Challenge 2: Count favourite
// Return the number of elements divisible by 17
// in the linked list
int challenge_2(struct node *head) {
    return 0;
}

// Challenge 3: Reverse array
// Reverse the elements of the array, given its
// length.
void challenge_3(int length, int array[]) {}

// Challenge 4: Scan and print 5
// Write a procedure that scans numbers until CTRL-D
// and prints out the last 5 integers scanned in
// in the order they were scanned in.
// You may assume you will get at least 5 inputs.
void challenge_4(void) {}

// Challenge 5: Print missing lowercase letters
// Write a procedure that scans in a line and prints
// all the lower case letters that do not occur in that
// line in alphabetical order.
void challenge_5(void) {}

// Challenge 6: Linked list addition
// Given two numbers written as a linked list
// with the units digit as the head node
// return a new list representing their sum.
// For example, given the lists
// 3 -> 4 -> 7 -> X and 8 -> 9 -> 3 -> X
// The function should return a new list
// 1 -> 4 -> 1 -> 1 -> X
// because 743 + 398 = 1141
struct node *challenge_6(struct node *list1, struct node *list2) {
    return NULL;
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
