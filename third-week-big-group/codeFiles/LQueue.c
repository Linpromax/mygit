#include "LQueue.h" 

void InitLQueue(LQueue *Q)
{	
	if(Q->front != NULL)
	{
		printf("已初始化过，勿重复操作！\n");
		return;
	}
	Q->front = Q->rear = (Node *)malloc(sizeof(Node));  //建头结点 
  	if( NULL == Q->front )
    	exit(OVERFLOW);  //分配失败 
  	Q->front->next = NULL;	//设置头结点指针域为NULL
	printf("初始化成功！\n");
}

void DestoryLQueue(LQueue *Q)
{
	while(Q->front)
  	{
    	Q->rear = Q->front->next;   //头结点指针域指向的节点指针赋给队尾指针 
    	free(Q->front);
    	Q->front = Q->rear;
  	}

}
 
Status IsEmptyLQueue(LQueue Q)
{
	if(Q.front->next == NULL)
    	return TRUE;
  	else
    	return FALSE;
}

Status GetHeadLQueue(LQueue Q, int *e)
{
	Node *p;
  	if(Q.front == Q.rear)
    	return FALSE;
  	p = Q.front->next;
  	*e = p->Ndata;
  	return TRUE;

}

int LengthLQueue(LQueue Q)
{
  	int length = 0;
   	Node *p;
  	p = Q.front;
  	while(Q.rear != p)
  	{
    	length++;
    	p=p->next;
  	}
  	return length;

}

Status EnLQueue(LQueue *Q, int *data)
{
	Node *p = (Node *)malloc(sizeof(Node));
  	if(NULL == p) // 内存分配失败 
    	exit(OVERFLOW);
  	p->Ndata = *data; //初始化节点 
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

Status DeLQueue(LQueue *Q, int *e)
{
	Node * p;
  	if(Q->front == Q->rear)
    	return FALSE;
	p = Q->front->next;   //首节点指针赋给p 
	*e = p->Ndata;
	Q->front->next = p->next;
  	if(Q->rear == p)   //当队列仅剩一个节点时 
    	Q->rear = Q->front;
  	free(p);
  	p = NULL;
  	return TRUE; 
}

void ClearLQueue(LQueue *Q)
{
	Node *p, *q;
  	Q->rear = Q->front;
  	p = Q->front->next;
  	Q->front->next = NULL;
  	while(NULL != p)
  	{
	    q = p;
	    p = p->next;
	    free(q);
  	}

} 

Status TraverseLQueue(const LQueue Q )
{
	if(Q.front == Q.rear)
		return FALSE;
	Node *p;
  	p = Q.front->next;
  	while(NULL != p)
  	{
    	printf("%d ", p->Ndata);
    	p = p->next;
  	}
  	printf("\n");
  	return TRUE;
}
