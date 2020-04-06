#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"


int main()
{
	int input;
  	SqStack Q;
  	SElemType x, y;
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
			InitStack(&Q);
			printf("ջ�ѳ�ʼ������ʱջΪ��ջ��\n");
			break;
		}
		case 2:
		{
		    DestroyStack(&Q);
			break;
		}
		case 3:
		{
		    ClearStack(&Q);
			break;
		}
		case 4:
		{
		    if(1 == StackEmpty(Q))
			{
				printf("��ʱջΪ��ջ��\n");
			}
			else if(2 == StackEmpty(Q))
			{
				printf("��ʱջ���ǿ�ջ��\n");
			}
			else
				printf("ջ�����ڣ�");
			break;
		}
		case 5:
		{
		  	StackLength(Q); 
		    break;
		}
		case 6:
		{
		    GetTop(Q, &x);
			break;
		}
		case 7:
		{
		  	if(StackEmpty(Q))
			{
				printf("��������ջԪ�أ�");
				fflush(stdin);
		  		input = scanf("%d",&y);
				while(1 != input)
				{
				printf("�����������ȷ���룺");
				fflush(stdin); 
				input = scanf("%d",&y);
				}  
			    Push(&Q, y);
				StackTraverse(Q);
				break;
			}
			else
				printf("ջ�����ڣ�");
			break;	
		}
		case 8:
		{
		  	int n = Pop(&Q, &x);
		    if(1 == n)
				printf("��ջԪ��Ϊ��%d\n",x);
			else if(0 == n)
				printf("��ʱջ�ǿ�ջ��\n");
			break;
		}
		case 9:
		{
			StackTraverse(Q);
			break;
		}
	}
  	}while(number <= 9);
  	return 0;
}
