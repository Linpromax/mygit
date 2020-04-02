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

enum {create_List = 1, print_List, insert_Node, delete_Node, delete_List, quit};  //���ڲ˵�ѡ��
   
struct list  //���ṹ
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
	node * s, * p ; // sָ���½�㣬pָ�����������Ľ��   
  	int predata;  //������ʶ��ǰ���������һ����������ֵ
 	s = (node *)malloc(sizeof( node));   //��̬������һ���½�� 
 	
	printf("\n������һ������ֵ��Ϊ�½���������Ϣ,����0ʱ�����������."); 
  	printf("\n��%d�����:", n + 1);
  	fflush(stdin);
  	input = scanf("%d", &(s->data));
	while(1 != input)
	{
		printf("�����������ȷ���룺");
		fflush(stdin); 
		input = scanf("%d", &(s->data));
	}  
	
  	predata = s->data;
  	head = NULL;   //ͷָ���ʼֵΪNULL   
  	if( s->data == 0)  //��һ��������ݾ�Ϊ0������һ��������   
  	{  
  		printf("�������Ŀ�����.\n");
      	free(s);  //�ͷ�����Ϊ0�Ľ��   
  	}  
  	else //�����ǿ�����   
  	{  
      	while ( s->data != 0 )  //ͨ���ж��½������������ѭ��   
      	{ 	
			if ( head == NULL )  
			  	head = s ; //ͷָ�븳ֵ   
        	else  
			  	p->next = s ;
			  	
	        p = s ; // pָ�����������Ľ��    
	        n = n + 1; //��������1   
	        s = (node *)malloc(sizeof( node));  //��̬����һ���½��  
			 
	        printf("\n������һ������ֵ��Ϊ�½���������Ϣ,����0ʱ�����������.");
	        printf("\n��%d�����:", n + 1);
	        fflush(stdin);
	        input = scanf("%d", &(s->data));
			while(1 != input)
			{
				printf("�����������ȷ���룺");
				fflush(stdin); 
				input = scanf("%d", &(s->data));     //�����½������ 
			}   
	
		if(s->data == 0 )  //���������½������Ϊ0�����˳���ǰѭ��
			break;
		predata = s->data;
      }  
      p -> next = NULL ; //��������β��Ϊ��   
      free(s) ;  //�ͷ�����Ϊ0�Ľ�� 
	  printf("------------------\n");  
      printf("���������.\n");  
      printf("�����������й���%d�����.\n", n);  
  }  
  	return (head); //����ͷָ��    
}  
  
/*��������*/
void PrintList( node * head)  //��������н����Ϣ����,�������
{    
	node *p = head;
    int i = 1;
	printf("��������:\n");
    if(head != NULL)  //�������ǿգ����������н��
        do             //ѭ������ӵ����ݣ�ֱ���ƶ�������β�������һ�����
		{   
			printf("��%d���������Ϊ:%d\n", i++, p->data); 
            p = p->next;				
        }while(p != NULL) ;
	else
	{
	  	printf("�����ǿ�����!\n");
	}
	printf("�����й���%d�����.\n", n);
}
 
/*������*/  
node * InsertNode(node * head, node * s)  //������ĺ�����headΪ����ͷָ�룬sָ��Ҫ������½��
{
	node *p;                         
 	p = head;   //ʹpָ�������еĵ�һ�����      
 	if(head == NULL)      //ԭ���������ǿձ�
 	{
 		head = s;           //ʹheadָ����½����Ϊͷ���
   		s->next = NULL;     
 	}          
 	else  //ԭ���������ǿձ�
 	{
		s->next = p->next;
		p->next = s;         
	 	  
 	} 
   	n = n + 1;          //������ӣ� 
   	printf("�ɹ����һ���½�����.\n");
   	return (head);
}
               
/*ɾ�����*/
node * DeleteNode(node *head, int delData)   //ɾ������ΪdelDate�Ľ��ĺ���   
{	
	int i = 1; 
	node *p, *q;   
    p = head;          //ʹpָ���һ�����   
 	if(head == NULL)     //�ǿձ�   
 	{ 
	 	printf("�������ǿ��������ܽ��н��ɾ��!\n");   
   		return (head);  
 	}  
 //���ҵ�Ҫɾ���Ľ��    
 			                     
	 	while(delData != p->data && p->next != NULL ) //pָ��Ĳ�����Ҫ�ҵĽ���Һ��滹�н�� 
	 	{	
		 	i++;
		 	q = p;  //q������¼pǰһ�����   
	   		p = p->next;  
		         //p����һ�����  
		} 
	  		if(delData == p->data)      //�ҵ���Ҫɾ���Ľ��   
	  		{ 
				do
				{
			 		if(p == head)  //���Ҫɾ������ͷ���   
					{
						head = p->next;   //��pָ������׽�㣬�ѵڶ�������ַ����head  
		      			n = n - 1;
			  			free(p);
			  			p = head;
			 		}
	    			else 
					{ 
						q->next = p->next;  //������һ����ַ����ǰһ����ַ     
		  				n = n - 1;
		  				free(p);  //�ͷű�ɾ�����ռ�
	 	  				p = q->next;
					}
				}while(p != NULL && p->data == delData);  
	 
				printf("�ɹ�ɾ������Ϊ%d�Ľ��.\n", delData); 
				printf("------------------\n");    
	 		}       
	if(i == n)
		printf("Ҫɾ��������Ϊ%d�Ľ����������û���ҵ�.\n", delData);    //�Ҳ����ý��  
 	return (head);  
}  
 
 
 
