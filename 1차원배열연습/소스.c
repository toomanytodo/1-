#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*���� 1�����迭 ������ ����
2���� ������ �迭Ȱ���ؼ� Ǯ����*/
int main() {

	printf("��� ���� �ִ°�?\n");
	int num;
	scanf_s("%d", &num);

	int** arr = malloc(sizeof(int*) * num);
    int i = 0;
	/*���� ���� ��ŭ '��'�� ���� �����*/
	
	while (i < num) {
		int s;
		printf("�� �ݿ� ����� �ִ°�\n");
		scanf_s("%d",&s);
		printf("%d���ֳ�\n\n", s);
		int nos = s;
		arr[i] = malloc(sizeof(int*) * s);
		/*i+1��°���� ���ǰ����� �����*/
		
		int score;
		float total=0;
		
		int ii = 0;

		while (ii < s) {
			
				printf("�������� �Է��ض�\t");
				scanf_s("%d", &score);
				if (score > 100 || 0>score) {
					printf("�ùٸ� ������ �Է��ض�\n");
					
				}
				else {
					arr[i][ii] = score;


					total = total + score;

					ii++;
				}
				/*
				*100�ʰ��� ���ڽ���� ��������
				���࿡ �����ִ� ���鿡 ������ �Է��Ѵ�*/

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
			/*������ ���ҵ��� ����� ���ϰ� ��հ��� ���Ұ��� ������ ���Ͽ� ����ʰ��ο� ����*/
		}
		

		float final = student*100 / s;
		printf("�������:%.2f��\n��ճ��� ����: %.3f%% \n",average ,final);
		/*��������� ���Ƶ� ����� �ѱ�� �ƴѰ����� �����Ѵ�. */

		

		
		i++;


	}
	
	for (int fr = 0; fr < num; fr++) {
		free(arr[fr]);
	}
	/*2�����迭 ��� ������� 1�����迭���� �޸��Ҵ��� ���������־����*/
	
	free(arr);

	return 0;
}