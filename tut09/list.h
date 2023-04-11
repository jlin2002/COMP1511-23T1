// Emily Chen & Tom Kunc
// Defines a linked list and basic functions to debug it

struct node {
	int data;		        // data item at this node
	struct node *next;		// pointer to the next node
};


// Append to a linked list
struct node *append_node(struct node *head, int data);

// Returns a copy of the linked list
struct node *copy(struct node *head);

// Returns a list containing a copy of list2 appended to a copy of 
// list1. The original lists are NOT modified
struct node *append(struct node *list1, struct node *list2);

// Prints the data of a linked list
void print_list(struct node *head);

// Prints the data of a linked list alongside the node address
void print_list_with_addresses(struct node *head);

// Frees all the elements in a linked list
void free_list(struct node *head);

struct node *create_node(int data);
