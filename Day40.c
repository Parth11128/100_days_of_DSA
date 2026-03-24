#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;        // root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {

    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// Display array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array (Ascending): ");
    printArray(arr, n);

    return 0;
}
