//�����׼�������ͷ�ļ�
#include<stdio.h>

//���붯̬�ڴ�ͷ�ļ�
#include<malloc.h>


//����������ڵ�
typedef struct Node	{

	char data;

	struct Node *lChild, *rChild;

}Node,*bTree;

//���崴������������
void createTree(bTree* T);

//���������������������
void preOrderTraverse(bTree* T);

//���������������������
void inOrderTraverse(bTree* T);

//��������������������
void postOrderTraverse(bTree* T);

//��ں���
void main() {

	bTree T;

	//���ô�������������
	createTree(&T);

	//���������������������
	preOrderTraverse(&T);

	printf("\n");

	//���������������������
	inOrderTraverse(&T);

	printf("\n");

	//���ú����������������
	postOrderTraverse(&T);

	printf("\n");

	printf("�����ѽ���\n");
	
}

//��������������
void createTree(bTree *T) {

	char ch;

	scanf("%c",&ch);

	if(ch == '#') {
	
		*T = NULL;

		return;

	}else {
		
		*T = (Node*)malloc(sizeof(struct Node));

		(*T)->data = ch;

		createTree(&((*T)->lChild));

		createTree(&((*T)->rChild));
	
	}

}

//�������������
void preOrderTraverse(bTree* T) {

	if((*T) != NULL){
	
		printf("%c",(*T)->data);

		preOrderTraverse(&((*T)->lChild));
 
		preOrderTraverse(&((*T)->rChild));	
	
	}

}

//�����������
void inOrderTraverse(bTree* T) {

	if((*T) != NULL){

		inOrderTraverse(&((*T)->lChild));
	
		printf("%c",(*T)->data);

		inOrderTraverse(&((*T)->rChild));	
	
	}

}

//�����������
void postOrderTraverse(bTree* T) {

	if((*T) != NULL){

		postOrderTraverse(&((*T)->lChild));

		postOrderTraverse(&((*T)->rChild));	

		printf("%c",(*T)->data);
	
	}

}