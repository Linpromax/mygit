#include "LQueue.h" 

void InitLQueue(LQueue *Q)
{	
	if(Q->front != NULL)
	{
		printf("�ѳ�ʼ���������ظ�������\n");
		return;
	}
	Q->front = Q->rear = (Node *)malloc(sizeof(Node));  //��ͷ��� 
  	if( NULL == Q->front )
    	exit(OVERFLOW);  //����ʧ�� 
  	Q->front->next = NULL;	//����ͷ���ָ����ΪNULL
	printf("��ʼ���ɹ���\n");
}

void DestoryLQueue(LQueue *Q)
{
	while(Q->front)
  	{
    	Q->rear = Q->front->next;   //ͷ���ָ����ָ��Ľڵ�ָ�븳����βָ�� 
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
  	if(NULL == p) // �ڴ����ʧ�� 
    	exit(OVERFLOW);
  	p->Ndata = *data; //��ʼ���ڵ� 
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
	p = Q->front->next;   //�׽ڵ�ָ�븳��p 
	*e = p->Ndata;
	Q->front->next = p->next;
  	if(Q->rear == p)   //�����н�ʣһ���ڵ�ʱ 
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
