#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);  // 추가된 함수

int main() {
    int scores[30];
    int studentNumber;
    double average;
    int option;

    srand(time(0));

    // 성적 초기화
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101;
    }

    // 평균 계산
    average = calculateAverage(scores, 30);
    printf("학급 평균 점수: %.2f\n", average);

    // 특정 학생 점수 확인
    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }

    // 옵션 테스트: 0 - 전체, 1 - 평균 이상, 2 - 평균 미만
    printf("\n[모든 학생 점수 출력]\n");
    printScore(scores, 30, average, 0);

    printf("\n[평균 이상 학생 점수 출력]\n");
    printScore(scores, 30, average, 1);

    printf("\n[평균 미만 학생 점수 출력]\n");
    printScore(scores, 30, average, 2);

    return 0;
}

// 평균 계산 함수
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

// 특정 학생 점수 검색 함수
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1;
    }
}

// 평균 기준 출력 함수
void printScore(int scores[], int size, double average, int option) {
    for (int i = 0; i < size; i++) {
        int score = *(scores + i); // 포인터 방식 접근
        int studentNum = i + 1;

        if (option == 0 || (option == 1 && score >= average) || (option == 2 && score < average)) {
            printf("%2d번 학생: %3d점\n", studentNum, score);
        }
    }
}
