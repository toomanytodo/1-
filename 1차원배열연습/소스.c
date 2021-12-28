#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*백준 1차원배열 마지막 문제
2차원 포인터 배열활용해서 풀었다*/
int main() {

	printf("몇개의 반이 있는가?\n");
	int num;
	scanf_s("%d", &num);

	int** arr = malloc(sizeof(int*) * num);
    int i = 0;
	/*반의 개수 만큼 '행'의 개수 만든다*/
	
	while (i < num) {
		int s;
		printf("이 반에 몇명이 있는가\n");
		scanf_s("%d",&s);
		printf("%d명있넹\n\n", s);
		int nos = s;
		arr[i] = malloc(sizeof(int*) * s);
		/*i+1번째행의 열의개수를 만든다*/
		
		int score;
		float total=0;
		
		int ii = 0;

		while (ii < s) {
			
				printf("각점수를 입력해라\t");
				scanf_s("%d", &score);
				if (score > 100 || 0>score) {
					printf("올바른 점수를 입력해라\n");
					
				}
				else {
					arr[i][ii] = score;


					total = total + score;

					ii++;
				}
				/*
				*100초과의 숫자썼는지 검토한후
				한행에 속해있는 열들에 점수를 입력한다*/

		}
		ii = 1;
		float average = total / s;

		int iii = 0;
		float student = 0;
		while (iii < s ) {
			if (arr[i][iii] > average) {
				student++;
				
			}
			iii++;
			/*한행의 원소들의 평균을 구하고 평균값과 원소값의 우위를 비교하여 평균초과인원 조사*/
		}
		

		float final = student*100 / s;
		printf("평균점수:%.2f점\n평균넘은 비율: %.3f%% \n",average ,final);
		/*평균점수와 같아도 평균을 넘긴건 아닌것으로 간주한다. */

		

		
		i++;


	}
	
	for (int fr = 0; fr < num; fr++) {
		free(arr[fr]);
	}
	/*2차원배열 경우 각행들의 1차원배열들의 메모리할당을 해제시켜주어야함*/
	
	free(arr);

	return 0;
}