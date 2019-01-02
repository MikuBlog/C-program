#include <stdio.h>

#include <malloc.h>

typedef struct Node {

	int key;

	struct Node *lchild, *rchild;

}BSTNode, *BSTree;

void InsertBST(BSTree *BT, int key);

void CreateBST(BSTree *BT);

BSTree BSTSearch(BSTree BT, int key);

// �����������Ĵ���
void CreateBST(BSTree *BT) {

	*BT = NULL;

	int key;

	printf("��������������:\n");

	scanf("%d", &key);

	while(key != -1) {
	
		InsertBST(BT, key);

		scanf("%d", &key);
	
	}

}

// �����������ڵ�Ĳ���
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

// �����������Ĳ���
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

// ��ں���
void main() {

	BSTree BT;

	int value;

	// ����������������
	CreateBST(&BT);
	
	printf("���������ֵ:");

	scanf("%d",&value);

	BSTree getNode = BSTSearch(BT, value);

	if(getNode == NULL) {
	
		printf("���Ҳ�����ֵ!\n");
	
	}else {
	
		printf("��ȡ����ֵΪ:%d\n",getNode -> key);	
	
	}

}