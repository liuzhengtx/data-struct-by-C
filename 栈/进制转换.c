#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;
typedef struct stack
{
	PNODE pTop;
	PNODE pBottom; 
}STACK,*PSTACK;
void InitStack(PSTACK S)
{
	S->pTop=(PNODE)malloc(sizeof(NODE));
	S->pBottom=S->pTop;
	S->pBottom->next=NULL;
//	S->pTop->data=0; 
}
void PushStack(PSTACK S,int data)
{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	pNew->data=data;
	
	pNew->next=S->pTop;
	S->pTop=pNew;
}
void PrintStack(PSTACK S)
{
	PNODE top=S->pTop;
	while(S->pBottom!=top)
	{
		printf("%d ",top->data);
		top=top->next;
	}
	printf("\n");
}
int PopStack(PSTACK S)
{
	int data;
	PNODE old=S->pTop;
	data=old->data;
	S->pTop=old->next;
	free(old);
	return data;
}
int main(void)
{
	STACK S;
	int num,d,t,y;
	
	printf("please input num:");
	scanf("%d",&num);//要转换的十进制数 
	printf("please input d:");//转换成几进制 
	scanf("%d",&d);
	InitStack(&S);

	while(num!=0)
	{	
		PushStack(&S,num%d);
		PushStack(&S,num);
		num=PopStack(&S)/d;
	}

	PrintStack(&S);
	
	return 0;
 } 
