#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int score[10],sum = 0;
	double average;

	for (int i = 0; i < 10; i++) {
		printf("%d번째 학생 성적을 입력하시오: ", i + 1);
		scanf("%d", &score[i]);
		sum += score[i];
	}

	average = sum / 10.0;
	printf("10명의 학생 총 점수 : %d\n10명의 학생 평균 점수 : %.2f\n", sum, average);
	return 0;
}