//引入标准输入输出头文件
#include<stdio.h>

//引入动态内存头文件
#include<malloc.h>


//定义二叉树节点
typedef struct Node	{

	char data;

	struct Node *lChild, *rChild;

}Node,*bTree;

//定义创建二叉树函数
void createTree(bTree* T);

//定义先序遍历二叉树函数
void preOrderTraverse(bTree* T);

//定义中序遍历二叉树函数
void inOrderTraverse(bTree* T);

//定义后序遍历二叉树函数
void postOrderTraverse(bTree* T);

//入口函数
void main() {

	bTree T;

	//调用创建二叉树函数
	createTree(&T);

	//调用先序遍历二叉树函数
	preOrderTraverse(&T);

	printf("\n");

	//调用中序遍历二叉树函数
	inOrderTraverse(&T);

	printf("\n");

	//调用后序遍历二叉树函数
	postOrderTraverse(&T);

	printf("\n");

	printf("程序已结束\n");
	
}

//创建二叉树函数
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

//先序遍历二叉树
void preOrderTraverse(bTree* T) {

	if((*T) != NULL){
	
		printf("%c",(*T)->data);

		preOrderTraverse(&((*T)->lChild));
 
		preOrderTraverse(&((*T)->rChild));	
	
	}

}

//中序遍历函数
void inOrderTraverse(bTree* T) {

	if((*T) != NULL){

		inOrderTraverse(&((*T)->lChild));
	
		printf("%c",(*T)->data);

		inOrderTraverse(&((*T)->rChild));	
	
	}

}

//后序遍历函数
void postOrderTraverse(bTree* T) {

	if((*T) != NULL){

		postOrderTraverse(&((*T)->lChild));

		postOrderTraverse(&((*T)->rChild));	

		printf("%c",(*T)->data);
	
	}

}