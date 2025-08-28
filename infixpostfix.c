#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char val) {
    if (top == MAX - 1) {
        printf("\nSTACK OVERFLOW\n");
    } else {
        st[++top] = val;
    }
}

char pop() {
    if (top == -1) {
        printf("\nSTACK UNDERFLOW\n");
        return '\0';
    } else {
        return st[top--];
    }
}

int getPriority(char op) {
    if (op == '*' || op == '/' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    else
        return -1;
}

void InfixToPostfix(char source[], char target[]) {
    int i = 0, j = 0;

    while (source[i] != '\0') {
        if (source[i] == '(') {
            push(source[i]);
        } else if (source[i] == ')') {
            while (top != -1 && st[top] != '(') {
                target[j++] = pop();
            }
            if (top == -1) {
                printf("\nINCORRECT EXPRESSION\n");
                exit(1);
            }
            pop(); // Remove '('
        } else if (isalnum(source[i])) {
            target[j++] = source[i];
        } else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                   source[i] == '/' || source[i] == '%') {
            while (top != -1 && st[top] != '(' &&
                   getPriority(st[top]) >= getPriority(source[i])) {
                target[j++] = pop();
            }
            push(source[i]);
        } else if (source[i] != ' ') {
            printf("\nINVALID CHARACTER IN EXPRESSION\n");
            exit(1);
        }
        i++;
    }

    while (top != -1 && st[top] != '(') {
        target[j++] = pop();
    }

    target[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline

    InfixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

