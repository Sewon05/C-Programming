#include <stdio.h>
#include <ctype.h>  // isdigit(), isalpha() ���
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack* s) {
    s->top = -1;
}

// ������ ������� Ȯ��
int isEmpty(Stack* s) {
    return s->top == -1;
}

// ���ÿ� ��� �߰�
void push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

// ���ÿ��� ��� ����
int pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

// ���� �ֻ�� ��� ��ȯ
int peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

// ������ �켱���� ����
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;  // ���� ��ȣ�� �켱���� �� ��� �ƴ�
}

// ����ǥ����� ����ǥ������� ��ȯ
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

    printf("����ǥ���: %s\n", postfix);

    // ��� ��� ���
    int result = evaluatePostfix(postfix);
    printf("����ǥ��� ��� ���: %d\n", result);
}


// Stack �����ڵ�� �� �ڵ� ���� Ȱ��
// ����ǥ����� ����ϴ� �Լ�
int evaluatePostfix(char* postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // �ǿ����� (����)
        if (isdigit(ch)) {
            push(&s, ch - '0');  // ���� '3' �� ���� 3
        }
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            int result = 0;

            switch (ch) {
            case '+': result = val1 + val2; break;
            case '-': result = val1 - val2; break;
            case '*': result = val1 * val2; break;
            case '/': result = val1 / val2; break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}


int main() {
    char postfix[MAX];
    printf("����ǥ����� �Է��ϼ���: ");
    scanf_s("%s", &postfix, (unsigned)_countof(postfix));
    infixToPostfix(postfix);

    return 0;
}