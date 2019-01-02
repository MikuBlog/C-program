//�����׼�������ͷ�ļ�
#include<stdio.h>
//���붯̬�����ڴ�ͷ�ļ�
#include<malloc.h>

//���峣��
#define MAXSIZE 10

#define FALSE 0

#define TRUE 1

//����һ���ṹ������
typedef struct{

	int elem[MAXSIZE]; 

	int top;

}stack;

//����ջ˳��ṹ������������

void initStack(stack *s);

int stackEmpty(stack s);

int push(stack *s,int number);

void printStack(stack s);

int pop(stack *s);

int elem;

void main() {

	stack a;
	int i,enterLength = 5,outLength = 2;

	//���Գ�ʼ��ջ,	ʹջ�Ķ���ָ��ֵΪ��
	initStack(&a);

	//�����ж�ջ�Ƿ�Ϊ��
	if(stackEmpty(a)) {
	
		printf("ջΪ��\n");
	
	}else {
	
		printf("ջ��Ϊ��\n");
	
	}

	//������ջ������Ԫ��
	for(i = 0 ; i < enterLength ; i ++) {
	
		push(&a,i);	
	
	}

	//���ջ�е�����Ԫ��
	printStack(a);

	//���Ե���ջ������outLength��Ԫ��
	printf("\n����ջ��Ԫ��:");

	for(i = 0 ; i < outLength ; i ++ ){
	
		printf("%d ",pop(&a));

	}

}

//��ʼ��ջ
void initStack(stack *s) {

	s->top = 0;
	
}

//�ж�ջ�Ƿ�Ϊ��
int stackEmpty(stack s) {

	return s.top == 0?TRUE:FALSE;
	
} 

//��ջ����Ԫ��
int push(stack *s,int number) {

	if(s->top == MAXSIZE) return FALSE;

	s->elem[s->top] = number;

	s->top++;

	return TRUE;

}

//����ջ��Ԫ��
int pop(stack *s) {

	if(s->top == MAXSIZE) return FALSE;

	s->top--;

	elem = s->elem[s->top];

	return elem;

}

//���ջ�е�����Ԫ��
void printStack(stack s) {

	int i;

	printf("���ջ�е����н��:");

	for(i = 0 ; i < s.top ; i ++) {
	
		printf("%d ",s.elem[i]);
	
	}

}