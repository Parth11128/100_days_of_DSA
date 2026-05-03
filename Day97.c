#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compareStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int compareEnd(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), compareStart);

    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    heap[size++] = arr[0].end;

    for (int i = 1; i < n; i++) {
        qsort(heap, size, sizeof(int), compareEnd);

        if (arr[i].start >= heap[0]) {
            heap[0] = arr[i].end;
        } else {
            heap[size++] = arr[i].end;
        }
    }

    printf("%d", size);

    free(heap);
    return 0;
}
