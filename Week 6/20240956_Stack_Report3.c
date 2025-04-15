#include <stdio.h>
#include <ctype.h>  // isdigit(), isalpha() 사용
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// 스택 초기화
void initStack(Stack* s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택에 요소 추가
void push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

// 스택에서 요소 제거
int pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

// 스택 최상단 요소 반환
int peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

// 연산자 우선순위 설정
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;  // 여는 괄호는 우선순위 비교 대상 아님
}

// 중위표기식을 후위표기식으로 변환
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

    // 계산 결과 출력
    int result = evaluatePostfix(postfix);
    printf("후위표기식 계산 결과: %d\n", result);
}


// Stack 구현코드는 위 코드 예시 활용
// 후위표기식을 계산하는 함수
int evaluatePostfix(char* postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // 피연산자 (숫자)
        if (isdigit(ch)) {
            push(&s, ch - '0');  // 문자 '3' → 숫자 3
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
    printf("중위표기식을 입력하세요: ");
    scanf_s("%s", &postfix, (unsigned)_countof(postfix));
    infixToPostfix(postfix);

    return 0;
}
