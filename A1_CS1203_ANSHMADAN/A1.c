#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
typedef struct node {
    int data;            // Data stored in the node
    struct node *next;   // Pointer to the next node in the queue
} NODE, *NODEPTR;

// Define the structure for the queue
typedef struct queue {
    NODEPTR front, rear; // Pointers to the front and rear of the queue
} QUEUE;

// Function to create a new node
NODEPTR createNode(int val) {
    NODEPTR p = (NODEPTR)malloc(sizeof(NODE)); // Allocate memory for a new node
    if (p == NULL) { // Check if memory allocation was successful
        perror("Memory allocation failed");
        exit(EXIT_FAILURE); // Exit the program if allocation failed
    }
    p->data = val; // Set the data field of the new node to the given value
    p->next = NULL; // Initialize the next pointer to NULL
    return p; // Return a pointer to the newly created node
}

// Function to insert an element into the queue
void insert(QUEUE *q, int elm) {
    NODEPTR temp = createNode(elm); // Create a new node with the given element
    if (q->front == NULL) { // If the queue is empty
        q->front = temp; // Both front and rear pointers point to the new node
        q->rear = temp;
    } else {
        q->rear->next = temp; // Link the new node to the rear of the queue
        q->rear = temp; // Update the rear pointer to the new node
    }
}

// Function to delete an element from the front of the queue
int delete(QUEUE *q) {
    if (q->front == NULL) { // If the queue is empty
        fprintf(stderr, "Queue is empty\n"); // Print an error message
        exit(EXIT_FAILURE); // Exit the program with an error
    }
    NODEPTR temp = q->front; // Create a temporary pointer to the front node
    int elm = temp->data; // Get the data from the front node
    q->front = q->front->next; // Move the front pointer to the next node
    free(temp); // Free the memory of the deleted node
    return elm; // Return the deleted element
}

// Function to print the elements in the queue
void printQueue(QUEUE q) {
    NODEPTR temp = q.front; // Create a temporary pointer starting from the front
    printf("Queue: ");
    while (temp != NULL) { // Iterate through the queue until the end
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

int main() {
    QUEUE q = {NULL, NULL}; // Initialize an empty queue
    int choice, element;

    // Main menu loop
    while (1) {
        printf("0. Exit\n1. Delete\n2. Insert\n3. Print Queue\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(EXIT_SUCCESS); // Exit the program with a success status
            case 1:
                if (q.front != NULL) { // If the queue is not empty
                    printf("Deleted value: %d\n", delete(&q)); // Delete and print the deleted value
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 2:
                printf("Element you want to insert: ");
                scanf("%d", &element);
                insert(&q, element); // Insert an element into the queue
                break;
            case 3:
                printQueue(q); // Print the elements in the queue
                break;
            default:
                printf("Invalid choice\n"); // Print an error message for an invalid choice
        }
    }

    return 0;
}
