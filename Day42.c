#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

// Stack implementation
int stack[MAX];
int top = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

// Stack functions
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1)
        return -1;

    return stack[top--];
}

// Reverse Queue using Stack
void reverseQueue() {
    // Step 1: Dequeue all elements and push to stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Pop from stack and enqueue back
    while (top != -1) {
        enqueue(pop());
    }
}

// Main function
int main() {
    int N, x;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue();

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
