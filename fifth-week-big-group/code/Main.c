#include "BinaryTree.h"

int main()
{
	BiTree T;	//��ָ��
	int number, inputCorrect;
	InitBiTree(&T);		//��ʼ���ն�����
	do
  	{	
	  	printf("\n----------------------\n");
	    printf("1  ���ٶ�����\n");
	    printf("2  ���������\n");
	    printf("3  ǰ�����\n");
	    printf("4  �������\n");
	    printf("5  �������\n");
	    printf("6  �������\n");
	    printf("7  ���������Ƿ�Ϊ��\n");
	    printf("8  ��ȡ���������\n");
	    printf("9  ����ǰ׺���ʽ\n");
		printf("10 �˳�\n");
		  
	    printf("\n�����������ţ�");
		fflush(stdin);
  		inputCorrect = scanf("%d", &number);
		while (1 != inputCorrect || (number < 1 || number > 10) )
		{
			printf("�����������ȷ���룺");      
			fflush(stdin); 		
			inputCorrect = scanf("%d", &number);           //�������� 
		}  		
		
		system("cls");
	
		switch (number)
		{	  
			case 1:
			{
				if (DestroyBiTree(&T))
					printf("���ٳɹ���\n");
			    else
					printf("��ʱΪ�ն����������ٲ���������!\n"); 
				break;
			}
			case 2:
			{
				fflush(stdin);
				printf("����ǰ��ʽ������������ݣ���#Ϊ�սڵ㣺\n");
				if(CreateBiTree(&T))
					printf("���������\n");
				else
					printf("�������\n");
				break;
			}
			case 3:
			{	
				printf("ǰ�������\n");
				if (!PreOrderTraverse(T))
					printf("������Ϊ�գ�\n");
				break;
			}
			case 4:
			{
				printf("���������\n");
				if (!InOrderTraverse(T))
					printf("������Ϊ�գ�\n");
			    break;
			}
			case 5:
			{
				printf("���������\n");
				if (!PostOrderTraverse(T))
					printf("������Ϊ�գ�\n");
				break;
			}
			case 6:
			{
				printf("���������\n");
				if(!LevelOrderTraverse(T))
					printf("������Ϊ�գ�\n");
				break;	
			}
			case 7:
			{
				if (BiTreeEmpty(T))
					printf("������Ϊ��.\n");		
			  	else
					printf("��������Ϊ��.\n"); 
				break;
			}
			case 8:
			{
				printf("���������Ϊ��%d", GetDepth(T));
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
				printf("�����˳�...\n");
				return 0;
			}
		}		
	}while(1);		
	return 0;
}