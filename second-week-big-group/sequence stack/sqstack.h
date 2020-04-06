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

//**********ջ��˳��洢��ʾ***************

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//**********���������ĺ���ԭ��˵��**********

Status InitStack(SqStack *S);
//����һ����ջS
Status DestroyStack(SqStack *S);
//����ջS��S���ٴ���
Status ClearStack(SqStack *S);
//��S��Ϊ��ջ
Status StackEmpty(SqStack S);
//��ջSΪ��ջ, ���� 1 
void StackLength(SqStack S);
//����S��Ԫ�ظ�������ջ�ĳ���
Status GetTop(SqStack S,SElemType *e);
//��ջ��Ϊ�գ�����*e����S��ջ��Ԫ��
Status Push(SqStack *S,SElemType e);
//����eΪ�µ�ջ��Ԫ��
Status Pop(SqStack *S,SElemType *e);
//��ջ���գ���ɾ��S��ջ��Ԫ��
Status StackTraverse(SqStack S);
//��ջ����ջ�ױ���ջ

//**********�����������㷨��������************

//��ʼ��
Status InitStack(SqStack *S)
{
  	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
  	if(!S->base) 
  	{ 
  		printf("�ڴ����ʧ��!"); 
  		exit(OVERFLOW);
  	} 
  	S->top = S->base;
  	S->stacksize = STACK_INIT_SIZE;
  	return OK;
}

//����
Status DestroyStack(SqStack *S)
{
	if(S->base == NULL)
	{
		printf("ջ�����ڣ�");
		return 2;
	}
	else
	{
        free(S->base);
        S->top = S->base = NULL;
        S->stacksize = 0; 
        printf("ջ������ϣ���ʱջ�����ڣ�\n");
    }
 	return OK;
}

//�ÿ�
Status ClearStack(SqStack *S)
{
	if(S->base == NULL)
	{
		printf("ջ�����ڣ�");
		return ERROR;
	}
  	S->top = S->base;
  	printf("ջ�ÿ���ϣ���ʱջΪ��ջ��\n");
  	return OK;
}

//�п�
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

//�ⳤ��
void StackLength(SqStack S)
{
	if(S.base == NULL)
	{
		printf("ջ�����ڣ�");
		return;
	}
    printf("ջ�ĳ���Ϊ%d\n", S.top-S.base);
}

//ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType *e)
{
	if(1 == StackEmpty(S))
		{
			printf("��ʱջΪ��ջ��\n");
		}
	else if(2 == StackEmpty(S))
		{
			*e = *(S.top - 1);
			printf("��ʱջ��Ԫ��Ϊ��%d\n", *e);
			return OK;
		}
	else
		printf("ջ�����ڣ�");
	return ERROR;
}

//��ջ
Status Push(SqStack *S, SElemType e)
{
	if(S->base == NULL)
	{
		printf("ջ�����ڣ�");
		return ERROR;
	}
  	if(S->top - S->base >= S->stacksize)
  	{
	    //ջ����׷�Ӵ洢�ռ�
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) 
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
  	}
	*S->top++=e;
	return OK;
}

//��ջ
Status Pop(SqStack *S, SElemType *e)
{
	if(S->base == NULL)
	{
		printf("ջ�����ڣ�");
		return 2;
	}
  	if(S->top == S->base) 
	 	return ERROR;
    *e = *(--S->top);
  	return OK;
}

//����
Status StackTraverse(SqStack S)
{
	if(1 == StackEmpty(S))
		{
			printf("��ʱջΪ��ջ��\n");
			return ERROR;
		}
	else if(2 == StackEmpty(S))
		{
			printf("��ʱ��ջ����ջ�ױ���ջ���õ��������У�\n");
  			for(S.top--; S.top > S.base; S.top--)
    		printf("%d ", *S.top);
  			printf("%d\n", *S.top);
		return OK;
		}
	else
		printf("ջ�����ڣ�");
 	return ERROR;
}
