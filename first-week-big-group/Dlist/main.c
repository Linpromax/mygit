#include "Dlist.h"

int main()
{   
  	int menu_choice;  //��Ų˵�ѡ����
 
  	do   //ѭ����ʵֱ���û��˳�����
  	{
   	menu_choice = Menu(); //�˵���ʾ���û�ѡ��
   	switch(menu_choice) //�û�ѡ����ƥ��
   	{
      	case create_List: 	printf("------------------\n");
		  					printf("1 ��������\n");  
		                	Create();
					    	break;
	  	case  print_List: 	printf("------------------\n");
		  					printf("2 ��������\n"); 
                        	Print();
					    	break;
      	case  insert_Node: 	printf("------------------\n");
		  					printf("3 ͷ���������\n"); 
                         	Insert();
					     	break;
	  	case  delete_Node:  printf("------------------\n");
		  					printf("4 ��ֵɾ��������\n"); 
                         	Delete();
					     	break;
      	case  delete_List: 	printf("------------------\n");
		  					printf("5 ɾ������\n"); 
                         	DeleteAll();
					     	break;
	  	case quit: ; 
	  	default:   	printf("�˳�����..."); 
		        	return 0;
 
   }    
  }while(menu_choice!=quit);  
 
  return 0;
}
