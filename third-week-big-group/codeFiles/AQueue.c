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
		printf("队列初始化成功！\n"); 
	} 
	else  //队列已存在 
	{
		printf("已初始化过，勿重复操作！\n");
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
		return FALSE;   // 队空
 	*e = Q->array[Q->front];          // 取队头元素        
  	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	return( (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE ); //取余防止溢出 
} 

Status EnAQueue(AQueue *Q, int *data)
{
	if( (Q->rear + 1) % MAXQUEUE == Q->front ) 
		return FALSE; // 队满
		
 	Q->array[Q->rear] = *data;                      // 入队
 	Q->rear = (Q->rear + 1) % MAXQUEUE;             // 修改队尾指针 
  	return TRUE;
}

Status DeAQueue(AQueue *Q, int *e)
{
	if( IsEmptyAQueue(Q) )
		return FALSE;       // 队空 
 	*e = Q->array[Q->front];               // 取队头元素       
 	Q->front = (Q->front + 1) % MAXQUEUE;       // 修改队头指针
  	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q)
{
	if( IsEmptyAQueue(Q) )	
		return FALSE; //队空 
		 
	int i;
    i = Q->front;
    printf("队列："); 
    while(i != Q->rear)  //逐个打印 
    {
        printf("%d ", Q->array[i]);
        i = ( i + 1) % MAXQUEUE;
    }
    printf("\n");
    return TRUE; 
}


