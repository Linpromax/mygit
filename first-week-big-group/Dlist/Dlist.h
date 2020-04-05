/***************************************************************************************
 *	File Name				:   Dlist.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Date  			:	2020.4.1 
 ***************************************************************************************/

#ifndef _Dlist_H_
#define _Dlist_H_

#include <stdio.h>
#include <stdlib.h>

enum {create_List = 1, print_List, insert_Node, delete_Node, delete_List, quit};  //用于菜单选择
   
struct list  //结点结构
{ 
	int data; 
	struct list * next; 
};
typedef struct list node;
int n = 0, input; 
node * head=NULL ;

/**
 *  @name        : node * CreateList( ); 
 *	@description : create a list
 *	@param		 : None
 *	@return		 : node *
 *  @notice      : None
 */
node * CreateList(); 

/**
 *  @name        : void PrintList( node * head)
 *	@description : Print the whole list
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void PrintList( node * head);

/**
 *  @name        : node * InsertNode(node * head, node *stu)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : head, stu
 *	@return		 : node *
 *  @notice      : None
 */
node * InsertNode(node * head, node *stu);

/**
 *  @name        : node * DeleteNode(node *head, int delData) 
 *	@description : delete a node by its value
 *	@param		 : L(the head node)
 *	@return		 : node *
 *  @notice      : None
 */
node * DeleteNode(node *head, int delData); 

/**
 *  @name        : node * deleteList(node * head)
 *	@description : delete the whole list
 *	@param		 : head(the head node)
 *	@return		 : node *
 *  @notice      : None
 */
node * deleteList(node * head);

/**
 *  @name        : int Menu()
 *	@description : show the menu
 *	@param		 : None
 *	@return		 : int
 *  @notice      : None
 */
int Menu();

/**
 *  @name        : void Create()
 *	@description : creat a list by CreateList()
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
void Create();

/**
 *  @name        : void Print()
 *	@description : Print the list by PrintList()
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
void Print();

/**
 *  @name        : void Insert()
 *	@description : insert a node after the first node by InsertNode()
 *	@param		 : 
 *	@return		 : 
 *  @notice      : 
 */
void Insert();

/**
 *  @name        : void Delete()
 *	@description : delete nodes by DeleteNode()
 *	@param		 : 
 *	@return		 : 
 *  @notice      : 
 */
void Delete();

/**
 *  @name        : void DeleteAll()
 *	@description : delete list by DeleteNode()
 *	@param		 : 
 *	@return		 : 
 *  @notice      : 
 */
void DeleteAll();

node * CreateList()  
{ 
	node * s, * p ; // s指向新结点，p指向链表中最后的结点   
  	int predata;  //用来标识当前链表中最后一个结点的数据值
 	s = (node *)malloc(sizeof( node));   //动态建立第一个新结点 
 	
	printf("\n请输入一个整数值作为新结点的数据信息,输入0时建立链表结束."); 
  	printf("\n第%d个结点:", n + 1);
  	fflush(stdin);
  	input = scanf("%d", &(s->data));
	while(1 != input)
	{
		printf("输入错误！请正确输入：");
		fflush(stdin); 
		input = scanf("%d", &(s->data));
	}  
	
  	predata = s->data;
  	head = NULL;   //头指针初始值为NULL   
  	if( s->data == 0)  //第一个结点数据就为0，建立一个空链表   
  	{  
  		printf("您建立的空链表.\n");
      	free(s);  //释放数据为0的结点   
  	}  
  	else //建立非空链表   
  	{  
      	while ( s->data != 0 )  //通过判断新结点数据来进行循环   
      	{ 	
			if ( head == NULL )  
			  	head = s ; //头指针赋值   
        	else  
			  	p->next = s ;
			  	
	        p = s ; // p指向链表中最后的结点    
	        n = n + 1; //结点个数增1   
	        s = (node *)malloc(sizeof( node));  //动态建立一个新结点  
			 
	        printf("\n请输入一个整数值作为新结点的数据信息,输入0时建立链表结束.");
	        printf("\n第%d个结点:", n + 1);
	        fflush(stdin);
	        input = scanf("%d", &(s->data));
			while(1 != input)
			{
				printf("输入错误！请正确输入：");
				fflush(stdin); 
				input = scanf("%d", &(s->data));     //输入新结点数据 
			}   
	
		if(s->data == 0 )  //如果输入的新结点数据为0，则退出当前循环
			break;
		predata = s->data;
      }  
      p -> next = NULL ; //设置链表尾部为空   
      free(s) ;  //释放数据为0的结点 
	  printf("------------------\n");  
      printf("链表建立完成.\n");  
      printf("建立的链表中共有%d个结点.\n", n);  
  }  
  	return (head); //返回头指针    
}  
  
