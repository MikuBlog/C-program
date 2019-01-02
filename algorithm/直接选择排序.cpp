#include<stdio.h>

#define LENGTH 10

void SelectSort(int arr[]);

void _Printf(int arr[]);

void main() {
	
	int arr[LENGTH] = {3,2,5,4,6,9,7,8,10,1};

	printf("��ʼ����:\n");

	_Printf(arr);

	printf("�����Ľ��:\n");

	SelectSort(arr);

	_Printf(arr);
	
}

// ֱ��ѡ������(��������)
void SelectSort(int arr[]) {

	int i, j, s, t;

	for(i = 0 ; i < LENGTH - 1 ; i ++) {

		s = i;
	
		// �ҳ���СԪ��
		for(j = i+1 ; j < LENGTH ; j ++) {
		
			if(arr[s] > arr[j+1]) {
			
				s = j+1;
			
			}
		
		}

		// ����СԪ�غ͵�һ��Ԫ�ؽ��н���
		if(arr[i] > arr[s]) {
		
			t = arr[i];

			arr[i] = arr[s];

			arr[s] = t;
		
		}
	
	}

}


// ��ӡ��������е�ֵ
void _Printf(int arr[]) {

	int i;

	for(i = 0 ; i < LENGTH ; i ++) {
	
		printf("%d ",arr[i]);
		
	}

	printf("\n");

}

