
#include "head.h"

int main()
{
	FILE *testDataFile_1 = fopen("testData_1.txt","w+");	//10000层次测试数据文件
	FILE *sortedDataFile_1 = fopen("sortedData_1.txt","w"); //10000层次已排序数据文件
	FILE *testDataFile_2 = fopen("testData_2.txt","w+");	//50000层次
	FILE *sortedDataFile_2 = fopen("sortedData_2.txt","w");
	FILE *testDataFile_3 = fopen("testData_3.txt","w+");	//200000层次
	FILE *sortedDataFile_3 = fopen("sortedData_3.txt","w");
	FILE *testDataFile_4 = fopen("testData_4.txt","w+");	//100*100k层次
	FILE *sortedDataFile_4 = fopen("sortedData_4.txt","w");
	
	if(testDataFile_1 == NULL && sortedDataFile_1 == NULL
	&& testDataFile_2 == NULL && sortedDataFile_2 == NULL
	&& testDataFile_3 == NULL && sortedDataFile_3 == NULL
	&& testDataFile_4 == NULL && sortedDataFile_4 == NULL)
	{
		printf("文件无法打开.\n");
		return -1;
	}
	
	makeTestData(testDataFile_1, 10000);
	makeTestData(testDataFile_2, 50000);	//生成测试数据并写入文件
	makeTestData(testDataFile_3, 200000);
	
	printf("----------------------------\n");	//输出排序时长
	printf("10000层次：\n");
	showTime(testDataFile_1, sortedDataFile_1, 10000);
	printf("----------------------------\n");
	printf("50000层次：\n");
	showTime(testDataFile_2, sortedDataFile_2, 50000);
	printf("----------------------------\n");
	printf("200000层次：\n");
	showTime(testDataFile_3, sortedDataFile_3, 200000);
	printf("----------------------------\n");
	printf("100*100k层次：\n");
	showTime_2(testDataFile_4, sortedDataFile_4, 100);
	printf("----------------------------\n");
	
	fclose(testDataFile_1);
	fclose(sortedDataFile_1);
	fclose(testDataFile_2);
	fclose(sortedDataFile_2);
	fclose(testDataFile_3);
	fclose(sortedDataFile_3);
	fclose(testDataFile_4);
	fclose(sortedDataFile_4);
	system("pause");
	return 0;
}