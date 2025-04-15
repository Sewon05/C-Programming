#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �Լ� ����
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
    printf("�Է� �Ϸ�\n");

    while (1) {
        printf("\n---�л� ���� ���� ���α׷�---\n");
        printf("1. �л����� �߰�\n");
        printf("2. �л����� ����\n");
        printf("3. �л����� �˻�\n");
        printf("4. �л����� ���(�ɼ� : 0, 1, 2)\n");
        printf("5. ���α׷� ����\n");
        printf("����: ");
        scanf("%d", &choice);

        // �ü���� ���� �ܼ� ����
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
            printf("���ο� �л� �߰� : ��ȣ - %d, ���� - %d\n", size, newScore);
            break;

        case 2: // delete
            printf("������ �л� ��ȣ �Է�(1 ~ %d) : ", size);
            scanf("%d", &studentNumber);
            deleteStudent(scores, size, studentNumber);
            break;

        case 3: // search
            printf("�˻��� �л� ��ȣ �Է�(1 ~ %d) : ", size);
            scanf("%d", &studentNumber);
            {
                int score = getStudentScore(scores, size, studentNumber);
                if (score != -1)
                    printf("%d�� �л� ���� : %d\n", studentNumber, score);
                else
                    printf("�ش� �л��� ���� �л��Դϴ�.\n");
            }
            break;

        case 4: // print
        {
            int option;
            printf("�ɼ� ���� (0: ��ü, 1: ��� �̻�, 2: ��� �̸�): ");
            scanf("%d", &option);
            double average = calculateAverage(scores, size);
            printScore(scores, size, average, option);
            break;
        }

        case 5: // ����
            free(scores);
            printf("���α׷� ����\n");
            return 0;

        default:
            printf("�߸��� �Է�\n");
            break;
        }
    }

    return 0;
}

void deleteStudent(int* scores, int size, int studentNumber) {
    if (studentNumber < 1 || studentNumber > size) {
        printf("�л���ȣ ����\n");
        return;
    }
    if (scores[studentNumber - 1] == -1) {
        printf("�̹� ������ �л��Դϴ�.\n");
    }
    else {
        scores[studentNumber - 1] = -1;
        printf("%d�� �л� ���� �Ϸ�\n", studentNumber);
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
        return -1; // ��ȿ���� �ʰų� ������ �л�
    }
}

void printScore(int scores[], int size, double average, int option) {
    switch (option) {
    case 0: // ��� �л�
        for (int i = 0; i < size; i++) {
            if (scores[i] != -1) {
                printf("�л� ��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 1: // ��� �̻�
        for (int i = 0; i < size; i++) {
            if (scores[i] != -1 && scores[i] >= average) {
                printf("�л� ��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 2: // ��� �̸�
        for (int i = 0; i < size; i++) {
            if (scores[i] != -1 && scores[i] < average) {
                printf("�л� ��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    default:
        printf("��ȿ���� ���� �ɼ��Դϴ�.\n");
        break;
    }
}
