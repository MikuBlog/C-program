//引入标准输入输出头文件
#include<stdio.h>
//引入动态分配内存头文件
#include<malloc.h>

//定义常量

#define FALSE 0

#define TRUE 1

//定义一个结构体类型

typedef struct stack{

	int data; 

	struct stack *next;

}stack;

typedef struct pointer{

	struct stack *top;

}pointer;

//定义链式结构基本函数

void initStack(pointer *s);

int push(pointer *s,int elemValue);

int pop(pointer *s);

//存放弹出的值
int elem;


//main函数(程序执行的入口)
void main() {

	int pushLength = 5,popLength = 5,i;

	pointer *topPointer = (pointer*)malloc(sizeof(pointer));

	initStack(topPointer);

	//向栈中添加元素
	for(i = 1 ; i < pushLength ; i ++) {
	
		push(topPointer,i);
	
	}

	//从栈顶弹出元素
	for(i = 1 ; i < popLength ; i ++) {
	
		printf("%d:",pop(topPointer));

		printf(" %d \n",elem);
	
	}

}

//初始化栈顶

void initStack(pointer *s) {

	s->top = NULL;

}

//将新元素加入到栈顶
int push(pointer *s,int elemValue) {

	stack *newElem = (stack *)malloc(sizeof(stack));

	if(newElem == NULL) return FALSE;

	newElem->data = elemValue;

	newElem->next = s->top;

	s->top = newElem;

	return TRUE;

}

//将栈顶元素弹出
int pop(pointer *s) {

	stack *storage;

	if(s->top == NULL) return FALSE;

	storage = s->top;

	s->top = s->top->next;

	elem = storage->data;

	free(storage);

	return TRUE;

}
