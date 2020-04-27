#include "BinaryTree.h"

int i = 0, k = 0;
char str[100];		//����ǰ׺���ʽ

Status InitBiTree(BiTree *T) 	
{	
	*T = NULL;
	return SUCEESS;                              
}

Status DestroyBiTree(BiTree *T)
{
	if (*T)
    {
        if ((*T)->lchild) // ������ 
            DestroyBiTree(&(*T)->lchild); // ������������ 
        if ((*T)->rchild) // ���Һ��� 
            DestroyBiTree(&(*T)->rchild); // �����Һ������� 
        free(*T); // �ͷŸ���� 
        *T = NULL; 
		return SUCEESS;
    }
	else
		return ERROR;
}

Status CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);	//	��ȡ�ڵ�����
	
    if (ch == '#') 	//��#��սڵ�
		*T = NULL;
    else
	{
        *T = (BiTree)malloc(sizeof(BiTNode));
		if (*T == NULL)
		{
			printf("�����\n");
			exit(OVERFLOW);
		}
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));		//�ݹ�ʵ��
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
	BiTree p;	//�����ڵ�ָ��
    Queue queue;	//�������У���ڵ�ָ��
	queue.front = -1;
	queue.rear = 0;
	if (T)
		queue.qu[queue.rear] = T;     //���ڵ�ָ��������
	else 
		return ERROR;
    while (queue.front != queue.rear) //���в�Ϊ��
    {
		queue.front = (queue.front + 1) % MAXSIZE;
		p = queue.qu[queue.front];       //��ͷ������
        printf("%c ", p->data);  //���ʽڵ�
		
        if (p->lchild != NULL)    //������ʱ�������
        {
            queue.rear = (queue.rear + 1) % MAXSIZE;
            queue.qu[queue.rear] = p->lchild;
        }
        if (p->rchild != NULL)    //���Һ���ʱ�������
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
    if (NULL == T)	//������Ϊ��ʱ�����Ϊ0
    {
		Depth = 0;
		return Depth;
	}
    LDepth = GetDepth(T->lchild);
    RDepth = GetDepth(T->rchild);
    Depth = 1 + (LDepth >= RDepth ? LDepth : RDepth); 
	//�����Ϊ��������Ⱥ����������������߼�һ
    return Depth;
}


double CountBiTRree(BiTree *T)
{
    *T = (BiTree)malloc(sizeof(BiTNode));
	if (*T == NULL)
	{
		printf("�����\n");
		exit(-1);
	}
	(*T)->lchild = (*T)->rchild = NULL;
	
    char c;
    if (k >= strlen(str))	//��֤k�������ַ�������
	{
        i = 1;
        return 0;
    }
	
    c = str[k++];
    if (c - '0' >= 0 && c - '0' <= 9)	//���ַ�Ϊ1-9ʱ
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
    else if (c < '0' && str[k] - '0' >= 0 && str[k] - '0' <= 9)	//�����ź������ʱ
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
        if(b == 0)	//��������Ϊ0
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
	printf("����ǰ׺���ʽ���Կո���������ֻ���ţ�\n");
	gets(str);		    //���ǰ׺���ʽ
	double result = CountBiTRree(&T);	//��ü�����
	printf("= %.3lf\n", result);
	DestroyBiTree(&T);
	return SUCEESS;
}