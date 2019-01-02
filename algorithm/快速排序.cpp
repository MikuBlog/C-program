#include<stdio.h>

#define LENGTH 11

int Partition(int arr[], int low, int high);

void QuickSort(int arr[], int low, int high);

void _Printf(int arr[]);

void main() {
	
	int arr[LENGTH] = {0,3,2,5,4,6,1,9,7,8,10};

	int FIRST = 1;

	int LAST = LENGTH - 1;

	printf("初始序列:\n");

	_Printf(arr);

	printf("排序后的结果:\n");

	QuickSort(arr, FIRST, LAST);

	_Printf(arr);
	
}

// 一趟快速排序
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

// 通过回调进行多次快速排序
void QuickSort(int arr[], int low, int high) {

	int p;

	if(low < high) {
	
		p = Partition(arr, low, high);

		QuickSort(arr, low, p - 1);

		QuickSort(arr, p + 1, high);
	
	}

}

// 打印输出数组中的值
void _Printf(int arr[]) {

	int i;

	for(i = 1 ; i < LENGTH ; i ++) {
	
		printf("%d ",arr[i]);
		
	}

	printf("\n");

}

