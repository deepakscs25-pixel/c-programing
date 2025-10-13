#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  

#define Max 50

char stack[Max];
int top = -1;

void push(char c) {
    if(top == Max - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if(top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if(top == -1)
        return -1;
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int associativity(char op) {
    
    if (op == '^')
        return 1;
    return 0;
}

void infixtopostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    for(i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while(peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            if (peek() == '(')
                pop(); 
        }
        else { 
            while(top != -1 && (
                (precedence(peek()) > precedence(c)) ||
                (precedence(peek()) == precedence(c) && associativity(c) == 0)
            )) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[Max], postfix[Max];

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
