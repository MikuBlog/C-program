#include<stdio.h>

#define LENGTH 11

int Partition(int arr[], int low, int high);

void QuickSort(int arr[], int low, int high);

void _Printf(int arr[]);

void main() {
	
	int arr[LENGTH] = {0,3,2,5,4,6,1,9,7,8,10};

	int FIRST = 1;

	int LAST = LENGTH - 1;

	printf("��ʼ����:\n");

	_Printf(arr);

	printf("�����Ľ��:\n");

	QuickSort(arr, FIRST, LAST);

	_Printf(arr);
	
}

// һ�˿�������
int Partition(int arr[], int low, int high) {

	arr[0] = arr[low];

	while(low < high) {
	
		while (low < high && arr[high] >= arr[0]) {
		
			high --;
		
		}

		arr[low] = arr[high];

		while (low < high && arr[low] <= arr[0]) {
		
			low ++;
		
		}

		arr[high] = arr[low];
	
	}

	arr[low] = arr[0];

	return low;

}

// ͨ���ص����ж�ο�������
void QuickSort(int arr[], int low, int high) {

	int p;

	if(low < high) {
	
		p = Partition(arr, low, high);

		QuickSort(arr, low, p - 1);

		QuickSort(arr, p + 1, high);
	
	}

}

// ��ӡ��������е�ֵ
void _Printf(int arr[]) {

	int i;

	for(i = 1 ; i < LENGTH ; i ++) {
	
		printf("%d ",arr[i]);
		
	}

	printf("\n");

}

