#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;
//define list head
PNODE Creat_list_haed()
{
	PNODE head=(PNODE)malloc(sizeof(NODE));
	head->next=NULL;
	return head;
}
 //add new node to list normal
 Add_node_normal(PNODE head)
 {
 	PNODE pNew=NULL;
 	int i,len,data;
 	printf("please input the length of list: ");
 	scanf("%d",&len);
 	for (i=0;i<len;i++)
 	{
 		printf("please input the data: ");
 		scanf("%d",&data);
 		pNew=(PNODE)malloc(sizeof(NODE));
 		pNew->next=NULL;
 		pNew->data=data;
 		
 		//link
 		head->next=pNew;
 		head=head->next;//head=pNew,can do sim work
	 }
 }
 //delete a node
 void Delete_node(PNODE head)
 {
 	PNODE p;
 	int i;
 	int pos;
 	PNODE q;
 	p=head->next;
 	printf("\nplease input the position of node you want to delete:");
 	scanf("%d",&pos);
	while(i<pos-1)
	{
		p=p->next;
		i++;
	}
	q=p->next;
	p->next=q->next;
	free(q);//release delete node
	q=NULL;
 }
 //add new node to list not normal
 Add_node_innormal(PNODE head)
 {
 	PNODE pNew=NULL;
 	int i,len,data;
 	printf("please input the length of list: ");
 	scanf("%d",&len);
 	for (i=0;i<len;i++)
 	{
 		printf("please input the data: ");
 		scanf("%d",&data);
 		pNew=(PNODE)malloc(sizeof(NODE));
 		pNew->next=NULL;
 		pNew->data=data;
 		
 		//link
 		pNew->next=head->next;
 		head->next=pNew;//head=pNew,can do sim work
	 }
 }
 //insert node
void Insert_list(PNODE head)
{
	int i;
	PNODE p;
	int pos,data;
	p=head->next;
	PNODE q=(PNODE)malloc(sizeof(NODE));
	printf("please input insert position ");
	scanf("%d",&pos);
	printf("please input insert data ");
	scanf("%d",&data);
	q->data=data;
	for(i=0;i<pos-1;i++)
	{
		p=p->next	;
	}
	q->next=p->next;
	p->next=q; 
 } 
 //length of list
int Len_list(PNODE head)
{
	int i=0;
	PNODE p;
	p=head->next;
	while(p!=NULL)
	{	
		i++;
		p=p->next;
	}	
	return i;
} 
 //sort list from small to big
void Sort_list(PNODE head)
{
	int len;
	int i,j;
	int temp;
	PNODE p,q;
	len=Len_list(head);
	for(i=0,p=head->next;i<len-1;i++,p=p->next)
	{ 
		for(j=i+1,q=p->next;j<len;j++,q=q->next)
			{
				if(p->data>q->data)
				{
                 	temp=p->data;
                 	p->data=q->data;
					q->data=temp; 
				}
			 } 
	} 
 } 

 //print list
 Print_list(PNODE head)
 {
 	PNODE p=head->next;
 	while(p!=NULL)
 	{
 		printf("%d ",p->data);
 		p=p->next;
	 }
	 printf("\n");
 }
int main(void)
{
	PNODE head1,head2;
	head1= Creat_list_haed();
	head2= Creat_list_haed();
	Add_node_normal(head1);
	Print_list(head1);
	Insert_list(head1);
	Print_list(head1);
	Sort_list(head1);
	Print_list(head1);
	Delete_node(head1);
	Print_list(head1);
	Add_node_innormal(head2);
	Print_list(head2);
	return 0;
}
