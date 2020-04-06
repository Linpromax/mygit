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
	    	InitStack(&Q, &isdestroyed);
			printf("栈已初始化，此时栈为空栈！\n");
			break;
	  	}
	  	case 2:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
	    	DestroyStack(&Q, &isdestroyed);
			printf("栈销毁完毕，此时栈不存在！\n");
			break;
	 	}
	  	case 3:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
	    	ClearStack(&Q);
			printf("栈已被置空，此时栈为空栈！\n");
			break;
	  	}
	  	case 4:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
	    	if(StackEmpty(Q))
			{
				printf("此时栈为空栈！\n");
				break;
			}
			else
			{
				printf("此时栈不是空栈！\n");
				break;
			}
	  	}
	  	case 5:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("此时栈为空栈！\n");
				break;
			} 
	    	printf("栈的长度为%d\n", StackLength(Q));
			break;
	  	}
	  	case 6:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("此时栈为空栈！\n");
				break;
			}
	    	GetTop(Q, &x);
			printf("此时栈顶元素为：%d\n", x);
			break;
	  	}
	  	case 7:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
			
	    	printf("请输入入栈元素：");
			fflush(stdin);
			input = scanf("%d", &y);
			while(1 != input)
			{
				printf("输入错误！请正确输入：");
				fflush(stdin); 
				input = scanf("%d",&y);
			}  
	    	Push(&Q, y);
			printf("此时从栈顶到栈底遍历栈，得到如下序列：\n");
			StackTraverse(Q);
			break;
	  	}
	  	case 8:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("此时栈为空栈！\n");
				break;
			}
			
	    	Pop(&Q, &x);
			printf("出栈元素为：%d\n", x);
			printf("此时从栈顶到栈底遍历栈，得到如下序列：\n");
			StackTraverse(Q);
			break;
	  	}
	  	case 9:
	  	{
	  		if(!isdestroyed)
	  		{
	  			printf("栈不存在！");
	  			break;
			}
			else if(StackEmpty(Q))
			{
				printf("此时栈为空栈！\n");
				break;
			}
			
	    	printf("此时从栈顶到栈底遍历栈，得到如下序列：\n");
			StackTraverse(Q);
			break;
	  	}
	}
}while(number <= 9);

  	return 0;
}
