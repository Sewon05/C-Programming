#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int top;
	int capacity;
} Stack;

void initStack(Stack* s, int initialSize) {
	s->data = (int*)malloc(initialSize * sizeof(int));
	if (s->data == NULL) {
		printf("메모리 할당 실패!\n");
		exit(1);
	}
	s->top = -1;
	s->capacity = initialSize;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

int isFull(Stack* s) {
	return s->top == s->capacity - 1;
}

void expandStack(Stack* s) {
	int newCapacity = s->capacity + 5;
	int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));
	if (newData == NULL) {
		printf("메모리 재할당 실패!\n");
		exit(1);
	}
	s->data = newData;
	s->capacity = newCapacity;
	printf("스택 용량이 %d로 증가했습니다.\n", s->capacity);
}

void push(Stack* s, int value) {
	if (isFull(s)) {
		expandStack(s);
	}
	s->data[++(s->top)] = value;
	printf("%d을(를) 스택에 추가했습니다.\n", value);
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("스택 언더플로우! 제거할 요소가 없습니다.\n");
		return -1;
	}
	printf("제거된 값 : %d\n", s->data[s->top]);
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("스택이 비어 있습니다! 확인할 값이 없습니다.\n");
		return -1;
	}
	printf("최상단 값 : %d\n", s->data[s->top]);
	return s->data[s->top];
}

void display(Stack* s) {
	if (isEmpty(s)) {
		printf("스택이 비어 있습니다!\n");
		return;
	}
	printf("스택 내용 : ");
	for (int i = 0; i <= s->top; i++) {
		printf("%d", s->data[i]);
	}
	printf("\n");
}

void freeStack(Stack* s) {
	free(s->data);
	printf("스택 메모리를 해제했습니다.\n");
}

int main() {
	Stack s;
	initStack(&s, 5);

	int choice, value;
	while (1) {
		printf("\n---스택 메뉴---\n");
		printf("1. 추가 (Push)\n)");
		printf("2. 제거 (Pop)\n)");
		printf("3. 최상단 값 확인 (Peek)\n)");
		printf("4. 스택 내용 출력\n)");
		printf("5. 종료\n)");
		printf("매뉴를 선택하세요 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("스택에 추가할 값을 입력하세요 : ");
			scanf("%d", &value);
			push(&s, value);
			break;
		case 2:
			pop(&s);
			break;
		case 3:
			peek(&s);
			break;
		case 4:
			display(&s);
			break;
		case 5:
			freeStack(&s);
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("잘못된 선택입니다! 1에서 5 사이의 숫자를 입력해주세요.\n");
		}
	}
}