#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<stddef.h>
//定义结点结构体
typedef struct Node
{
 int data;  //内容
 struct Node * pNext; //指向下一结点的指针
} NODE, * PNODE;  //NODE等价于struct Node, PNODE等价于struct Node *
//定义栈的结构体
typedef struct Stack
{
 PNODE pTop;  //栈顶结点
 PNODE pBottom;  //栈底结点
} STACK, * PSTACK;  //STACK等价于struct Stack, PSTACK等价于struct Stack *
//函数声明
void initStack(PSTACK pStack);  //对栈进行初始化的函数
void pushStack(PSTACK pStack, int val); //入栈的函数
bool popStack(PSTACK pStack, int * pVal);//出栈的函数，*pVal用来保存出栈的元素内容
void traverseStack(PSTACK pStack);  //遍历栈的函数
bool isEmpty(PSTACK pStack);  //判断栈是否为空的函数
void clearStack(PSTACK pStack);  //清空栈的函数
int main(void)
{
 STACK stack;  //定义一个栈变量,STACK等价于struct Stack
 int val;  //用来保存出栈的内容
 initStack(&stack); //调用栈的初始化函数
 pushStack(&stack, 10); //调用入栈的函数
 pushStack(&stack, 20);
 pushStack(&stack, 30);
 pushStack(&stack, 50);
 traverseStack(&stack); //调用遍历栈的函数
 //调用出栈的函数
 if(popStack(&stack, &val))
 printf("出栈成功，出栈的元素值为：%d\n", val);
 else
 printf(" 出栈失败!");
 //调用清空栈的函数
 clearStack(&stack);
 traverseStack(&stack); //调用遍历栈的函数
 system("pause");
 return 0;
}

void initStack(PSTACK pStack)
{
 //创建一个空结点，让pTop指向它
 pStack->pTop = (PNODE)malloc(sizeof(NODE));
 if(NULL != pStack->pTop)
 {
 //将pBottom也指向空节点
 pStack->pBottom = pStack->pTop;
 pStack->pTop->data=0;
 //清空空结点的指针域
 pStack->pTop->pNext = NULL;
 }
 else   //如果内存分配失败
 {
 printf("内存分配失败!程序退出!\n");
 exit(-1);
 }
 return;
}

void pushStack(PSTACK pStack, int val)
{
 //动态创建一个新结点
 PNODE pNew = (PNODE)malloc(sizeof(NODE));
 //设置新结点的数据域的值
 pNew->data = val;
 //将新结点的指针域指向之前建的空节点
 pNew->pNext = pStack->pTop;  //pStack->pTop不能换成pStack->pBottom
 //pTop指向新的结点
 pStack->pTop = pNew;
 return;
}

bool popStack(PSTACK pStack, int * pVal)
{
 if(isEmpty(pStack))
 {
 return false;
 }
 else
 {
 //先保存栈顶元素的地址，然后将pTop指向下一元素,最后释放之前栈顶元素的内存
 PNODE rNode = pStack->pTop;
 *pVal = rNode->data;
 pStack->pTop = rNode->pNext;
 free(rNode);
 rNode = NULL;
 return true;
 }
}

void traverseStack(PSTACK pStack)
{
 //将栈顶赋给一个临时结点,因为在遍历栈的时候不能销毁栈
 PNODE pNode = pStack->pTop;
 //循环遍历栈,直到栈底
 while(pStack->pBottom != pNode )
 {
 printf("%d ", pNode->data);
 pNode = pNode->pNext;
 }
 printf("\n");
 return;
}

bool isEmpty(PSTACK pStack)
{
 if(pStack->pTop == pStack->pBottom)
 return true;
 else
 return false;
}

void clearStack(PSTACK pStack)
{ //栈为空，则退出该函数
 if(isEmpty(pStack))
 {
 return;
 }
 else
 { 
 //两个结点指针变量用来释放栈中元素的内存
 PNODE p = pStack->pTop;
 PNODE q = NULL;
 //循环释放内存
 while(p != pStack->pBottom)
 {
  q = p->pNext;
  free(p);
  p = q;
 }
 //将栈顶和栈底指向同一个指针域为空的结点
 pStack->pTop = pStack->pBottom;
 return;
 }
}

