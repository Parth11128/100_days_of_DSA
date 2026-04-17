#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


struct Node* queue[1000];
int front = 0, rear = 0;


void enqueue(struct Node* node) {
    queue[rear++] = node;
}


struct Node* dequeue() {
    return queue[front++];
}


int isEmpty() {
    return front == rear;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* current = dequeue();

        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* q[1000];
    int f = 0, r = 0;

    q[r++] = root;
    int leftToRight = 1;

    while (f < r) {
        int size = r - f;
        int level[1000];

        for (int i = 0; i < size; i++) {
            struct Node* temp = q[f++];
            level[i] = temp->data;

            if (temp->left)
                q[r++] = temp->left;
            if (temp->right)
                q[r++] = temp->right;
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
