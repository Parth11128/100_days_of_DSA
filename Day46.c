#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Queue for traversal
struct Node* queue[100];
int front = 0, rear = -1;

// Enqueue
void enqueue(struct Node* node) {
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(curr->left);

        if (curr->right)
            enqueue(curr->right);
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
