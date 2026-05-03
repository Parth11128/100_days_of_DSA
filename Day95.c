#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[k++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%.6f ", arr[i]);

    return 0;
}
