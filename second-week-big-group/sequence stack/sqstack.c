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
	    printf("\n\n\t主菜单\n\n");
		printf("%3c1%4c初始化\n",' ',' ');
		printf("%3c2%4c销毁\n",' ',' ');
		printf("%3c3%4c置空\n",' ',' ');
		printf("%3c4%4c判空\n",' ',' ');
		printf("%3c5%4c测长度\n",' ',' ');
		printf("%3c6%4c取栈顶元素\n",' ',' ');
		printf("%3c7%4c入栈\n",' ',' ');
		printf("%3c8%4c出栈\n",' ',' ');
		printf("%3c9%4c遍历\n\n",' ',' ');
		printf("请输入您的选择（1-8）：");
		fflush(stdin);
  		input = scanf("%d", &number);
		while(1 != input || (number < 1 || number > 9))
		{
		printf("输入错误！请正确输入：");
		fflush(stdin); 
		input = scanf("%d", &number);
		}  
		
	system("cls");
	
	switch(number)
	{	  
		case 1:
		{
			InitStack(&Q);
			printf("栈已初始化，此时栈为空栈！\n");
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
				printf("此时栈为空栈！\n");
			}
			else if(2 == StackEmpty(Q))
			{
				printf("此时栈不是空栈！\n");
			}
			else
				printf("栈不存在！");
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
				printf("请输入入栈元素：");
				fflush(stdin);
		  		input = scanf("%d",&y);
				while(1 != input)
				{
				printf("输入错误！请正确输入：");
				fflush(stdin); 
				input = scanf("%d",&y);
				}  
			    Push(&Q, y);
				StackTraverse(Q);
				break;
			}
			else
				printf("栈不存在！");
			break;	
		}
		case 8:
		{
		  	int n = Pop(&Q, &x);
		    if(1 == n)
				printf("出栈元素为：%d\n",x);
			else if(0 == n)
				printf("此时栈是空栈！\n");
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
