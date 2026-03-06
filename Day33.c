#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[100];
    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if(isalnum(c))
        {
            printf("%c", c);
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(peek() != '(')
                printf("%c", pop());
            pop();
        }
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}
