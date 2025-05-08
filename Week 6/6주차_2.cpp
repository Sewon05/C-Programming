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

int evaluatePostfix(char* postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        else {
            int b = pop(&s);
            int a = pop(&s);
            int result;

            switch (ch) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default:
                printf("Invalid operator encountered.\n");
                exit(1);
            }

            push(&s, result);
        }
    }

    return pop(&s);
}

int main() {
    char postfix[MAX] = "12+5*";
    printf("후위표기식 계산 결과: %d\n", evaluatePostfix(postfix));
    return 0;
}