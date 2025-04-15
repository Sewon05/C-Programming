#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);
void deleteStudent(int* scores, int size, int studentNumber);

int main() {
    int* scores;
    int size = 30;
    int capacity = 30;
    int choice, studentNumber;

    scores = (int*)malloc(capacity * sizeof(int));
    if (!scores) {
        printf("allocation error\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < size; i++) scores[i] = rand() % 101;
    printf("입력 완료\n");

    while (1) {
        printf("\n---학생 성적 관리 프로그램---\n");
        printf("1. 학생정보 추가\n");
        printf("2. 학생정보 삭제\n");
        printf("3. 학생정보 검색\n");
        printf("4. 학생정보 출력(옵션 : 0, 1, 2)\n");
        printf("5. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        // 운영체제에 따라 콘솔 정리
        system("cls");

        switch (choice) {
        case 1: // add
            if (capacity - size < 5) {
                capacity += 10;
                int* newScores = realloc(scores, capacity * sizeof(int));
                if (!newScores) {
                    printf("allocation error\n");
                    free(scores);
                    return 1;
                }
                scores = newScores;
            }
            int newScore = rand() % 101;
            scores[size] = newScore;
            size++;
            printf("새로운 학생 추가 : 번호 - %d, 점수 - %d\n", size, newScore);
            break;

        case 2: // delete
            printf("삭제할 학생 번호 입력(1 ~ %d) : ", size);
            scanf("%d", &studentNumber);
            deleteStudent(scores, size, studentNumber);
            break;

        case 3: // search
            printf("검색할 학생 번호 입력(1 ~ %d) : ", size);
            scanf("%d", &studentNumber);
            {
                int score = getStudentScore(scores, size, studentNumber);
                if (score != -1)
                    printf("%d번 학생 점수 : %d\n", studentNumber, score);
                else
                    printf("해당 학생은 없는 학생입니다.\n");
            }
            break;

        case 4: // print
        {
            int option;
            printf("옵션 선택 (0: 전체, 1: 평균 이상, 2: 평균 미만): ");
            scanf("%d", &option);
            double average = calculateAverage(scores, size);
            printScore(scores, size, average, option);
            break;
        }

        case 5: // 종료
            free(scores);
            printf("프로그램 종료\n");
            return 0;

        default:
            printf("잘못된 입력\n");
            break;
        }
    }

    return 0;
}

void deleteStudent(int* scores, int size, int studentNumber) {
    if (studentNumber < 1 || studentNumber > size) {
        printf("학생번호 오류\n");
        return;
    }
    if (scores[studentNumber - 1] == -1) {
        printf("이미 삭제된 학생입니다.\n");
    }
    else {
        scores[studentNumber - 1] = -1;
        printf("%d번 학생 삭제 완료\n", studentNumber);
    }
}

double calculateAverage(int scores[], int size) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] != -1) {
            sum += scores[i];
            count++;
        }
    }
    return (count == 0) ? 0.0 : sum / (double)count;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size && scores[studentNumber - 1] != -1) {
        return scores[studentNumber - 1];
    }
    else {
        return -1; // 유효하지 않거나 삭제된 학생
    }
}

void printScore(int scores[], int size, double average, int option) {
    switch (option) {
    case 0: // 모든 학생
        for (int i = 0; i < size; i++) {
            if (scores[i] != -1) {
                printf("학생 번호 : %d, 점수 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 1: // 평균 이상
        for (int i = 0; i < size; i++) {
            if (scores[i] != -1 && scores[i] >= average) {
                printf("학생 번호 : %d, 점수 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 2: // 평균 미만
        for (int i = 0; i < size; i++) {
            if (scores[i] != -1 && scores[i] < average) {
                printf("학생 번호 : %d, 점수 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    default:
        printf("유효하지 않은 옵션입니다.\n");
        break;
    }
}
