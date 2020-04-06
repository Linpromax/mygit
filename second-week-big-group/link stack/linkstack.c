#include<stdio.h>
#include<stdlib.h>
#include"Linkstack.h"

int isdestroyed = 0;
int main()
{
    int input;
  	LinkStack Q;
  	LElemType x, y;
	int number;
	
do
{
  	printf("\n----------------------");
    printf("\n\n\t���˵�\n\n");
	printf("%3c1%4c��ʼ��\n",' ',' ');
	printf("%3c2%4c����\n",' ',' ');
	printf("%3c3%4c�ÿ�\n",' ',' ');
	printf("%3c4%4c�п�\n",' ',' ');
	printf("%3c5%4c�ⳤ��\n",' ',' ');
	printf("%3c6%4cȡջ��Ԫ��\n",' ',' ');
	printf("%3c7%4c��ջ\n",' ',' ');
	printf("%3c8%4c��ջ\n",' ',' ');
	printf("%3c9%4c����\n\n",' ',' ');
	printf("����������ѡ��1-8����");
	
	fflush(stdin);
  	input = scanf("%d", &number);
	while(1 != input || (number < 1 || number > 9))
	{
		printf("�����������ȷ���룺");
		fflush(stdin); 
		input = scanf("%d", &number);
	}
	
	system("cls");
	
	switch(number)
	{
	  	case 1:
	  	{
	    	InitStack(&Q, &isdestroyed);
			printf("ջ�ѳ�ʼ������ʱջΪ��ջ��\n");
			break;
	  	}
	  	case 2:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
	    	DestroyStack(&Q, &isdestroyed);
			printf("ջ������ϣ���ʱջ�����ڣ�\n");
			break;
	 	}
	  	case 3:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
	    	ClearStack(&Q);
			printf("ջ�ѱ��ÿգ���ʱջΪ��ջ��\n");
			break;
	  	}
	  	case 4:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
	    	if(StackEmpty(Q))
			{
				printf("��ʱջΪ��ջ��\n");
				break;
			}
			else
			{
				printf("��ʱջ���ǿ�ջ��\n");
				break;
			}
	  	}
	  	case 5:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("��ʱջΪ��ջ��\n");
				break;
			} 
	    	printf("ջ�ĳ���Ϊ%d\n", StackLength(Q));
			break;
	  	}
	  	case 6:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("��ʱջΪ��ջ��\n");
				break;
			}
	    	GetTop(Q, &x);
			printf("��ʱջ��Ԫ��Ϊ��%d\n", x);
			break;
	  	}
	  	case 7:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
			
	    	printf("��������ջԪ�أ�");
			fflush(stdin);
			input = scanf("%d", &y);
			while(1 != input)
			{
				printf("�����������ȷ���룺");
				fflush(stdin); 
				input = scanf("%d",&y);
			}  
	    	Push(&Q, y);
			printf("��ʱ��ջ����ջ�ױ���ջ���õ��������У�\n");
			StackTraverse(Q);
			break;
	  	}
	  	case 8:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("��ʱջΪ��ջ��\n");
				break;
			}
			
	    	Pop(&Q, &x);
			printf("��ջԪ��Ϊ��%d\n", x);
			printf("��ʱ��ջ����ջ�ױ���ջ���õ��������У�\n");
			StackTraverse(Q);
			break;
	  	}
	  	case 9:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("ջ�����ڣ�");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("��ʱջΪ��ջ��\n");
				break;
			}
			
	    	printf("��ʱ��ջ����ջ�ױ���ջ���õ��������У�\n");
			StackTraverse(Q);
			break;
	  	}
	}
}while(number <= 9);

  	return 0;
}
