#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTEX_NUM 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int VertexType;
typedef int Status;
typedef enum{
	DG,DN
}Graphkind;//图的种类包括有向图和有向网 
//弧信息 
typedef struct ArcBox{
	int tailvex;//该弧的尾顶点的位置
	int headvex;//该弧的头定点的位置
	struct ArcBox *hlink;//指向下一个顶点相同的弧
	struct ArcBox *tlink;//指向下一个终点相同的弧
	int weight;//弧的权值 
}ArcBox; 
//顶点信息 
typedef struct VexNode{
	VertexType data;//弧的顶点
	ArcBox *firstin;//指向该顶点的第一条入弧
	ArcBox *firstout;//指向该顶点的第一条出弧 
}VexNode;
//图信息
typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum;//当前的顶点数
	int arcnum;//当前的弧数
	Graphkind kind;//图的种类 
}OLGraph; 
//访问标记数组
int visited[MAX_VERTEX_NUM]; 
//创建图（有向图/有向网）
Status CreateGraph(OLGraph *G);
//定位顶点值v的位置
int LocateVex(OLGraph G,VertexType v);
//销毁图
Status CreateGraph(OLGraph *G)
{
	int i,j,k,w;
	VertexType tv,hv;//顶点类型 
	ArcBox *p;//弧
	//确定图的种类
	printf("please enter the kind of graph(DG:0,DN:1:)") ;
	scanf("%d",&(*G).kind);
	//确定顶点数和弧数
	printf("please enter the vexnum and arcnum:");
	scanf("%d %d",&(*G).vexnum,&(*G).arcnum);
	//确定各个顶点
	printf("please enter each valve of graph:");
	for(i=0;i<(*G).vexnum;i++)
	{
		scanf("%d",&(*G).xlist[i].data);
		(*G).xlist[i].firstin=NULL;
		(*G).xlist[i].firstout=NULL;
	} 
	//建立各个顶点间的关系，即建立入/出表
	if((*G).kind==DN)
		printf("please enter the heads,tails and weights:\n"); 
	else 
		printf("please enter the heads and tails:\n");
	for(k = 0;k < (*G).arcnum ; k++)
	{
		if((*G).kind == DN)   
            scanf("%d,%d,%d",&tv,&hv,&w);  
        else  
            scanf("%d,%d",&tv,&hv); 
			i=LocateVex(*G,tv);//弧尾 
	j=LocateVex(*G,hv); //弧头
	
	p=(ArcBox*)malloc(sizeof(ArcBox)); 
	if(!p)
		exit(OVERFLOW);
	p->tailvex=i;//弧的起点，入表
	p->headvex=j;//弧的终点，出表
	p->hlink=(*G).xlist[j].firstin;//指向下一个起点相同的弧节点
	p->tlink=(*G).xlist[i].firstout;//指向下一个终点相同的弧节点
	//注意不管是出还是入表都是在表头插入的，<v1,v2>表示v1有出，v2有入
	(*G).xlist[i].firstout=(*G).xlist[j].firstin=p;
	if((*G).kind==DN)
	{
		p->weight=w;
	} 
		
	}

	return OK;
	
 } 
int LocateVex(OLGraph G,VertexType v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.xlist[i].data==v)
		{
			return i;
		}
	}
}

int main(void)
{
	OLGraph G;
	CreateGraph(&G);
	
	return 0;
 } 
