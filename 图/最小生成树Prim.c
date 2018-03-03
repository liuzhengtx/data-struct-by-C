#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAXVEX 20
typedef struct
{
	int arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;
/*构建图*/
void CreateMGraph(MGraph *G)
{
	int i,j;
	G->numEdges=15;
	G->numVertexes=9;
	for(i=0;i<G->numVertexes;i++)
	{
		for(j=0;j<G->numVertexes;j++)
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
	for(i=0;i<G->numVertexes;i++)
	{
		for(j=0;j<G->numVertexes;j++)
		{
			G->arc[j][i]=G->arc[i][j];
		}
	}
 } 
 /*Prim算法生成最小生成树*/
 void MiniSpanTree_Prim(MGraph G)
 {
 	int min,i,j,k;
 	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存相关顶点间边的权值
	lowcost[0]=0;//初始化第一个权值为0，即V0加入生成树
	adjvex[0]=0;// 初始化第一个顶点下标为0
	for(i=1;i<G.numVertexes;i++)//循环除下标为0的所有顶点 
	{
		lowcost[i]=G.arc[0][i]; //将V0顶点与之有边的权值存入数组
		adjvex[i]=0; 
	 } 
	 for(i=1;i<G.numVertexes;i++)
	 {
	 	min=65535;
	 	j=1;k=0;
	 	while(j<G.numVertexes)
	 	{
		 if(lowcost[j]!=0&&lowcost[j]<min)/* 如果权值不为0且权值小于min */
		 {
		 	min=lowcost[j];/* 则让当前权值成为最小值 */
		 	k=j;/* 将当前最小值的下标存入k */
		  } 
		  j++;
		 } 
		printf("(%d %d)\n",adjvex[k],k);
		lowcost[k]=0;/* 将当前顶点的权值设置为0,表示此顶点已经完成任务 */
	 	for(j=1;j<G.numVertexes;j++)
	 	{
	 		if(lowcost[j]!=0 && G.arc[k][j]<lowcost[j])
	 		{
	 			lowcost[j]=G.arc[k][j];
	 			adjvex[j]=k;
			 }
		 }
	 }
  } 
int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Prim(G);
	return 0;
 } 
