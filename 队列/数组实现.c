#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct queue
{
	int *pBase;
	int front;
	int rear;
	int maxsize;//最大长度 
}QUEUE,*PQUEUE;
//初始化一个队列
void InitQueue(PQUEUE Q,int maxsize)
{
	Q->pBase=(int*)malloc(sizeof(int)*maxsize) ;
	Q->front=Q->rear=0;
	Q->maxsize=maxsize;
 } 
//判断队列是否为空
bool IsEmpty(PQUEUE Q)
{
	if(Q->front==Q->rear)
	{
		return true;
	}
	else
		return false;
 } 
 //判断队列是否满
bool IsFull(PQUEUE Q)
{
	if(Q->front==(Q->rear+1)%Q->maxsize)
	{
		return true;
	}
	else
		return false;
 } 
 //入队
void InQueue(PQUEUE Q,int val)
{
	if(IsFull(Q))
	{
		printf("队列已满！！");
	}
	else
	{
		Q->pBase[Q->rear]=val;
		Q->rear=(Q->rear+1)%Q->maxsize;//为了使最后一个空间为空(不放元素)，不能采用(Q->rear)++ 
	}
		
 } 
 //出队 
 void OutQueue(PQUEUE Q,int *val)
 {
 	if(IsEmpty(Q)) 
 		printf("队列以为空！！");
	else
	{
		*val=Q->pBase[Q->front];
 		Q->front=(Q->front+1)%Q->maxsize;
	 } 
  } 
 
 //打印
void PrintQueue(PQUEUE Q)
{
	int i=Q->front;
	while(i!=Q->rear)
	{
		printf("%d ",Q->pBase[i]);
		i++;
	}
	printf("\n");
 } 
int main(void)
{
	QUEUE Q;
	int val,w;
	InitQueue(&Q,5);
	while(1)
	{
		printf("请输入一个元素：");
		scanf("%d",&w);
		InQueue(&Q,w);
		PrintQueue(&Q);
	}
//	InQueue(&Q,5);
	PrintQueue(&Q);
	OutQueue(&Q,&val);
	printf("出队元素是：%d",val);
	printf("\n");
	printf("剩余元素为：");
	PrintQueue(&Q);
	OutQueue(&Q,&val);
	printf("出队元素是：%d",val);
	printf("\n");
	printf("剩余元素为：");
	PrintQueue(&Q);
	return 0;
 } 
