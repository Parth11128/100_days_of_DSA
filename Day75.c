#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[MAX];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (prefix[i] == 0)
            maxLen = i + 1;

        for (int j = i + 1; j < n; j++) {
            if (prefix[j] == prefix[i]) {
                int len = j - i;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d", maxLen);

    return 0;
}
