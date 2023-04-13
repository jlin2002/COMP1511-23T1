// Program to do various linked list exercises
// <CLASS>, <MONTH YEAR>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
    struct node *list1 = append_node(NULL, 3);
    append_node(list1, 1);
    append_node(list1, 4);
    struct node *list2 = append_node(NULL, 1);
    append_node(list2, 5);
    append_node(list2, 9);

    // Task 4: Use the append function to create a list containing the
    // nodes of list1 followed by the nodes of list2 and print the
    // list
    // The list should be
    // 3 -> 1 -> 4 -> 1 -> 5 -> 9 -> X
    struct node *joined_list = append(list1, list2);
    print_list(joined_list);
    free_list(list1);
    free_list(list2);
    // Task 5: Deal with the final memory leak!
    free_list(joined_list);
    return 0;
}

/** PRESCRIBED FUNCTIONS **/
struct node *append_node(struct node *head, int data) {
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

// Task 2: Implement the copy function
// Returns a copy of the list
struct node *copy(struct node *list) {
    struct node *head_copy = NULL;
    struct node *curr_copy = NULL;
    struct node *curr = list;
    while (curr != NULL) {
        struct node *new_node = create_node(curr->data);
        if (head_copy == NULL) {
            head_copy = new_node;
        } else {
            curr_copy->next = new_node;
        }
        curr_copy = new_node;
        curr = curr->next;
    }
    return head_copy;
}

// Task 3: Implement the append function
// Returns a list containing a copy of list2 appended to a copy of
// list1. The original lists are NOT modified.
struct node *append(struct node *list1, struct node *list2) {
    if (list1 == NULL) {
        return copy(list2);
    }
    struct node *list1_copy = copy(list1);
    struct node *list2_copy = copy(list2);
    struct node *curr = list1_copy;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = list2_copy;
    return list1_copy;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

void print_list_with_addresses(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d (%p) -> ", curr->data, curr);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Frees all memory associated with list.
void free_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        struct node *del_node = curr;
        curr = curr->next;
        free(del_node);
    }
}
