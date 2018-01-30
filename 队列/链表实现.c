#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;
typedef struct queue
{
	PNODE front;
	PNODE rear;
}QUEUE,*PQUEUE;
//初始化空队列
void InitQueue(PQUEUE Q)
{
	Q->front=(PNODE)malloc(sizeof(NODE));
	if(NULL==Q->front)
	{
		printf("queue init failure");
		exit(-1);
	}
	Q->front->next=NULL;
	Q->rear=Q->front;
}
//入队 
void InQueue(PQUEUE Q,int data)
{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	pNew->next=NULL;
	pNew->data=data;
	if(NULL==pNew)
	{
		printf("pNew creat failure");
		exit(-1);
	}
	Q->rear->next=pNew;
	Q->rear=pNew;
}
//判断队列是否为空
bool IsEmpty(PQUEUE Q)
{
	if(Q->front==Q->rear)
		return true;
	else
		return false	;
 } 
//出队
void OutQueue(PQUEUE Q,int *val)
{
	PNODE old=Q->front;
	if(IsEmpty(Q))
	{
		printf("queue is empty!!");
		printf("\n");	
	}
	else
	{
		*val=old->next->data;
		Q->front=old->next;
		free(old);
	 } 
 } 
void PrintQueue(PQUEUE Q)
{
	PNODE p=Q->front->next;
	while(NULL!=p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(void)
{
	int data,val;
	QUEUE Q;
	InitQueue(&Q);
	InQueue(&Q,1);
	InQueue(&Q,2);
	InQueue(&Q,3);
	InQueue(&Q,4);
	InQueue(&Q,5);
	PrintQueue(&Q);
	
	OutQueue(&Q,&val);
	printf("out data is %d \n",val);
	PrintQueue(&Q);
	
	OutQueue(&Q,&val);
	printf("out data is %d \n",val);
	PrintQueue(&Q);
	system("pause");
//	while(1)
//	{
//		printf("please input a data:");
//		if(scanf("%d",&data)==1)
//		{
//			InQueue(&Q,data);
//			PrintQueue(&Q);
//		}
//		
//		else
//		{
//				printf("input is not a num "); 
//				fflush(stdin);//清理输入缓存，否则scanf的返回值会一直是0 
//				printf("\n");
//		}
//	}
	return 0;
 } 
 
