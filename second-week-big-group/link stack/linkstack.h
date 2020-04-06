/***************************************************************************************
 *	File Name				:	linkstack.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Date 			:	2020.4.5
 ***************************************************************************************/


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2 
typedef int Status;

//**********栈的链式存储表示***************
typedef int LElemType;

//结点结构
typedef struct StackNode
{
  	LElemType data;
  	struct StackNode *next;
}StackNode;

//链栈结构
typedef struct LinkStack
{
  	struct StackNode *top;
  	int count;
}LinkStack;
//**********基本操作的函数原型说明**********

Status InitStack(LinkStack *S, int *pdestroyed);
//构造一个空栈S
int DestroyStack(LinkStack *S, int *pdestroyed);
//销毁栈S，S不再存在
Status ClearStack(LinkStack *S);
//把S置为空栈
Status StackEmpty(LinkStack S);
//若栈S为空栈，则返回TRUE,否则返回FALSE
int StackLength(LinkStack S);
//返回S的元素个数，即栈的长度
Status GetTop(LinkStack S, LElemType *e);
//若栈不空，则用*e返回S的栈顶元素
Status Push(LinkStack *S, LElemType e);
//插入e为新的栈顶元素
Status Pop(LinkStack *S, LElemType *e);
//若栈不空，则删除S的栈顶元素
Status StackTraverse(LinkStack S);
//从栈顶到栈底遍历栈

//**********基本操作的算法描述部分************

//初始化
Status InitStack(LinkStack *S, int *pdestroyed)
{
	S->top = NULL;
	S->count = 0;
	*pdestroyed = 1;
	return OK;
}

//销毁
int DestroyStack(LinkStack *S ,int *pdestroyed)
{
  	StackNode *p = S->top;
	for( ; S->count > 0; S->count--)
	{
	    S->top = p->next;
		free(p);
		p = S->top;
	}
	S = NULL;
	*pdestroyed = 0;
	return OK;
}

//置空
Status ClearStack(LinkStack *S)
{
	StackNode *p = S->top;
	for( ; S->count > 0; S->count--)
	{
	    S->top = p->next;
		free(p);
		p = S->top;
	}
	S->top = NULL;
	S->count = 0;
	return OK;
}

//判空
Status StackEmpty(LinkStack S)
{
  	if(!S.count)
   	 	return TRUE;
  	else
    	return FALSE;
}

//测长度
int StackLength(LinkStack S)
{
  	return S.count;
}

//取栈顶元素
Status GetTop(LinkStack S,LElemType *e)
{
  	if(!S.count) 
	  	return ERROR;
  	*e = S.top->data;
  	return OK;
}

//入栈
Status Push(LinkStack *S, LElemType e)
{
  	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
  	if(!p) 
  	{
  		printf("内存分配失败！"); 
  		exit(OVERFLOW);
  	}
  	p->data = e;
  	p->next = S->top;
  	S->top = p;
  	S->count++;
  	return OK;
}

//出栈
Status Pop(LinkStack *S, LElemType *e)
{
  	if(!S->count)
    	return ERROR;
  	StackNode *p = S->top;
    *e = S->top->data;
  	S->top = p->next;
  	free(p);
  	S->count--;
  	return OK;
}

//遍历
Status StackTraverse(LinkStack S)
{
  	while(S.top)
  	{
    	printf("%d ", S.top->data);
		S.top = S.top->next;
  	}
  	return OK;
}
