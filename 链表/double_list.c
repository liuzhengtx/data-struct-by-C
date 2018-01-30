#include <stdlib.h>//including malloc
#include <stddef.h>//including NULL
#include <stdio.h>//including printf and scanf 
#include <stdbool.h>//including bool,true,false
//init a node
typedef struct node
{
	int data;
	struct node *pre;//point prever node's address
	struct node *next;//point next node's address

}NODE,*PNODE;
//creat a head of list
PNODE Creat_list_head()
{
	PNODE head;
	head=(PNODE)malloc(sizeof(NODE));
	head->next=head->pre=NULL;
	return head;
 } 
//add new node to list from trial
Add_node_normal(PNODE head)
{
	int len,i,data;
	PNODE pNew=NULL;
	printf("please input the length of list: ");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("please input the data: ");
 		scanf("%d",&data);
		pNew=(PNODE)malloc(sizeof(NODE));
		pNew->next=pNew->pre=NULL;
		pNew->data=data;
		
		//link node
		head->next=pNew;
		pNew->pre=head;//add one step compare sigal list
		
		head=pNew;
	}
}
//add new node to list from head
Add_node_innormal(PNODE head)
{
	int len,i,data;
	PNODE pNew=NULL;
	printf("please input the length of list: ");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("please input the data: ");
 		scanf("%d",&data);
		pNew=(PNODE)malloc(sizeof(NODE));
		pNew->next=pNew->pre=NULL;
		pNew->data=data;
		
		//link node
		pNew->next=head->next;
		pNew->pre=head;//add one step compare sigal list
		head->next=pNew;
	}
}

print_list(PNODE head)
{
	PNODE p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void main(void)
{
	PNODE head,head2;
//	head=Creat_list_head();
	head2=Creat_list_head();
//	Add_node_normal(head);
//	print_list(head);
	Add_node_innormal(head2);
		print_list(head2);
}
