#include <stdio.h>

#include <malloc.h>

typedef struct Node {

	int key;

	struct Node *lchild, *rchild;

}BSTNode, *BSTree;

void InsertBST(BSTree *BT, int key);

void CreateBST(BSTree *BT);

BSTree BSTSearch(BSTree BT, int key);

// 二叉排序树的创建
void CreateBST(BSTree *BT) {

	*BT = NULL;

	int key;

	printf("创建二叉排序树:\n");

	scanf("%d", &key);

	while(key != -1) {
	
		InsertBST(BT, key);

		scanf("%d", &key);
	
	}

}

// 二叉排序树节点的插入
void InsertBST(BSTree *BT, int key) {

	BSTree s;

	if(*BT == NULL) {
	
		s = (BSTree)malloc(sizeof (BSTNode));

		s -> key = key;

		s -> lchild = NULL;

		s -> rchild = NULL;

		*BT = s;
	
	}

	else if(key < (*BT) -> key) {
	
		InsertBST(&((*BT) -> lchild), key);
	
	}

	else if(key > (*BT) -> key) {
	
		InsertBST(&((*BT) -> rchild), key);
	
	}

}

// 二叉排序树的查找
BSTree BSTSearch(BSTree BT, int key) {

	BSTree BT1;

	BT1 = BT;

	while(BT1) {
	
		if(BT1 -> key == key) {
		
			return BT1;
		
		}

		if(key < BT1 -> key) {
		
			BT1 = BT1 -> lchild;
		
		}else {
		
			BT1 = BT1 -> rchild;
		
		}
	
	}

	return NULL;

}

// 入口函数
void main() {

	BSTree BT;

	int value;

	// 创建二叉树排序树
	CreateBST(&BT);
	
	printf("请输入查找值:");

	scanf("%d",&value);

	BSTree getNode = BSTSearch(BT, value);

	if(getNode == NULL) {
	
		printf("查找不到该值!\n");
	
	}else {
	
		printf("获取到该值为:%d\n",getNode -> key);	
	
	}

}