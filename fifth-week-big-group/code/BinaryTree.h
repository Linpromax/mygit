/**
 *  @file        : BinaryTree.h
 *  @system      : Win10
 *  @date        : 2020.4.26
 */

#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OVERFLOW -1
#define MAXSIZE 100

typedef char TElemType;     // 设二叉树结点的数据为字符

typedef struct BiTNode
{
	double num;
    TElemType data;     // 数据域
    struct BiTNode  *lchild, *rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   

typedef struct Queue	//层序遍历方法中的辅助队列
{
	int front, rear;	//队首，队尾的下标
	BiTree qu[MAXSIZE];	//定义环形队列,存放节点指针
} Queue;

typedef enum
{
	ERROR = 0,
	SUCEESS
}Status;


/**
 *  @name        : Status InitBiTree(BiTree *T)
 *  @description : 初始化空二叉树T
 *  @param       : 
 */
Status InitBiTree(BiTree *T);

/**
 *  @name        : Status DestroyBiTree(BiTree *T)
 *  @description : 摧毁二叉树T
 *  @param       : 
 */
Status DestroyBiTree(BiTree *T);

/**
 *  @name        : Status CreateBiTree(BiTree *T)
 *  @description : 构造二叉树T
 *  @param       : 
 */
Status CreateBiTree(BiTree *T);

/**
 *  @name        : Status PreOrderTraverse(BiTree T)
 *  @description : 前序遍历
 *  @param       : 
 */
Status PreOrderTraverse(BiTree T);

/**
 *  @name        : Status InOrderTraverse(BiTree T)
 *  @description : 中序遍历
 *  @param       : 
 */
Status InOrderTraverse(BiTree T);	

/**
 *  @name        : Status PostOrderTraverse(BiTree T)
 *  @description : 后序遍历
 *  @param       : 
 */
Status PostOrderTraverse(BiTree T);	

/**
 *  @name        : Status LevelOrderTraverse(BiTree T)
 *  @description : 层序遍历
 *  @param       : 
 */
Status LevelOrderTraverse(BiTree T);	

/**
 *  @name        : Status BiTreeEmpty(BiTree T)
 *  @description : 判断二叉树是否为空
 *  @param       : 
 */
Status BiTreeEmpty(BiTree T);

/**
 *  @name        : int GetDepth(BiTree T)
 *  @description : 获取树的深度
 *  @return      : 深度Depth
 */
int GetDepth(BiTree T);

/**
 *  @name        : double CountBiTRree(BiTree *T)
 *  @description : 获计算结果
 *  @return      : 计算结果result
 */
double CountBiTRree(BiTree *T);

/**
 *  @name        : Status Count()
 *  @description : 获取前缀表达式并计算
 *  @return      : 
 */
Status Count();
#endif