/*ɾ����������*/
node * deleteList(node * head) //ɾ����������
{ 
  	node *p, *s;
 	p = head;
  	if(head == NULL)
	  	printf("�������Ϊ������.\n");
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
  	printf("��������ɾ���ɹ�!\n");
	return (head);
}
 
 
/*�˵�����*/
int Menu()
{  
	int choice;
	printf("------------------");
	printf("\n��������˵�\n");
	printf("1 ��������\n");
	printf("2 ��������\n");
	printf("3 ͷ���������\n");
	printf("4 ɾ��������\n");
	printf("5 ɾ����������\n");
	printf("6 �˳�����\n"); 
    printf("------------------");
    printf("\n�����빦�����:");
    fflush(stdin);
    input = scanf("%d", &choice);
	while(1 != input || (1 > choice || 6 < choice))
	{
		printf("�����������ȷ���룺");
		fflush(stdin); 
		input = scanf("%d", &choice);    //���빦��ѡ�� 
	}
    return (choice);
}
 
/*��Ӧ�����˵�--��������Ĳ���*/
void Create()
{
    if(head == NULL) //������������н�㣬���������½���
	{
	  	head = CreateList( ); 
	}
	else
	{
	  	printf("�Ѵ����������������ٴδ���\n");
	  	printf("��������´�������ɾ��ԭ������\n");	  
	}
}
 
/*��Ӧ�����˵�--��������Ĳ���*/
void Print( )
{
   	PrintList(head);
}
 
/*��Ӧ�����˵�--ͷ���������Ĳ���*/
void Insert( )
{  
  	char IsGo;  //�Ƿ����������־
  	IsGo ='y';
  	printf("\n��ʼ���н��������:");  
  	node * stu;   
  	while(IsGo == 'y' || IsGo == 'Y')  
  	{   
	   	stu = (node *)malloc(sizeof( node));    //����Ҫ������½��
      	printf("\n����Ҫ������½������:"); 
      	fflush(stdin);
      	input = scanf("%d", &(stu->data));
		while(1 != input)
		{
			printf("�����������ȷ���룺");
			fflush(stdin); 
			input = scanf("%d", &(stu->data));     //����Ҫ������½������ 	 
		} 
      	  
	  	head = InsertNode(head, stu);    //���ò��뺯������������ͷָ��
	  	printf("------------------\n");
	  	printf("\n�Ƿ���������½��? (���������밴y��Y,�˳��밴������):");
	  	fflush(stdin);
	  	input = scanf("%c", &IsGo);
		while(1 != input)
		{
			printf("�����������ȷ���룺");
			fflush(stdin); 
			input = scanf("%c", &IsGo);    //�����Ƿ������ѡ��	 
		} 
      	
  	}
  	printf("�������������.\n");
}
 
/*��Ӧ�����˵�--ɾ��������Ĳ���*/
void Delete( )
{
   	char IsGo;  //�Ƿ����������־
   	int del_num;	//Ҫɾ���Ľ�������
   	IsGo = 'y';
   	printf("\n��ʼ���н��ɾ������:");  
   	
   	while(IsGo == 'y' || IsGo == 'Y')
   	{
	    printf("\n����Ҫɾ���Ľڵ������:");  
	    fflush(stdin);
	    input = scanf("%d", &del_num); 
		while(1 != input)
		{
			printf("�����������ȷ���룺");
			fflush(stdin); 
			input = scanf("%d", &del_num);     //����Ҫɾ���Ľ�������	 
		} 
	   	
	    head = DeleteNode(head, del_num);    //ɾ����,�����ͷ��ַ
	    printf("------------------\n");
        printf("\n�Ƿ����ɾ�����? (���������밴y��Y,�˳��밴������):");
        fflush(stdin);
        input = scanf("%c", &IsGo);
		while(1 != input)
		{
			printf("�����������ȷ���룺");
			fflush(stdin); 
			input = scanf("%c", &IsGo);    //�����Ƿ������ѡ��	 
		} 
     
 	}
    printf("���ɾ����������.\n");
}
 
/*��Ӧ�����˵�--ɾ����������Ĳ���*/
void DeleteAll()
{
  head = deleteList(head);

}
#endif 
