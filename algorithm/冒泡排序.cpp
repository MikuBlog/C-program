#include<stdio.h>

#define LENGTH 10

void BubbleSort(int arr[]);

void _Printf(int arr[]);

void main() {
	
	int arr[LENGTH] = {3,2,5,4,6,9,7,8,10,1};

	printf("初始序列:\n");

	_Printf(arr);

	printf("排序后的结果:\n");

	BubbleSort(arr);

	_Printf(arr);
	
}

// 冒泡排序(升序排序)
void BubbleSort(int arr[]) {

	int i, j, t;

	for(i = 0 ; i < LENGTH - 1 ; i ++) {
	
		for(j = 0 ; j < LENGTH - i ; j ++) {
		
			if(arr[j] > arr[j+1]) {
			
				t = arr[j];

				arr[j] = arr[j+1];

				arr[j+1] = t;
			
			}
		
		}

	}
	
}

// 打印输出数组中的值
void _Printf(int arr[]) {

	int i;

	for(i = 0 ; i < LENGTH ; i ++) {
	
		printf("%d ",arr[i]);
		
	}

	printf("\n");

}

