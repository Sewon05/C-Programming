#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1; 
}

void infixToPostfix(char* infix) {
    Stack s;
    initStack(&s);
    char postfix[MAX] = "";
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s); 
            }
            pop(&s);
        }
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    printf("후위표기식: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("중위표기식을 입력하세요: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}