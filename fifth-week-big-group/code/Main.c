#include "BinaryTree.h"

int main()
{
	BiTree T;	//树指针
	int number, inputCorrect;
	InitBiTree(&T);		//初始化空二叉树
	do
  	{	
	  	printf("\n----------------------\n");
	    printf("1  销毁二叉树\n");
	    printf("2  构造二叉树\n");
	    printf("3  前序遍历\n");
	    printf("4  中序遍历\n");
	    printf("5  后序遍历\n");
	    printf("6  层序遍历\n");
	    printf("7  检查二叉树是否为空\n");
	    printf("8  获取二叉树深度\n");
	    printf("9  计算前缀表达式\n");
		printf("10 退出\n");
		  
	    printf("\n请输入操作序号：");
		fflush(stdin);
  		inputCorrect = scanf("%d", &number);
		while (1 != inputCorrect || (number < 1 || number > 10) )
		{
			printf("输入错误！请正确输入：");      
			fflush(stdin); 		
			inputCorrect = scanf("%d", &number);           //防误输入 
		}  		
		
		system("cls");
	
		switch (number)
		{	  
			case 1:
			{
				if (DestroyBiTree(&T))
					printf("销毁成功！\n");
			    else
					printf("此时为空二叉树，销毁操作无意义!\n"); 
				break;
			}
			case 2:
			{
				fflush(stdin);
				printf("请以前序方式输入二叉树数据，以#为空节点：\n");
				if(CreateBiTree(&T))
					printf("构造结束！\n");
				else
					printf("输入错误！\n");
				break;
			}
			case 3:
			{	
				printf("前序遍历：\n");
				if (!PreOrderTraverse(T))
					printf("二叉树为空！\n");
				break;
			}
			case 4:
			{
				printf("中序遍历：\n");
				if (!InOrderTraverse(T))
					printf("二叉树为空！\n");
			    break;
			}
			case 5:
			{
				printf("后序遍历：\n");
				if (!PostOrderTraverse(T))
					printf("二叉树为空！\n");
				break;
			}
			case 6:
			{
				printf("层序遍历：\n");
				if(!LevelOrderTraverse(T))
					printf("二叉树为空！\n");
				break;	
			}
			case 7:
			{
				if (BiTreeEmpty(T))
					printf("二叉树为空.\n");		
			  	else
					printf("二叉树不为空.\n"); 
				break;
			}
			case 8:
			{
				printf("二叉树深度为：%d", GetDepth(T));
				break;	
			}
			case 9:
			{
				fflush(stdin);
				Count();
				break;
			}
			case 10:
			{
				printf("正在退出...\n");
				return 0;
			}
		}		
	}while(1);		
	return 0;
}