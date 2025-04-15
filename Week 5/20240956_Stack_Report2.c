#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

int main() {
    char input[101];
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // 줄바꿈 제거
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // 스택 동적 할당
    char* stack = (char*)malloc(len * sizeof(char));
    if (stack == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    int top = -1;
    int isValid = 1;

    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;  // push
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(stack[top], ch)) {
                isValid = 0;
                break;
            }
            else {
                top--;  // pop
            }
        }
    }

    // 스택이 비어있지 않으면 유효하지 않음
    if (top != -1) {
        isValid = 0;
    }

    if (isValid)
        printf("유효한 괄호\n");
    else
        printf("유효하지 않은 괄호\n");

    free(stack);
    return 0;
}
