//Write a program that converts a prefix expression to a fully parenthesized infix
//expression.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX][10];
int top = -1;

void push(char* c) {
    strcpy(stack[++top], c);
}

char* pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return "";
    }
    return stack[top--];
}

void prefixToInfix(char* prefix) {
    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            char* operand2 = pop();
            char* operand1 = pop();
            char temp[20];
            sprintf(temp, "(%s %c %s)", operand2, prefix[i], operand1);
            push(temp);
        } else {
            char temp[2];
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }
    }

    printf("%s", pop());
}

int main() {
    char prefix[] = "*-/+ABCDE";
    printf("Prefix expression: %s\n", prefix);
    printf("Infix expression: ");
    prefixToInfix(prefix);
    return 0;
}
