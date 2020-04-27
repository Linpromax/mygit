#include "BinaryTree.h"

int i = 0, k = 0;
char str[100];		//储存前缀表达式

Status InitBiTree(BiTree *T) 	
{	
	*T = NULL;
	return SUCEESS;                              
}

Status DestroyBiTree(BiTree *T)
{
	if (*T)
    {
        if ((*T)->lchild) // 有左孩子 
            DestroyBiTree(&(*T)->lchild); // 销毁左孩子子树 
        if ((*T)->rchild) // 有右孩子 
            DestroyBiTree(&(*T)->rchild); // 销毁右孩子子树 
        free(*T); // 释放根结点 
        *T = NULL; 
		return SUCEESS;
    }
	else
		return ERROR;
}

Status CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);	//	获取节点数据
	
    if (ch == '#') 	//遇#设空节点
		*T = NULL;
    else
	{
        *T = (BiTree)malloc(sizeof(BiTNode));
		if (*T == NULL)
		{
			printf("溢出！\n");
			exit(OVERFLOW);
		}
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));		//递归实现
        CreateBiTree(&((*T)->rchild));
    }
	return SUCEESS;
}

Status PreOrderTraverse(BiTree T)
{
	if (T)
    {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
		return SUCEESS;
    }
	else
		return ERROR;
}

Status InOrderTraverse(BiTree T)
{
	if (T)
    {
        InOrderTraverse(T->lchild);
		printf("%c ", T->data);
        InOrderTraverse(T->rchild);
		return SUCEESS;
    }
	else
		return ERROR;
}

Status PostOrderTraverse(BiTree T)
{
	if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
		printf("%c ", T->data);
		return SUCEESS;
    }
	else
		return ERROR;
}

Status LevelOrderTraverse(BiTree T)
{
	BiTree p;	//辅助节点指针
    Queue queue;	//辅助队列，存节点指针
	queue.front = -1;
	queue.rear = 0;
	if (T)
		queue.qu[queue.rear] = T;     //根节点指针进入队列
	else 
		return ERROR;
    while (queue.front != queue.rear) //队列不为空
    {
		queue.front = (queue.front + 1) % MAXSIZE;
		p = queue.qu[queue.front];       //队头出队列
        printf("%c ", p->data);  //访问节点
		
        if (p->lchild != NULL)    //有左孩子时将其进队
        {
            queue.rear = (queue.rear + 1) % MAXSIZE;
            queue.qu[queue.rear] = p->lchild;
        }
        if (p->rchild != NULL)    //有右孩子时将其进队
        {
            queue.rear = (queue.rear + 1) % MAXSIZE;
            queue.qu[queue.rear] = p->rchild;
        }
    }
	return SUCEESS;
}

Status BiTreeEmpty(BiTree T)
{
    if (T == NULL)
        return SUCEESS;
    else
        return ERROR;
}

int GetDepth(BiTree T) 
{
	int LDepth = 0, RDepth = 0, Depth = 0; 
    if (NULL == T)	//二叉树为空时深度设为0
    {
		Depth = 0;
		return Depth;
	}
    LDepth = GetDepth(T->lchild);
    RDepth = GetDepth(T->rchild);
    Depth = 1 + (LDepth >= RDepth ? LDepth : RDepth); 
	//总深度为左子树深度和右子树深度中最大者加一
    return Depth;
}


double CountBiTRree(BiTree *T)
{
    *T = (BiTree)malloc(sizeof(BiTNode));
	if (*T == NULL)
	{
		printf("溢出！\n");
		exit(-1);
	}
	(*T)->lchild = (*T)->rchild = NULL;
	
    char c;
    if (k >= strlen(str))	//保证k不大于字符串长度
	{
        i = 1;
        return 0;
    }
	
    c = str[k++];
    if (c - '0' >= 0 && c - '0' <= 9)	//当字符为1-9时
	{
        double sum;
        sum = c - '0';
        
        while (1)
		{
            c = str[k++];
            if(c < '0')
				break;
            sum = sum * 10 + c - '0';
        }
        return sum;
    }
    else if (c < '0' && str[k] - '0' >= 0 && str[k] - '0' <= 9)	//当符号后接数字时
	{
        double sum=0;
        char temp = c;
        
        while (1)
		{
            c = str[k++];
            
            if(c < '0')
				break;
            sum = sum * 10 + c - '0';
            
        }
        if (temp == '-')
			return -sum;
        else 
			return sum;
    }
    k++;
    double a = CountBiTRree(&(*T)->lchild);		
    double b = CountBiTRree(&(*T)->rchild);
    if (c == '+')
	{
        (*T)->num = a + b;
    }
    else if (c == '-')
	{
        (*T)->num = a - b;
    }
    else if (c == '*')
	{
        (*T)->num = a * b;
    }
    else if (c == '/')
	{
        if(b == 0)	//除数不能为0
		{
            i = 1;
            return 0;
        }
        (*T)->num = a / b;
    }
    return (*T)->num;
}

Status Count()
{
	BiTree T = NULL;
	printf("输入前缀表达式，以空格隔开各数字或符号：\n");
	gets(str);		    //获得前缀表达式
	double result = CountBiTRree(&T);	//获得计算结果
	printf("= %.3lf\n", result);
	DestroyBiTree(&T);
	return SUCEESS;
}