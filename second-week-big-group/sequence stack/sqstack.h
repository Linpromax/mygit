/***************************************************************************************
 *	File Name				:	sqstack.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Date				:	2020.4.5
 ****************************************************************************************/


#define OK 1
#define ERROR 0
#define OVERFLOW -2 
typedef int Status;

//**********栈的顺序存储表示***************

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//**********基本操作的函数原型说明**********

Status InitStack(SqStack *S);
//构造一个空栈S
Status DestroyStack(SqStack *S);
//销毁栈S，S不再存在
Status ClearStack(SqStack *S);
//把S置为空栈
Status StackEmpty(SqStack S);
//若栈S为空栈, 返回 1 
void StackLength(SqStack S);
//返回S的元素个数，即栈的长度
Status GetTop(SqStack S,SElemType *e);
//若栈不为空，则用*e返回S的栈顶元素
Status Push(SqStack *S,SElemType e);
//插入e为新的栈顶元素
Status Pop(SqStack *S,SElemType *e);
//若栈不空，则删除S的栈顶元素
Status StackTraverse(SqStack S);
//从栈顶到栈底遍历栈

//**********基本操作的算法描述部分************

//初始化
Status InitStack(SqStack *S)
{
  	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
  	if(!S->base) 
  	{ 
  		printf("内存分配失败!"); 
  		exit(OVERFLOW);
  	} 
  	S->top = S->base;
  	S->stacksize = STACK_INIT_SIZE;
  	return OK;
}

//销毁
Status DestroyStack(SqStack *S)
{
	if(S->base == NULL)
	{
		printf("栈不存在！");
		return 2;
	}
	else
	{
        free(S->base);
        S->top = S->base = NULL;
        S->stacksize = 0; 
        printf("栈销毁完毕，此时栈不存在！\n");
    }
 	return OK;
}

//置空
Status ClearStack(SqStack *S)
{
	if(S->base == NULL)
	{
		printf("栈不存在！");
		return ERROR;
	}
  	S->top = S->base;
  	printf("栈置空完毕，此时栈为空栈！\n");
  	return OK;
}

//判空
Status StackEmpty(SqStack S)
{
	if(S.base == NULL)
	{
		return 0;
	}
 	if(S.top == S.base)
    	return 1;
  	else
    	return 2;
}

//测长度
void StackLength(SqStack S)
{
	if(S.base == NULL)
	{
		printf("栈不存在！");
		return;
	}
    printf("栈的长度为%d\n", S.top-S.base);
}

//取栈顶元素
Status GetTop(SqStack S, SElemType *e)
{
	if(1 == StackEmpty(S))
		{
			printf("此时栈为空栈！\n");
		}
	else if(2 == StackEmpty(S))
		{
			*e = *(S.top - 1);
			printf("此时栈顶元素为：%d\n", *e);
			return OK;
		}
	else
		printf("栈不存在！");
	return ERROR;
}

//入栈
Status Push(SqStack *S, SElemType e)
{
	if(S->base == NULL)
	{
		printf("栈不存在！");
		return ERROR;
	}
  	if(S->top - S->base >= S->stacksize)
  	{
	    //栈满，追加存储空间
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) 
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
  	}
	*S->top++=e;
	return OK;
}

//出栈
Status Pop(SqStack *S, SElemType *e)
{
	if(S->base == NULL)
	{
		printf("栈不存在！");
		return 2;
	}
  	if(S->top == S->base) 
	 	return ERROR;
    *e = *(--S->top);
  	return OK;
}

//遍历
Status StackTraverse(SqStack S)
{
	if(1 == StackEmpty(S))
		{
			printf("此时栈为空栈！\n");
			return ERROR;
		}
	else if(2 == StackEmpty(S))
		{
			printf("此时从栈顶到栈底遍历栈，得到如下序列：\n");
  			for(S.top--; S.top > S.base; S.top--)
    		printf("%d ", *S.top);
  			printf("%d\n", *S.top);
		return OK;
		}
	else
		printf("栈不存在！");
 	return ERROR;
}
