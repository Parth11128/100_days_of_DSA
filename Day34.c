#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node** top, int* val) {
    if(*top == NULL) return NULL;
    struct Node* temp = *top;
    *val = temp->data;
    *top = temp->next;
    free(temp);
    return *top;
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);

    struct Node* stack = NULL;
    char* token = strtok(expr, " \n");

    while(token != NULL) {
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
            // operand
            stack = push(stack, atoi(token));
        } else {
            // operator
            int b, a;
            pop(&stack, &b);
            pop(&stack, &a);
            int result;
            if(token[0] == '+') result = a + b;
            else if(token[0] == '-') result = a - b;
            else if(token[0] == '*') result = a * b;
            else if(token[0] == '/') result = a / b;
            stack = push(stack, result);
        }
        token = strtok(NULL, " \n");
    }

    int finalResult;
    pop(&stack, &finalResult);
    printf("%d\n", finalResult);

    return 0;
}
