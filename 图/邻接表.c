#include <stdio.h>
#include <stdlib.h> 
#define MAXVEX 1000
typedef char VertexType;//顶点类型
typedef int EdgeType;//权值类型

typedef struct EdgeNode//边表结点 
{
	int adjvex;//邻结点域
	EdgeType weight;//用于存储权值
	struct EdgeNode *next;//链域，指向下一个邻结点 
 } EdgeNode;
typedef struct VertexNode//顶点表结构
{
	VertexType data;//顶点域，存储顶点信息
	EdgeNode *firstedge;//边表头指针 
 } VertexNode,AdjList[MAXVEX] ;
typedef struct
{
	AdjList adjList;
	int numVertex,numEdges;//图中当前顶点数和边数 
}GraphList;
int Locate(GraphList *g,char ch)
{
	int i;
	for(i=0;i<MAXVEX;i++)
	{
		if(ch==g->adjList[i].data)
		{
			break;
		}
	}
	if(i>MAXVEX)
	{
		fprintf(stderr,"there is no vertex.\n");
		return -1; 
	}
	return i; 
}
//建立图的邻接表结构
void CreateGraph(GraphList *g)
{
	int i,j,k;
	EdgeNode *e;//边表结点
	EdgeNode *f;
	printf("输入顶点数和边数：\n");
	scanf("%d %d",&g->numVertex,&g->numEdges);
	for(i=0;i<g->numVertex;i++)
	{
		printf("请输入顶点%d:\n",i);
		g->adjList[i].data=getchar();//输入顶点信息
		g->adjList[i].firstedge=NULL; 
		while(g->adjList[i].data=='\n')
		{
			g->adjList[i].data=getchar();
		}
	}
	//建立边表
	for(k=0;k<g->numEdges;k++)
	{
		printf("输入边（vi,vj)上的顶点序号:\n");
		char p,q;
		p=getchar();
		while(p=='\n')
		{
			p=getchar();
		}
		printf("p=%c\n",p);
		q=getchar();
		while(q=='\n')
		{
			q=getchar();
		}
		printf("q=%c\n",q);
		int m=-1;
		int n=-1;
		m=Locate(g,p);
		n=Locate(g,q);
        printf("m = %d\n", m);
        printf("n = %d\n", n);
		if(m==-1||n==-1)
		{
			return;
		}
		//向内存申请空间，生成边表结点
		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		if(e==NULL)
		{
			fprintf(stderr,"内存分配失败"); 
			return; 
		 } 
		//邻接序号为j
		e->adjvex=n;
		//将e指针指向当前顶点指向的结构
		e->next=g->adjList[m].firstedge;
		//将当前顶点的指针指向e
		g->adjList[m].firstedge=e;
		f= (EdgeNode *)malloc(sizeof(EdgeNode));
		if(f==NULL)
		{
			fprintf(stderr,"内存分配失败"); 
			return; 
		}
		f->adjvex=m;
		f->next=g->adjList[n].firstedge;
		g->adjList[n].firstedge = f;
	 } 
 } 
 //打印图
 void printGraph(GraphList *g)
 {
 	int i=0;
 	while(g->adjList[i].firstedge!=NULL&&i<MAXVEX)
 	{
 		printf("顶点%c: ",g->adjList[i].data);
 		EdgeNode *e=NULL;
 		e=g->adjList[i].firstedge;
 		while(e!=NULL)
 		{
 			printf("%d  ",e->adjvex);
 			e=e->next;
		 }
		 i++;
		 printf("\n");
	 }
  } 
int main(void)
{
	GraphList g;
    CreateGraph(&g);
    printGraph(&g);
	return 0;
}
