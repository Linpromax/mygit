#include "AQueue.h"

int main()
{
	AQueue * Q = NULL; //����ָ�� 
	int number, inputCorrect, e, data;
	do
  	{	
	  	printf("\n----------------------\n");
	    printf("1  ��ʼ������\n");
	    printf("2  ���ٶ���\n");
	    printf("3  �������Ƿ�Ϊ��\n");
	    printf("4  �������Ƿ�����\n");
	    printf("5  �鿴��ͷԪ��\n");
	    printf("6  ��ȡ���г���\n");
	    printf("7  ���\n");
	    printf("8  ����\n");
	    printf("9  ��ն���\n");
	    printf("10 ��������\n");
	    printf("11 �˳�\n");
		  
	    printf("\n�����������ţ�");
		fflush(stdin);
  		inputCorrect = scanf("%d", &number);
		while(1 != inputCorrect || (number < 1 || number > 11) )
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
				InitAQueue(&Q);
				break;
			}
			case 2:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������ٲ��������壡\n");
					break;
				}
			    DestoryAQueue(&Q);
			    printf("���ٳɹ�!\n"); 
				break;
			}
			case 3:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
			    if(IsEmptyAQueue(Q)) 
					printf("��ʱ����Ϊ�գ�\n");				
				else
					printf("��ʱ���в�Ϊ�գ�\n");
				break;
			}
			case 4:
			{	
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}	
			    if(IsFullAQueue(Q)) 
					printf("��ʱ����������\n");				
				else
					printf("��ʱ����δ����\n");
				break;
			}
			case 5:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
			  	if(GetHeadAQueue(Q, &e))
				  	printf("��ͷԪ��Ϊ��%d\n", e);	
				else
					printf("����Ϊ�գ�\n");	
			    break;
			}
			case 6:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				printf("���г���Ϊ%d\n", LengthAQueue(Q));
				break;
			}
			case 7:
			{
				if(NULL == Q)
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

			    if( EnAQueue(Q, &data) )	
			    	printf("��ӳɹ�!\n");
			    else
			    	printf("�������������ʧ�ܣ�\n");
				break;	
			}
			case 8:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
			  	if(DeAQueue(Q, &e))
				{
					printf("���ӳɹ�������Ԫ��Ϊ��%d\n", e); 
					break;
				}
				else
					printf("����Ϊ�գ�\n");
				break;
			}
			case 9:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				ClearAQueue(Q);
				printf("������Ϊ��.\n"); 
				break;
			}
			case 10:
			{
				if(NULL == Q)
				{
					printf("δ��ʼ�������в����ڣ�\n");
					break;
				}
				if( !TraverseAQueue(Q) )
				    printf("����Ϊ�գ�\n");
				break;
			}
			case 11: 
			{
				printf("�����˳�...\n");
				Sleep(2 * 1000); 
				return 0;
		    }
		}
  	}while(number <= 10);
  	return 0;
}
