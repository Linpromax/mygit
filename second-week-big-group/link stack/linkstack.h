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

//**********ջ����ʽ�洢��ʾ***************
typedef int LElemType;

//���ṹ
typedef struct StackNode
{
  	LElemType data;
  	struct StackNode *next;
}StackNode;

//��ջ�ṹ
typedef struct LinkStack
{
  	struct StackNode *top;
  	int count;
}LinkStack;
//**********���������ĺ���ԭ��˵��**********

Status InitStack(LinkStack *S, int *pdestroyed);
//����һ����ջS
int DestroyStack(LinkStack *S, int *pdestroyed);
//����ջS��S���ٴ���
Status ClearStack(LinkStack *S);
//��S��Ϊ��ջ
Status StackEmpty(LinkStack S);
//��ջSΪ��ջ���򷵻�TRUE,���򷵻�FALSE
int StackLength(LinkStack S);
//����S��Ԫ�ظ�������ջ�ĳ���
Status GetTop(LinkStack S, LElemType *e);
//��ջ���գ�����*e����S��ջ��Ԫ��
Status Push(LinkStack *S, LElemType e);
//����eΪ�µ�ջ��Ԫ��
Status Pop(LinkStack *S, LElemType *e);
//��ջ���գ���ɾ��S��ջ��Ԫ��
Status StackTraverse(LinkStack S);
//��ջ����ջ�ױ���ջ

//**********�����������㷨��������************

//��ʼ��
Status InitStack(LinkStack *S, int *pdestroyed)
{
	S->top = NULL;
	S->count = 0;
	*pdestroyed = 1;
	return OK;
}

//����
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

//�ÿ�
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

//�п�
Status StackEmpty(LinkStack S)
{
  	if(!S.count)
   	 	return TRUE;
  	else
    	return FALSE;
}

//�ⳤ��
int StackLength(LinkStack S)
{
  	return S.count;
}

//ȡջ��Ԫ��
Status GetTop(LinkStack S,LElemType *e)
{
  	if(!S.count) 
	  	return ERROR;
  	*e = S.top->data;
  	return OK;
}

//��ջ
Status Push(LinkStack *S, LElemType e)
{
  	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
  	if(!p) 
  	{
  		printf("�ڴ����ʧ�ܣ�"); 
  		exit(OVERFLOW);
  	}
  	p->data = e;
  	p->next = S->top;
  	S->top = p;
  	S->count++;
  	return OK;
}

//��ջ
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

//����
Status StackTraverse(LinkStack S)
{
  	while(S.top)
  	{
    	printf("%d ", S.top->data);
		S.top = S.top->next;
  	}
  	return OK;
}