/*遍历链表*/
void PrintList( node * head)  //输出链表中结点信息函数,链表遍历
{    
	node *p = head;
    int i = 1;
	printf("遍历链表:\n");
    if(head != NULL)  //如果链表非空，即链表中有结点
        do             //循环输出接点数据，直到移动到链表尾，即最后一个结点
		{   
			printf("第%d个结点数据为:%d\n", i++, p->data); 
            p = p->next;				
        }while(p != NULL) ;
	else
	{
	  	printf("链表是空链表!\n");
	}
	printf("链表中共有%d个结点.\n", n);
}
 
/*插入结点*/  
node * InsertNode(node * head, node * s)  //插入结点的函数，head为链表头指针，s指向要插入的新结点
{
	node *p;                         
 	p = head;   //使p指向链表中的第一个结点      
 	if(head == NULL)      //原来的链表是空表
 	{
 		head = s;           //使head指向的新结点作为头结点
   		s->next = NULL;     
 	}          
 	else  //原来的链表不是空表
 	{
		s->next = p->next;
		p->next = s;         
	 	  
 	} 
   	n = n + 1;          //结点数加１ 
   	printf("成功完成一个新结点插入.\n");
   	return (head);
}
               
/*删除结点*/
node * DeleteNode(node *head, int delData)   //删除数据为delDate的结点的函数   
{	
	int i = 1; 
	node *p, *q;   
    p = head;          //使p指向第一个结点   
 	if(head == NULL)     //是空表   
 	{ 
	 	printf("该链表是空链表，不能进行结点删除!\n");   
   		return (head);  
 	}  
 //先找到要删除的结点    
 			                     
	 	while(delData != p->data && p->next != NULL ) //p指向的不是所要找的结点且后面还有结点 
	 	{	
		 	i++;
		 	q = p;  //q用来记录p前一个结点   
	   		p = p->next;  
		         //p后移一个结点  
		} 
	  		if(delData == p->data)      //找到了要删除的结点   
	  		{ 
				do
				{
			 		if(p == head)  //如果要删除的是头结点   
					{
						head = p->next;   //若p指向的是首结点，把第二个结点地址赋予head  
		      			n = n - 1;
			  			free(p);
			  			p = head;
			 		}
	    			else 
					{ 
						q->next = p->next;  //否则将下一结点地址赋给前一结点地址     
		  				n = n - 1;
		  				free(p);  //释放被删除结点空间
	 	  				p = q->next;
					}
				}while(p != NULL && p->data == delData);  
	 
				printf("成功删除数据为%d的结点.\n", delData); 
				printf("------------------\n");    
	 		}       
	if(i == n)
		printf("要删除的数据为%d的结点在链表中没有找到.\n", delData);    //找不到该结点  
 	return (head);  
}  
 
 
 
