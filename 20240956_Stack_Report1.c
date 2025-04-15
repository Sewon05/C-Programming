#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101];  // �ִ� 100�� + null ����
    printf("���ڿ��� �Է��ϼ���: ");
    fgets(input, sizeof(input), stdin);

    // �ٹٲ� ���ڰ� ������ ����
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

    // ���ڿ��� ���ÿ� Ǫ��
    for (size_t i = 0; i < len; i++) {
        stack[i] = input[i];
    }

    // ���ÿ��� ���ϸ� ���
    printf("�Ųٷ� ��µ� ���ڿ�: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(stack[i]);
    }
    printf("\n");

    // �޸� ����
    free(stack);
    return 0;
}
