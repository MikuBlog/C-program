//�����׼�������ͷ�ļ�
#include<stdio.h>
//���붯̬�����ڴ�ͷ�ļ�
#include<malloc.h>

//���峣��

#define FALSE 0

#define TRUE 1

//����һ���ṹ������

typedef struct stack{

	int data; 

	struct stack *next;

}stack;

typedef struct pointer{

	struct stack *top;

}pointer;

//������ʽ�ṹ��������

void initStack(pointer *s);

int push(pointer *s,int elemValue);

int pop(pointer *s);

//��ŵ�����ֵ
int elem;


//main����(����ִ�е����)
void main() {

	int pushLength = 5,popLength = 5,i;

	pointer *topPointer = (pointer*)malloc(sizeof(pointer));

	initStack(topPointer);

	//��ջ�����Ԫ��
	for(i = 1 ; i < pushLength ; i ++) {
	
		push(topPointer,i);
	
	}

	//��ջ������Ԫ��
	for(i = 1 ; i < popLength ; i ++) {
	
		printf("%d:",pop(topPointer));

		printf(" %d \n",elem);
	
	}

}

//��ʼ��ջ��

void initStack(pointer *s) {

	s->top = NULL;

}

//����Ԫ�ؼ��뵽ջ��
int push(pointer *s,int elemValue) {

	stack *newElem = (stack *)malloc(sizeof(stack));

	if(newElem == NULL) return FALSE;

	newElem->data = elemValue;

	newElem->next = s->top;

	s->top = newElem;

	return TRUE;

}

//��ջ��Ԫ�ص���
int pop(pointer *s) {

	stack *storage;

	if(s->top == NULL) return FALSE;

	storage = s->top;

	s->top = s->top->next;

	elem = storage->data;

	free(storage);

	return TRUE;

}
