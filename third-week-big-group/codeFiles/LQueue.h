/***************************************************************************************
 *    File Name                :    LQueue.h
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
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW -1
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//��ʽ���нṹ
typedef struct node
{
    int Ndata;                   //������
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;		

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q);

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q);

/**
 *  @name        : Status IsEmptyLQueue(LQueue Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         ���нṹ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         ���нṹ��Q, ����ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue Q, int *e);

/**
 *  @name        : int LengthLQueue(LQueue Q)
 *    @description : ȷ�����г���
 *    @param          ���нṹ��Q 
 *    @return         : ����length 
 *  @notice      : None
 */
int LengthLQueue(LQueue Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, int *data);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, int *e);

/**
 *  @name        : void ClearLQueue(LQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q, 
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue Q )
 *    @description : ������������
 *    @param         Q ���нṹ�� 
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue Q );



/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 

#endif // LQUEUE_H_INCLUDED


