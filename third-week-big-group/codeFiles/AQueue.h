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
//循环队列结构
typedef struct Aqueue
{
    int array[MAXQUEUE];      //数组域 
    int front; //队头下标 
    int rear;  //队尾下标 
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
 *    @description : 创建（初始化）队列
 *    @param         队列指针Q的指针Qp
 *  @notice      : 队列是否已创建 
 */
void InitAQueue(AQueue **Qp);


/**
 *  @name        : void DestoryAQueue(AQueue **Qp)
 *    @description : 销毁队列
 *    @param          队列指针Q的指针Qp
 *  @notice      : 队列是否不存在 
 */
void DestoryAQueue(AQueue **Qp);



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : 队列是否不存在 
 */
Status IsEmptyAQueue(const AQueue *Q);



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, int *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素指针e 
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空, 队列是否不存在 
 */
Status GetHeadAQueue(AQueue *Q, int *e);		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : 队列是否不存在 
 */
int LengthAQueue(AQueue *Q);	



/**
 *  @name        : Status EnAQueue(AQueue *Q, int *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了, 队列是否不存在 
 */
Status EnAQueue(AQueue *Q, int *data);	



/**
 *  @name        : Status DeAQueue(AQueue *Q, int *e)
 *    @description : 出队操作
 *    @param         Q 队列指针Q, 出队元素指针 
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空 ,队列是否不存在 
 */
Status DeAQueue(AQueue *Q, int *e);		



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : 队列是否不存在 
 */
void ClearAQueue(AQueue *Q);	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q)
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q
 *    @return         : None
 *  @notice      : 队列是否不存在 
 */
Status TraverseAQueue(const AQueue *Q);	


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/

#endif // AQUEUE_H_INCLUDED


