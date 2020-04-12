#include "AQueue.h"

void InitAQueue(AQueue **Qp)
{
	if(NULL == *Qp)
	{	
		*Qp = (AQueue *)malloc( sizeof(AQueue) );
		if(NULL == Qp)
		{
			exit(OVERFLOW);
		}
		(*Qp)->front = (*Qp)->rear = 0;
		printf("���г�ʼ���ɹ���\n"); 
	} 
	else  //�����Ѵ��� 
	{
		printf("�ѳ�ʼ���������ظ�������\n");
	} 
}

void DestoryAQueue(AQueue **Qp)
{
		free(*Qp); 
		*Qp = NULL;
}
	

Status IsFullAQueue(const AQueue *Q)
{
	if( (Q->rear + 1) % MAXQUEUE == Q->front)  
        return TRUE;
    else
        return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->front == Q->rear)
        return TRUE;
    else
     	return FALSE;
}

Status GetHeadAQueue(AQueue *Q, int *e)
{
	if(Q->front == Q->rear) 
		return FALSE;   // �ӿ�
 	*e = Q->array[Q->front];          // ȡ��ͷԪ��        
  	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	return( (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE ); //ȡ���ֹ��� 
} 

Status EnAQueue(AQueue *Q, int *data)
{
	if( (Q->rear + 1) % MAXQUEUE == Q->front ) 
		return FALSE; // ����
		
 	Q->array[Q->rear] = *data;                      // ���
 	Q->rear = (Q->rear + 1) % MAXQUEUE;             // �޸Ķ�βָ�� 
  	return TRUE;
}

Status DeAQueue(AQueue *Q, int *e)
{
	if( IsEmptyAQueue(Q) )
		return FALSE;       // �ӿ� 
 	*e = Q->array[Q->front];               // ȡ��ͷԪ��       
 	Q->front = (Q->front + 1) % MAXQUEUE;       // �޸Ķ�ͷָ��
  	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q)
{
	if( IsEmptyAQueue(Q) )	
		return FALSE; //�ӿ� 
		 
	int i;
    i = Q->front;
    printf("���У�"); 
    while(i != Q->rear)  //�����ӡ 
    {
        printf("%d ", Q->array[i]);
        i = ( i + 1) % MAXQUEUE;
    }
    printf("\n");
    return TRUE; 
}


