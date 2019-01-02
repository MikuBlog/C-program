//引入标准输入输出头文件
#include<stdio.h>
//引入动态分配内存头文件
#include<malloc.h>

//定义常量
#define MAXSIZE 10

#define FALSE 0

#define TRUE 1

//定义一个结构体类型
typedef struct{

	int elem[MAXSIZE]; 

	int top;

}stack;

//定义栈顺序结构基本操作函数

void initStack(stack *s);

int stackEmpty(stack s);

int push(stack *s,int number);

void printStack(stack s);

int pop(stack *s);

int elem;

void main() {

	stack a;
	int i,enterLength = 5,outLength = 2;

	//测试初始化栈,	使栈的顶部指向值为零
	initStack(&a);

	//测试判断栈是否为空
	if(stackEmpty(a)) {
	
		printf("栈为空\n");
	
	}else {
	
		printf("栈不为空\n");
	
	}

	//测试向栈中推入元素
	for(i = 0 ; i < enterLength ; i ++) {
	
		push(&a,i);	
	
	}

	//输出栈中的所有元素
	printStack(a);

	//测试弹出栈，弹出outLength个元素
	printf("\n弹出栈顶元素:");

	for(i = 0 ; i < outLength ; i ++ ){
	
		printf("%d ",pop(&a));

	}

}

//初始化栈
void initStack(stack *s) {

	s->top = 0;
	
}

//判断栈是否为空
int stackEmpty(stack s) {

	return s.top == 0?TRUE:FALSE;
	
} 

//向栈推入元素
int push(stack *s,int number) {

	if(s->top == MAXSIZE) return FALSE;

	s->elem[s->top] = number;

	s->top++;

	return TRUE;

}

//弹出栈顶元素
int pop(stack *s) {

	if(s->top == MAXSIZE) return FALSE;

	s->top--;

	elem = s->elem[s->top];

	return elem;

}

//输出栈中的所有元素
void printStack(stack s) {

	int i;

	printf("输出栈中的所有结果:");

	for(i = 0 ; i < s.top ; i ++) {
	
		printf("%d ",s.elem[i]);
	
	}

}