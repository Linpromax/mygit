/***************************************************************************************
 *    File Name                :    AQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Win10
 *    Create Data                :    2020.4.11
 *    Author/Corportation        :   Lin RongXiao
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/**************************************************************
 *    Macro Define Section
 **************************************************************/
#define MAXQUEUE 10
#define OVERFLOW -1
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//ѭ�����нṹ
typedef struct Aqueue
{
    int array[MAXQUEUE];      //������ 
    int front; //��ͷ�±� 
    int rear;  //��β�±� 
} AQueue;

typedef enum
{
	FALSE = 0, TRUE = 1, ERROR = 2
} Status;

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue **Qp)
 *    @description : ��������ʼ��������
 *    @param         ����ָ��Q��ָ��Qp
 *  @notice      : �����Ƿ��Ѵ��� 
 */
void InitAQueue(AQueue **Qp);


/**
 *  @name        : void DestoryAQueue(AQueue **Qp)
 *    @description : ���ٶ���
 *    @param          ����ָ��Q��ָ��Qp
 *  @notice      : �����Ƿ񲻴��� 
 */
void DestoryAQueue(AQueue **Qp);



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : �����Ƿ񲻴��� 
 */
Status IsEmptyAQueue(const AQueue *Q);



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, int *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��ָ��e 
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��, �����Ƿ񲻴��� 
 */
Status GetHeadAQueue(AQueue *Q, int *e);		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : �����Ƿ񲻴��� 
 */
int LengthAQueue(AQueue *Q);	



/**
 *  @name        : Status EnAQueue(AQueue *Q, int *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�����, �����Ƿ񲻴��� 
 */
Status EnAQueue(AQueue *Q, int *data);	



/**
 *  @name        : Status DeAQueue(AQueue *Q, int *e)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q, ����Ԫ��ָ�� 
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ�� ,�����Ƿ񲻴��� 
 */
Status DeAQueue(AQueue *Q, int *e);		



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : �����Ƿ񲻴��� 
 */
void ClearAQueue(AQueue *Q);	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q)
 *    @description : ������������
 *    @param         Q ����ָ��Q
 *    @return         : None
 *  @notice      : �����Ƿ񲻴��� 
 */
Status TraverseAQueue(const AQueue *Q);	


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/

#endif // AQUEUE_H_INCLUDED


