#include<stdio.h>

#include<stdlib.h>

#include <string.h>

#define MAXSIZE 100

typedef int ElemType;

int LIST_MAX_SIZE = MAXSIZE;

typedef struct array{

	ElemType *elem;

	int length;

	int listsize;

}SqList;

ElemType InitList(SqList *L);

ElemType DestroyList(SqList *L);

ElemType ClearList(SqList *L);

ElemType ListEmpty(SqList *L);

ElemType printList(SqList *L);

ElemType Locate(SqList *L,int e);

ElemType InsertList(SqList *L,int i,int e);

ElemType DeletetList(SqList *L,int i,int e);

ElemType PriorElem(SqList *L,int e);

ElemType NextElem(SqList *L,int e);

void main() {

	SqList a;

	SqList *b = &a;

	if(InitList(b) == 1) {

		printf("初始化成功\n");

	} else {
	
		printf("初始化失败\n");
	
	}

	
	InsertList(b,2,100);

	printList(b);

}

ElemType InitList(SqList *L) {

	int i;

	L->elem = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));

	if(!L->elem)return 0;

	L->length = 0;

	L->listsize = LIST_MAX_SIZE;

	for(i = 0 ; i < L->listsize ; i ++) {
	
		*(L->elem +(i*sizeof(ElemType))) = 0;
	
	}

	return 1;

}

ElemType DestroyList(SqList *L) {

	if(!L->elem)return 0;

	free(L->elem); 

	return 1;
		
}

ElemType ClearList(SqList *L) {

	if(!L->elem)return 0;

	free(L->elem);

	L->elem = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));

	L->length = 0;

	return 1;

}

ElemType ListEmpty(SqList *L) {

	int i;

	if(!L->elem)return 0;

	printf("\n");

	for(i = 0 ; i < L->listsize ; i ++) {

		if(*(L->elem+(i*sizeof(ElemType)))!=0)return 1;
		
	}

	return 0;

}

ElemType printList(SqList *L)  {

	int i;

	if(!L->elem)return 0;

	for(i = 0 ; i < L->listsize ; i ++) {
	
		printf("%d",*(L->elem+(i*sizeof(ElemType))));

	}

	printf("\n");

	return 1;

}

ElemType Locate(SqList *L,int e) {

	if(!L->elem)return 0;

	printf("%d",*(L->elem+e*sizeof(ElemType)));

	return 1;

}

ElemType InsertList(SqList *L,int n,int e) {

	int listsize = L->listsize;

	int length = listsize+1;

	int i,j;

	ElemType *array = (ElemType *)malloc(length*sizeof(ElemType));

	if(!L->elem) {
	
		free(array);

		return 0;
	
	}

	for(i = 0 , j = 0 ; i < length ; i ++)  {
	
		if (i == n - 1) {
		
			*(array+i*sizeof(ElemType)) = e;

			continue;

		}

		*(array+i*sizeof(ElemType)) = *(L->elem+j*sizeof(ElemType));

		j++;
 	
	}

	L->elem = array;

	L->listsize = length;

	return 1;

}

ElemType DeletetList(SqList *L,int n,int e) {

	int i,j,value;

	if(!L->elem) {

		return 0;
	
	}

	for(i = 0 , j = 0 ; i < L->listsize ; i ++) {
	
		if(i == n -1) {
		
			value = *(L->elem+i*sizeof(ElemType));

			j = i;
		
		} else if(i > n - 1) {
		
			*(L->elem+j*sizeof(ElemType)) = *(L->elem+i*sizeof(ElemType));
		
		}
	
	}

	return value;

}

ElemType PriorElem(SqList *L,int e) {

	int i;

	if(!L->elem)  {
	
		return 0;
	
	}

	for(i = 0 ; i < L->listsize ; i ++) {
	
		if(e == *(L->elem+i*sizeof(ElemType)) && i > 0)  {
		
			return *(L->elem+(i-1)*sizeof(ElemType));
		
		} 
	
	}

	return 0;

}

ElemType NextElem(SqList *L,int e) {

	int i;

	if(!L->elem)  {
	
		return 0;
	
	}

	for(i = 0 ; i < L->listsize ; i ++) {
	
		if(e == *(L->elem+i*sizeof(ElemType)) && i+1 < L->listsize)  {
		
			return *(L->elem+(i+1)*sizeof(ElemType));
		
		} 
	
	}

	return 0;

}







