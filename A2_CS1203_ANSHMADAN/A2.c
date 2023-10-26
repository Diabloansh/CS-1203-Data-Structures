#include <stdio.h>
#include <stdlib.h>
#define bool int

// Structure to represent a binary tree node
struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};

// Structure to represent a node in the stack for iterative traversal
struct sNode {
    struct tNode* t;
    struct sNode* next;
};

// Function to push a node onto the stack
void push(struct sNode** top_ref, struct tNode* t) {
    struct sNode* newStackNode = (struct sNode*)malloc(sizeof(struct sNode));
    newStackNode->t = t;
    newStackNode->next = (*top_ref);
    (*top_ref) = newStackNode;
}

// Function to check if the stack is empty
bool isEmpty(struct sNode* top) {
    return (top == NULL) ? 1 : 0;
}

// Function to pop a node from the stack
struct tNode* pop(struct sNode** top_ref) {
    struct tNode* res;
    struct sNode* top;

    if (isEmpty(*top_ref)) {
        printf("Stack Underflow\n");
        getchar();
        exit(0);
    }
    else {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

// Function to create a new binary tree node
struct tNode* newtNode(int data) {
    struct tNode* tNode = (struct tNode*)malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;
    return (tNode);
}

// Function for iterative inorder traversal
void inOrder(struct tNode* root) {
    struct tNode* current = root;
    struct sNode* s = NULL;
    bool done = 0;

    while (!done) {
        if (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        else {
            if (!isEmpty(s)) {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}

// Function to print a horizontal representation of the binary tree structure
void printTree(struct tNode* root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Print left subtree
    printTree(root->left, space);
}

int main() {
    // Create a different binary tree structure
    struct tNode* root = newtNode(10);
    root->left = newtNode(7);
    root->right = newtNode(15);
    root->left->left = newtNode(3);
    root->left->right = newtNode(8);
    root->right->left = newtNode(12);
    root->right->right = newtNode(18);

    // Perform an inorder traversal and print the result
    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    // Print the binary tree structure
    printf("Binary Tree Structure:\n");
    printTree(root, 0);

    getchar();
    return 0;
}
