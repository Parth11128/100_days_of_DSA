#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;

void init() {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1)
            return 0;

        if (table[index] == key)
            return 1;
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
