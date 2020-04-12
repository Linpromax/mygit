#include "LQueue.h"

int main()
{
	LQueue Q; //队列指针结构
	Q.front = Q.rear = NULL; 
	int number, inputCorrect, e, data;
	do
  	{	
	  	printf("\n----------------------\n");
	    printf("1  初始化队列\n");
	    printf("2  销毁队列\n");
	    printf("3  检查队列是否为空\n");
	    printf("4  查看队头元素\n");
	    printf("5  获取队列长度\n");
	    printf("6  入队\n");
	    printf("7  出队\n");
	    printf("8  清空队列\n");
	    printf("9  遍历队列\n");
	    printf("10 退出\n");
		  
	    printf("\n请输入操作序号：");
		fflush(stdin);
  		inputCorrect = scanf("%d", &number);
		while(1 != inputCorrect || (number < 1 || number > 10) )
		{
		printf("输入错误！请正确输入：");      
		fflush(stdin); 		
		inputCorrect = scanf("%d", &number);           //防误输入 
		}  		
		
		system("cls");
	
		switch(number)
		{	  
			case 1:
			{
				InitLQueue(&Q);
				break;
			}
			case 2:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，销毁操作无意义！\n");
					break;
				}
			    DestoryLQueue(&Q);
			    printf("销毁成功!\n"); 
				break;
			}
			case 3:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
			    if(IsEmptyLQueue(Q)) 
					printf("此时队列为空！\n");				
				else
					printf("此时队列不为空！\n");
				break;
			}
			case 4:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
			  	if(GetHeadLQueue(Q, &e))
				  	printf("队头元素为：%d\n", e);	
				else
					printf("队列为空！\n");	
			    break;
			}
			case 5:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
				printf("队列长度为%d\n", LengthLQueue(Q));
				break;
			}
			case 6:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
				
			  	printf("请输入入队数据：");
				fflush(stdin);
		  		inputCorrect = scanf("%d", &data);
				while(1 != inputCorrect)
				{
				printf("输入错误！请正确输入数值：");
				fflush(stdin); 
				inputCorrect = scanf("%d", &data);       //防误输入 
				}  

				EnLQueue(&Q, &data); 
			    printf("入队成功!\n");
				break;	
			}
			case 7:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
			  	if( DeLQueue(&Q, &e) )
			  		printf("出队元素为：%d\n", e);
			  	else
					printf("队列为空！\n");
				break;
			}
			case 8:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
				ClearLQueue(&Q);
				printf("队列已为空.\n"); 
				break;
			}
			case 9:
			{
				if(NULL == Q.front)
				{
					printf("未初始化，队列不存在！\n");
					break;
				}
				if( !TraverseLQueue(Q) )
				    printf("队列为空！\n");
				break;
			}
			case 10: 
			{
				printf("正在退出...\n");
				Sleep(2 * 1000); 
				return 0;
		    }
		}
  	}while(number <= 9);
  	return 0;
}
