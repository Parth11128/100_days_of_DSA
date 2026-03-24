#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Check if deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1);
}

// Insert at front
void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        printf("No space at front\n");
    } else {
        front--;
    }
    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Removed: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Delete from rear
void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Removed: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front element
void getFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
    } else {
        printf("Front: %d\n", deque[front]);
    }
}

// Get rear element
void getBack() {
    if (isEmpty()) {
        printf("Deque is empty\n");
    } else {
        printf("Rear: %d\n", deque[rear]);
    }
}

// Get size
void size() {
    if (isEmpty()) {
        printf("Size: 0\n");
    } else {
        printf("Size: %d\n", rear - front + 1);
    }
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

// Reverse deque
void reverse() {
    if (isEmpty()) return;
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

// Sort deque (simple bubble sort)
void sort() {
    if (isEmpty()) return;
    for (int i = front; i <= rear; i++) {
        for (int j = front; j < rear; j++) {
            if (deque[j] > deque[j + 1]) {
                int temp = deque[j];
                deque[j] = deque[j + 1];
                deque[j + 1] = temp;
            }
        }
    }
}

// Clear deque
void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n");
        printf("5. Front\n6. Back\n7. Size\n8. Display\n");
        printf("9. Reverse\n10. Sort\n11. Clear\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;
            case 3:
                pop_front();
                break;
            case 4:
                pop_back();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getBack();
                break;
            case 7:
                size();
                break;
            case 8:
                display();
                break;
            case 9:
                reverse();
                printf("Deque reversed\n");
                break;
            case 10:
                sort();
                printf("Deque sorted\n");
                break;
            case 11:
                clear();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
