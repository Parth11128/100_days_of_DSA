#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define HASH_SIZE 100003

int hash(int key) {
    if(key < 0) key = -key;
    return key % HASH_SIZE;
}

void insert(Node* hashMap[], int key) {
    int h = hash(key);
    Node* curr = hashMap[h];
    while(curr != NULL) {
        if(curr->key == key) {
            curr->value += 1;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = hashMap[h];
    hashMap[h] = newNode;
}

int get(Node* hashMap[], int key) {
    int h = hash(key);
    Node* curr = hashMap[h];
    while(curr != NULL) {
        if(curr->key == key)
            return curr->value;
        curr = curr->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* hashMap[HASH_SIZE] = {0};
    insert(hashMap, 0); 
    int prefixSum = 0;
    long long count = 0;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += get(hashMap, prefixSum);
        insert(hashMap, prefixSum);
    }

    printf("%lld\n", count);

    return 0;
}
