#include <stdio.h>
#include <ctype.h>

int is_operand(char c) {
    return isdigit(c);
}

double evaluate_prefix(char *expr) {
    int len = strlen(expr);
    char stack[len];
    int top = -1;

    for (int i = len - 1; i >= 0; i--) {
        char ch = expr[i];

        if (is_operand(ch)) {
            stack[++top] = ch - '0';
        } else {
            double operand1 = stack[top--];
            double operand2 = stack[top--];

            switch (ch) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    stack[++top] = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return -1;
            }
        }
    }

    return stack[top];
}

int main() {
    char expression[] = "-*+4325";

    double result = evaluate_prefix(expression);
    if (result != -1) {
        printf("The result of the prefix expression is: %.2lf\n", result);
    }

    return 0;
}
