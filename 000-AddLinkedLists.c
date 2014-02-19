#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Digit {
    int value;
    struct Digit *next;
} Digit;

Digit * create(int value);
Digit * createListFromString(char *string);
void addLinkedList(Digit *d1, Digit *d2, Digit *s, int c);


int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Invalid argument count. You must supply 2 numbers.\n");
        exit(0);
    }

    int j;
    int carry = 0;
    Digit *firstDigit,
          *secondDigit,
          *sum = create(0);

    // create pointers to the heads of the two lists
    firstDigit = createListFromString(argv[1]);
    secondDigit = createListFromString(argv[2]);

    printf("The two initial numbers are: %d and %d\n",
            firstDigit->value, secondDigit->value);

    addLinkedList(firstDigit, secondDigit, sum, carry);
}

// build the full number, starting from the beginning of the list
/*
string buildNumber(Digit *head)
{

}
*/

Digit * createListFromString(char *string)
{
    Digit *head = create(string[0] - '0'), *prev;

    int i;
    for (i = 0; i < strlen(string); i++) {
        if (i == 0) {
            prev = head;
        } else {
            prev->next = create(string[i] - '0');
            prev = prev->next;
        }
    }

    return head;
}

void addLinkedList(Digit *a, Digit *b, Digit *s, int c)
{
    printf("Called addLinkedList. Adding %d + %d + %d\n",
            a->value, b->value, c);
    s->value = a->value + b->value + c;

    c = 0;
    if (s->value > 9) {
        c = 1;
        s->value = s->value - 10;
    }

    printf("solution: %d\n", s->value);

    if (a->next == NULL)
        return;

    Digit * nextSum = create(0);
    s->next = nextSum;

    addLinkedList(a->next, b->next, s->next, c);
}

Digit * create(int value)
{
    Digit * newDigit = (Digit *)malloc(sizeof(Digit));

    if (newDigit == NULL) {
        printf("Error creating new node.\n");
        exit(0);
    }

    newDigit->value = value;
    return newDigit;
}

