#include "LQueue.h"

int main()
{
	LQueue Q; //����ָ��ṹ
	Q.front = Q.rear = NULL; 
	int number, inputCorrect, e, data;
	do
  	{	
	  	printf("\n----------------------\n");
	    printf("1  ��ʼ������\n");
	    printf("2  ���ٶ���\n");
	    printf("3  �������Ƿ�Ϊ��\n");
	    printf("4  �鿴��ͷԪ��\n");
	    printf("5  ��ȡ���г���\n");
	    printf("6  ���\n");
	    printf("7  ����\n");
	    printf("8  ��ն���\n");
	    printf("9  ��������\n");
	    printf("10 �˳�\n");
		  
	    printf("\n�����������ţ�");
		fflush(stdin);
  		inputCorrect = scanf("%d", &number);
		while(1 != inputCorrect || (number < 1 || number > 10) )
		{
		printf("�����������ȷ���룺");      
		fflush(stdin); 		
		inputCorrect = scanf("%d", &number);           //�������� 
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
					printf("δ��ʼ�������ٲ��������壡\n");
					break;
				}
			    DestoryLQueue(&Q);
			    printf("���ٳɹ�!\n"); 
				break;
			}
			case 3:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
			    if(IsEmptyLQueue(Q)) 
					printf("��ʱ����Ϊ�գ�\n");				
				else
					printf("��ʱ���в�Ϊ�գ�\n");
				break;
			}
			case 4:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
			  	if(GetHeadLQueue(Q, &e))
				  	printf("��ͷԪ��Ϊ��%d\n", e);	
				else
					printf("����Ϊ�գ�\n");	
			    break;
			}
			case 5:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				printf("���г���Ϊ%d\n", LengthLQueue(Q));
				break;
			}
			case 6:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				
			  	printf("������������ݣ�");
				fflush(stdin);
		  		inputCorrect = scanf("%d", &data);
				while(1 != inputCorrect)
				{
				printf("�����������ȷ������ֵ��");
				fflush(stdin); 
				inputCorrect = scanf("%d", &data);       //�������� 
				}  

				EnLQueue(&Q, &data); 
			    printf("��ӳɹ�!\n");
				break;	
			}
			case 7:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
			  	if( DeLQueue(&Q, &e) )
			  		printf("����Ԫ��Ϊ��%d\n", e);
			  	else
					printf("����Ϊ�գ�\n");
				break;
			}
			case 8:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				ClearLQueue(&Q);
				printf("������Ϊ��.\n"); 
				break;
			}
			case 9:
			{
				if(NULL == Q.front)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				if( !TraverseLQueue(Q) )
				    printf("����Ϊ�գ�\n");
				break;
			}
			case 10: 
			{
				printf("�����˳�...\n");
				Sleep(2 * 1000); 
				return 0;
		    }
		}
  	}while(number <= 9);
  	return 0;
}
