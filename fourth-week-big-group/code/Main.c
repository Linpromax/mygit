
#include "head.h"

int main()
{
	FILE *testDataFile_1 = fopen("testData_1.txt","w+");	//10000��β��������ļ�
	FILE *sortedDataFile_1 = fopen("sortedData_1.txt","w"); //10000��������������ļ�
	FILE *testDataFile_2 = fopen("testData_2.txt","w+");	//50000���
	FILE *sortedDataFile_2 = fopen("sortedData_2.txt","w");
	FILE *testDataFile_3 = fopen("testData_3.txt","w+");	//200000���
	FILE *sortedDataFile_3 = fopen("sortedData_3.txt","w");
	FILE *testDataFile_4 = fopen("testData_4.txt","w+");	//100*100k���
	FILE *sortedDataFile_4 = fopen("sortedData_4.txt","w");
	
	if(testDataFile_1 == NULL && sortedDataFile_1 == NULL
	&& testDataFile_2 == NULL && sortedDataFile_2 == NULL
	&& testDataFile_3 == NULL && sortedDataFile_3 == NULL
	&& testDataFile_4 == NULL && sortedDataFile_4 == NULL)
	{
		printf("�ļ��޷���.\n");
		return -1;
	}
	
	makeTestData(testDataFile_1, 10000);
	makeTestData(testDataFile_2, 50000);	//���ɲ������ݲ�д���ļ�
	makeTestData(testDataFile_3, 200000);
	
	printf("----------------------------\n");	//�������ʱ��
	printf("10000��Σ�\n");
	showTime(testDataFile_1, sortedDataFile_1, 10000);
	printf("----------------------------\n");
	printf("50000��Σ�\n");
	showTime(testDataFile_2, sortedDataFile_2, 50000);
	printf("----------------------------\n");
	printf("200000��Σ�\n");
	showTime(testDataFile_3, sortedDataFile_3, 200000);
	printf("----------------------------\n");
	printf("100*100k��Σ�\n");
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