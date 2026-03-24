#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
