#include <stdlib.h>

#include <stdio.h>

#define MAX_VERTEX_NUM 30

typedef struct ArcNode {

	int adjvex;

	struct ArcNode *next;

}ArcNode;

typedef struct VertexNode {

	char data;

	struct ArcNode *firstarc;

}VertexNode;

typedef struct {

	VertexNode vertex[MAX_VERTEX_NUM];

	int vexnum,arcnum;

}ALGraph;

void CreateUDG(ALGraph *G);

void DFS(ALGraph G, int v);

//�����ڽӱ��ʾ����������ͼG
void CreateUDG(ALGraph *G) {

	int i, j, k;

	ArcNode *s;

	printf("���붥�����ͻ���:");

	scanf("%d,%d", &G -> vexnum, &G -> arcnum);

	printf("���붥����Ϣ\n");

	for(i = 0 ; i < G-> vexnum; i ++) {
	
		getchar();

		printf("��%d������:", i);

		scanf("%c", &G -> vertex[i].data);

		G -> vertex[i].firstarc = NULL;
	
	}

	printf("����ߵ���Ϣ\n");

	for(k = 0 ; k < G -> arcnum ; k ++) {
	
		printf("��%d��-----�����ţ��յ����:", k);

		scanf("%d,%d", &i, &j);

		s = (ArcNode*)malloc(sizeof (ArcNode));

		s -> adjvex = j;

		s -> next = G -> vertex[i].firstarc;

		G -> vertex[i].firstarc = s;

		s = (ArcNode*)malloc(sizeof (ArcNode));

		s -> adjvex = i;

		s -> next = G -> vertex[j].firstarc;

		G -> vertex[j].firstarc = s;
	
	}

}

// ������ȱ����ķǵݹ��㷨
void DFS(ALGraph G, int v) {

	int w, visited[MAX_VERTEX_NUM] = {0};

	int stack[MAX_VERTEX_NUM], top = 0;

	ArcNode *p;

	printf("%c", G.vertex[v].data);

	visited[v] = 1;

	top ++;

	stack[top] = v;

	p = G.vertex[v].firstarc;

	while(1) {
	
		while(p && visited[p -> adjvex] == 1)

			p = p -> next;

		if(p) {
		
			w = p -> adjvex;
			
			printf("%c", G.vertex[w].data);

			visited[w] = 1;

			top ++;

			stack[top] = w;

			p = G.vertex[w].firstarc;
		
		}else {
		
			if(top > 1) {
			
				top --;

				w = stack[top];

				p = G.vertex[w].firstarc;

			}else {
			
				break;
			
			}
		
		}
	
	}

	printf("\n");

}

// ��ں���
void main() {

	ALGraph G;

	int v;

	CreateUDG(&G);

	printf("������ʼ�����:");

	scanf("%d", &v);

	printf("��ȱ�������Ϊ:");

	DFS(G, v);

}


