#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20
#define MAXEDGE 20

typedef struct 
{
	int arc[MAXVEX][MAXVEX];
	int numVertexs,numEdges;
}MGraph;
typedef struct
{
	int begine;
	int end;
	int weight;
}Edge;//对边集数组的结构的定义
//构建图
void CreateMGraph(MGraph *G)
{
	int i,j;
	G->numEdges=15;
	G->numVertexs=9;
	for(i=0;i<G->numVertexs;i++)
	{
		for(j=0;j<G->numVertexs;j++)
		{
			if(i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j]=G->arc[j][i]=65535;
		}
	}
	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19;
	for(i=0;i<G->numVertexs;i++)
	{
		for(j=0;j<G->numVertexs;j++)
		{
			G->arc[j][i]=G->arc[i][j];
		}
	}
 } 
//交换权值以及头和尾
void Swapn(Edge *edges,int i,int j)
{
	int temp;
	temp=edges[i].begine;
	edges[i].begine=edges[j].begine;
	edges[j].begine=temp;
	
	temp=edges[i].end;
	edges[i].end=edges[j].end;
	edges[j].end=temp;
	
	temp=edges[i].weight;
	edges[i].weight=edges[j].weight;
	edges[j].weight=temp;
 } 
 //对权值进行排序
 void sort(Edge edges[],MGraph *G)
 {
 	int i,j;
 	for(i=0;i<G->numEdges;i++)
 	{
 		for(j=i+1;j<G->numEdges;j++)
 		{
 			if(edges[i].weight>edges[j].weight)
 			{
 				Swapn(edges,i,j);
			 }
		 }
	 }
	 printf("权值排序之后的为：\n");
	 for(i=0;i<G->numEdges;i++)
	 {
	 	printf("(%d,%d) %d\n",edges[i].begine,edges[i].end,edges[i].weight);
	 }
  } 
 //查找连线顶点的尾部下标
 int Find(int *parent,int f)
 {
 	while(parent[f]>0)
 	{
 		f=parent[f];
	 }
	 return f;
  } 
//生成最小生成树
void MiniSpanTree_kruskal(MGraph G)
{
	int i,j,n,m;
	int k=0;
	int parent[MAXVEX];//定义一维数组判断边与边是否形成环路
	Edge edges[MAXEDGE];//定义边集数组
	//用来构建边集数组并排序
	 for(i=0;i<G.numVertexs-1;i++)
	 {
	 	for(j=i+1;j<G.numVertexs;j++)
	 	{
	 		if(G.arc[i][j]<65535)
	 		{
	 			edges[k].begine=i;
	 			edges[k].end=j;
	 			edges[k].weight=G.arc[i][j];
	 			k++;
			 }
		 }
	  } 
	  sort(edges,&G);
	  for(i=0;i<G.numVertexs;i++)
	  	parent[i]=0;
	printf("打印最小生成树：\n");
	for(i=0;i<G.numEdges;i++)
	{
		n=Find(parent,edges[i].begine);
		m=Find(parent,edges[j].end);
		if(n!=m)
		{
			parent[n]=m;
			printf("(%d,%d) %d\n",edges[i].begine,edges[i].end,edges[i].weight);
		}
	}
 } 
int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_kruskal(G);
	return 0;
 } 
