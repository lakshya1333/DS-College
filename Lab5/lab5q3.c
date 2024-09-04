//Write a program that converts a post fix expression to a fully parenthesized infix
//expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

 void postfixToInfix(char* exp) {
    char stack[100][100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
         if (isOperand(exp[i])) {
            char op[2] = {exp[i], '\0'};
            strcpy(stack[++top], op);
        } else {
             char op1[100], op2[100], temp[100];
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            sprintf(temp, "(%s%c%s)", op2, exp[i], op1);
            strcpy(stack[++top], temp);
        }
    }

     printf("Infix Expression: %s\n", stack[top]);
}

int main() {
    char exp[100];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    postfixToInfix(exp);
    return 0;
}