/*删除整个链表*/
node * deleteList(node * head) //删除整个链表
{ 
  	node *p, *s;
 	p = head;
  	if(head == NULL)
	  	printf("链表本身就为空链表.\n");
  	else
  	{
	  	while(p->next != NULL)
	  	{
	     	s = p;
		 	p = p->next;
		 	free(s);
		 	n--;
	  	}  
	  	
	  	free(p);
	  	n--;
     	head = NULL;
  }
  	printf("整个链表删除成功!\n");
	return (head);
}
 
 
/*菜单函数*/
int Menu()
{  
	int choice;
	printf("------------------");
	printf("\n链表操作菜单\n");
	printf("1 创建链表\n");
	printf("2 遍历链表\n");
	printf("3 头结点后插入结点\n");
	printf("4 删除链表结点\n");
	printf("5 删除整个链表\n");
	printf("6 退出程序\n"); 
    printf("------------------");
    printf("\n请输入功能序号:");
    fflush(stdin);
    input = scanf("%d", &choice);
	while(1 != input || (1 > choice || 6 < choice))
	{
		printf("输入错误！请正确输入：");
		fflush(stdin); 
		input = scanf("%d", &choice);    //输入功能选择 
	}
    return (choice);
}
 
/*对应操作菜单--创建链表的操作*/
void Create()
{
    if(head == NULL) //如果链表中已有结点，不允许重新建立
	{
	  	head = CreateList( ); 
	}
	else
	{
	  	printf("已创建过链表，不允许再次创建\n");
	  	printf("如果想重新创建，先删除原先链表\n");	  
	}
}
 
/*对应操作菜单--遍历链表的操作*/
void Print( )
{
   	PrintList(head);
}
 
/*对应操作菜单--头结点后插入结点的操作*/
void Insert( )
{  
  	char IsGo;  //是否继续操作标志
  	IsGo ='y';
  	printf("\n开始进行结点插入操作:");  
  	node * stu;   
  	while(IsGo == 'y' || IsGo == 'Y')  
  	{   
	   	stu = (node *)malloc(sizeof( node));    //创建要插入的新结点
      	printf("\n输入要插入的新结点数据:"); 
      	fflush(stdin);
      	input = scanf("%d", &(stu->data));
		while(1 != input)
		{
			printf("输入错误！请正确输入：");
			fflush(stdin); 
			input = scanf("%d", &(stu->data));     //输入要插入的新结点数据 	 
		} 
      	  
	  	head = InsertNode(head, stu);    //调用插入函数，返回链表头指针
	  	printf("------------------\n");
	  	printf("\n是否继续插入新结点? (继续插入请按y或Y,退出请按其它键):");
	  	fflush(stdin);
	  	input = scanf("%c", &IsGo);
		while(1 != input)
		{
			printf("输入错误！请正确输入：");
			fflush(stdin); 
			input = scanf("%c", &IsGo);    //输入是否继续的选择	 
		} 
      	
  	}
  	printf("结点插入操作结束.\n");
}
 
/*对应操作菜单--删除链表结点的操作*/
void Delete( )
{
   	char IsGo;  //是否继续操作标志
   	int del_num;	//要删除的结点的数据
   	IsGo = 'y';
   	printf("\n开始进行结点删除操作:");  
   	
   	while(IsGo == 'y' || IsGo == 'Y')
   	{
	    printf("\n输入要删除的节点的数据:");  
	    fflush(stdin);
	    input = scanf("%d", &del_num); 
		while(1 != input)
		{
			printf("输入错误！请正确输入：");
			fflush(stdin); 
			input = scanf("%d", &del_num);     //输入要删除的结点的数据	 
		} 
	   	
	    head = DeleteNode(head, del_num);    //删除后,链表的头地址
	    printf("------------------\n");
        printf("\n是否继续删除结点? (继续插入请按y或Y,退出请按其它键):");
        fflush(stdin);
        input = scanf("%c", &IsGo);
		while(1 != input)
		{
			printf("输入错误！请正确输入：");
			fflush(stdin); 
			input = scanf("%c", &IsGo);    //输入是否继续的选择	 
		} 
     
 	}
    printf("结点删除操作结束.\n");
}
 
/*对应操作菜单--删除整个链表的操作*/
void DeleteAll()
{
  head = deleteList(head);

}
#endif 
