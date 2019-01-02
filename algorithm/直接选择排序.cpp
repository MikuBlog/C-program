#include<stdio.h>

#define LENGTH 10

void SelectSort(int arr[]);

void _Printf(int arr[]);

void main() {
	
	int arr[LENGTH] = {3,2,5,4,6,9,7,8,10,1};

	printf("初始序列:\n");

	_Printf(arr);

	printf("排序后的结果:\n");

	SelectSort(arr);

	_Printf(arr);
	
}

// 直接选择排序(升序排序)
void SelectSort(int arr[]) {

	int i, j, s, t;

	for(i = 0 ; i < LENGTH - 1 ; i ++) {

		s = i;
	
		// 找出最小元素
		for(j = i+1 ; j < LENGTH ; j ++) {
		
			if(arr[s] > arr[j+1]) {
			
				s = j+1;
			
			}
		
		}

		// 将最小元素和第一个元素进行交换
		if(arr[i] > arr[s]) {
		
			t = arr[i];

			arr[i] = arr[s];

			arr[s] = t;
		
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

