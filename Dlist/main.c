#include "Dlist.h"

int main()
{   
  	int menu_choice;  //存放菜单选择项
 
  	do   //循环现实直到用户退出程序
  	{
   	menu_choice = Menu(); //菜单显示及用户选择
   	switch(menu_choice) //用户选择功能匹配
   	{
      	case create_List: 	printf("------------------\n");
		  					printf("1 创建链表\n");  
		                	Create();
					    	break;
	  	case  print_List: 	printf("------------------\n");
		  					printf("2 遍历链表\n"); 
                        	Print();
					    	break;
      	case  insert_Node: 	printf("------------------\n");
		  					printf("3 头结点后插入结点\n"); 
                         	Insert();
					     	break;
	  	case  delete_Node:  printf("------------------\n");
		  					printf("4 按值删除链表结点\n"); 
                         	Delete();
					     	break;
      	case  delete_List: 	printf("------------------\n");
		  					printf("5 删除链表\n"); 
                         	DeleteAll();
					     	break;
	  	case quit: ; 
	  	default:   	printf("退出程序..."); 
		        	return 0;
 
   }    
  }while(menu_choice!=quit);  
 
  return 0;
}
