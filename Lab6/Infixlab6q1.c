#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}


void push(char c) {
    if (!isFull()) {
        stack[++top] = c;
    }
}


char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0';
}

int isOperator(char c) {

    return (!isalpha(c) && !isdigit(c));

}

int getPriority(char C) {
    if (C == '-' || C == '+') {
        return 1;
    } else if (C == '*' || C == '/') {
        return 2;
    } else if (C == '^') {
        return 3;
    }
    return 0;
}

void infixToPostfix(char* infix, char* output) {
    int k = 0;
    int l = strlen(infix);

    char newInfix[MAX];

    snprintf(newInfix, MAX, "(%s)", infix);

    for (int i = 0; i < l + 2; i++) {
        if (isalpha(newInfix[i]) || isdigit(newInfix[i])) {
            output[k++] = newInfix[i];
        }

        else if (newInfix[i] == '(') {
            push('(');
       }
        else if (newInfix[i] == ')') {
            while (peek() != '(') {
                output[k++] = pop();
            }
            pop();
        } else {

            if (isOperator(peek())) {

                if (newInfix[i] == '^') {

                    while (getPriority(newInfix[i]) <= getPriority(peek())) {

                        output[k++] = pop();

                    }

                } else {

                    while (getPriority(newInfix[i]) < getPriority(peek())) {

                        output[k++] = pop();

                    }

                }

            }

            push(newInfix[i]);

        }

    }

    while (!isEmpty()) {

        output[k++] = pop();

    }

    output[k] = '\0';

}

void reverse(char* str) {

    int n = strlen(str);

    for (int i = 0; i < n / 2; i++) {

        char temp = str[i];

        str[i] = str[n - i - 1];

        str[n - i - 1] = temp;

    }

}

void infixToPrefix(char* infix, char* result) {
    int l = strlen(infix);
    reverse(infix);
    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {

            infix[i] = ')';

        } else if (infix[i] == ')') {

            infix[i] = '(';

        }

    }

    infixToPostfix(infix, result);

    reverse(result);

}



int main() {

    char infix[MAX];
    char result[MAX];

    printf("Enter Infix Expression: ");

    scanf("%s", infix);

    infixToPrefix(infix, result);
    printf("Prefix Expression: %s\n", result);

    return 0;

}
