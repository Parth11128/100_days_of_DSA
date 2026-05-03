#include <stdio.h>

int sum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

int isPossible(int arr[], int n, int k, int limit) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > limit)
            return 0;

        if (time + arr[i] <= limit) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = 0;
    int high = sum(arr, n);
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
