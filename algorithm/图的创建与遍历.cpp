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

//采用邻接表表示法建立无向图G
void CreateUDG(ALGraph *G) {

	int i, j, k;

	ArcNode *s;

	printf("输入顶点数和弧数:");

	scanf("%d,%d", &G -> vexnum, &G -> arcnum);

	printf("输入顶点信息\n");

	for(i = 0 ; i < G-> vexnum; i ++) {
	
		getchar();

		printf("第%d个顶点:", i);

		scanf("%c", &G -> vertex[i].data);

		G -> vertex[i].firstarc = NULL;
	
	}

	printf("输入边的信息\n");

	for(k = 0 ; k < G -> arcnum ; k ++) {
	
		printf("第%d条-----起点序号，终点序号:", k);

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

// 深度优先遍历的非递归算法
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

// 入口函数
void main() {

	ALGraph G;

	int v;

	CreateUDG(&G);

	printf("输入起始点序号:");

	scanf("%d", &v);

	printf("深度遍历序列为:");

	DFS(G, v);

}


