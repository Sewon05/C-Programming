#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101];  // 최대 100자 + null 문자
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // 줄바꿈 문자가 있으면 제거
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

    // 문자열을 스택에 푸시
    for (size_t i = 0; i < len; i++) {
        stack[i] = input[i];
    }

    // 스택에서 팝하며 출력
    printf("거꾸로 출력된 문자열: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(stack[i]);
    }
    printf("\n");

    // 메모리 해제
    free(stack);
    return 0;
}
