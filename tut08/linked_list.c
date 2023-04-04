#include <stdlib.h>
#include <stdio.h>
#define MAX_LENGTH 50

struct node {
    int data;
    struct node *next;
};

// Task 5: Write a function "append" that
// takes a pointer to the head of a linked list and an integer
// inserts a node containing that integer at the end of the linked list,
// then returns the head of the list.
struct node *append(struct node *head, int data);
// Task 7: Write a function "insert" that
// takes a pointer to the head of a linked list and 2 integers,
// data and position
// inserts a node containing data at the given position* in the linked list
// then returns the head of the list.
// *position 0 corresponds to the start of the list
struct node *insert(struct node *head, int data, int position);
// Task 9: Write a function "print_list" that
// takes a pointer to the head of a linked list
// prints the elements of the list.
// For a list of length 3, containing elements 3, 1 and 4, the function
// should print 3 -> 1 -> 4 -> X
void print_list(struct node *head);
struct node *create_node(int data);

int main(void) {
    struct node *head = create_node(0);
    // Task 2: Change the data field to 3 
    head->data = 3;

    // Task 3: Add a single node after head containing value 1

    // head->next = create_node(1);

    // Task 4: Add two more nodes after the element we just added
    // containing values 4 and 5. Is this scaleable?

    // head->next->next = create_node(4);
    // head->next->next->next = create_node(5);

    // Task 6: Modify the code you wrote in task 3 and 4 to use
    // the append function you wrote.
    append(head, 1);
    append(head, 4);
    append(head, 5);
    
    // Task 8: Insert 1 at position 3 of the linked list starting
    // at head.
    insert(head, 1, 3);

    // Task 10: Print the linked list
    print_list(head);

    return 0;
}

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

struct node *insert(struct node *head, int data, int position) {
    struct node *new_node = create_node(data);
    if (position == 0 || head == NULL) {
        new_node->next = head;
        return new_node;
    }

    struct node *curr = head;
    int i = 0;
    while (curr->next != NULL && i < position - 1) {
        curr = curr->next;
        i++;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data); 
        curr = curr->next;
    }
    printf("X\n");
}

struct node *create_node(int data) {
    // Task 1: Modify this function so that it works.
    struct node *new_node = malloc(sizeof(struct node)); 
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

