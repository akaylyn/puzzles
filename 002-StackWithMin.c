#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Node structure:
 *
 * Each node has a pointer to the min value at the time it was
 * added to the stack.
 */
typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *min;
} Node;

/**
 * Stack structure:
 *
 * The stack keeps a pointer to the top.
 */
typedef struct Stack {
    Node *top;
} Stack;

void printStack(Node *curr);
void push(Stack *stack, Node *node);
void pop(Stack *stack);
int min(Stack *stack);
Node * createNode(int value);
Stack * createStack();

int main()
{
    Stack *stack = createStack();
    Node *a = createNode(15);
    Node *b = createNode(3);
    Node *c = createNode(2);
    Node *d = createNode(12);

    push(stack, a);
    push(stack, b);
    push(stack, c);
    push(stack, d);

    pop(stack);

    printStack(stack->top);
    printf("The minimum value in the stack is: %d\n", min(stack));

    return 0;
}

void printStack(Node *curr)
{
    if (curr == NULL) {
        return;
    }

    printf("%d, curr min: %d\n", curr->value, curr->min->value);
    printStack(curr->prev);
}

void push(Stack *stack, Node *node)
{
    node->prev = stack->top;
    stack->top = node;

    if (node->prev == NULL) {
        return;
    }

    // determine if the newest node is the new min node
    // in the future, consider doing this above for less de-referencing
    if (node->value < node->prev->min->value) {
        node->min = node;
    } else {
        node->min = node->prev->min;
    }
}

void pop(Stack *stack)
{
    stack->top = stack->top->prev;
}

int min(Stack *stack)
{
    return stack->top->min->value;
}

Node * createNode(int value)
{
   Node *newNode = malloc(sizeof(Node));

   if (newNode == NULL) {
       printf("Error creating new node.\n");
       exit(0);
   }

   newNode->min = newNode;
   newNode->value = value;
   return newNode;
}

Stack * createStack()
{
    Stack *newStack = malloc(sizeof(Stack));

    if (newStack == NULL) {
        printf("Error creating new stack.\n");
        exit(0);
    }

    return newStack;
}

