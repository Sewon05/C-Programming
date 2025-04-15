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
    printf("���ڿ��� �Է��ϼ���: ");
    fgets(input, sizeof(input), stdin);

    // �ٹٲ� ����
    size_t len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // ���� ���� �Ҵ�
    char* stack = (char*)malloc(len * sizeof(char));
    if (stack == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
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

    // ������ ������� ������ ��ȿ���� ����
    if (top != -1) {
        isValid = 0;
    }

    if (isValid)
        printf("��ȿ�� ��ȣ\n");
    else
        printf("��ȿ���� ���� ��ȣ\n");

    free(stack);
    return 0;
}
