
#include "head.h"

void makeTestData(FILE *fp, int n)
{
	srand((unsigned)(time(NULL)));	
	int i;
	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%-5d  ", rand());	//随机写入数据
	}
}

int * getTestData(FILE *fp_1, int n)
{
	int i;
	int * a = (int *)malloc(n * sizeof(int));
	if(!a)
	{
		printf("overflow!");
		exit(-1);
	}
	
	rewind(fp_1);    //把读写位置重新定义到文件头部
	
	for(i = 0; i < n; i++)
	{
		fscanf(fp_1,"%d", &a[i]);	//读取数据进数组
	}
	return a;
}

void showTime(FILE *fp_1, FILE *fp_2, int n)	//非100*100k层次时
{
	int i;
	int * a = getTestData(fp_1, n);	//获得测试数据数组
	
	clock_t start_1 = clock();		//insertSort
    insertSort(a, n);
    clock_t end_1 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);	//将已排序的数据写入另一个文件
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	free(a);
	
	a = getTestData(fp_1, n);
	clock_t start_2 = clock();		//mergeSort
    mergeSort(a, 0, n - 1);
    clock_t end_2 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	free(a);
	
	a = getTestData(fp_1, n);
	clock_t start_3 = clock();		//quickSort
    quickSort(a, 0, n - 1);
    clock_t end_3 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	free(a);
	
	a = getTestData(fp_1, n);
	clock_t start_4 = clock();		//countSort
    countSort(a,n);
    clock_t end_4 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	free(a);
	
	a = getTestData(fp_1, n);
	clock_t start_5 = clock();		//radixSort
    radixSort(a,n);
    clock_t end_5 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	
	free(a);
	a = NULL;
	
	printf("insertSort: %d ms.\n", (end_1 - start_1));
	printf("mergeSort:  %d ms.\n", (end_2 - start_2));
	printf("quickSort:  %d ms.\n", (end_3 - start_3));
	printf("countSort:  %d ms.\n", (end_4 - start_4));
	printf("radixSort:  %d ms.\n", (end_5 - start_5));
}

void showTime_2(FILE *fp_1, FILE *fp_2, int n)		//100*100k层次时
{
	int i, j;
	int * a = (int *)malloc(n * sizeof(int));
	makeTestData(fp_1, n);
	
	clock_t start_1 = clock();
	for(j = 0; j < 100000; j++)
	{
		rewind(fp_1);    		
		for(i = 0; i < n; i++)
		{
			fscanf(fp_1,"%d", &a[i]);	
		}
		insertSort(a, n);
	}
	clock_t end_1 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	
	clock_t start_2 = clock();
	for(j = 0; j < 100000; j++)
	{
		rewind(fp_1);    		
		for(i = 0; i < n; i++)
		{
			fscanf(fp_1,"%d", &a[i]);	
		}
		mergeSort(a, 0, n - 1);
	}
	clock_t end_2 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	
	clock_t start_3 = clock();
	for(j = 0; j < 100000; j++)
	{
		rewind(fp_1);    		
		for(i = 0; i < n; i++)
		{
			fscanf(fp_1,"%d", &a[i]);	
		}
		quickSort(a, 0, n - 1);
	}
	clock_t end_3 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	
	clock_t start_4 = clock();
	for(j = 0; j < 100000; j++)
	{
		rewind(fp_1);    		
		for(i = 0; i < n; i++)
		{
			fscanf(fp_1,"%d", &a[i]);	
		}
		countSort(a, n);
	}
	clock_t end_4 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	
	clock_t start_5 = clock();
	for(j = 0; j < 100000; j++)
	{
		rewind(fp_1);    		
		for(i = 0; i < n; i++)
		{
			fscanf(fp_1,"%d", &a[i]);	
		}
		radixSort(a, n);
	}
	clock_t end_5 = clock();
	for(i = 0; i < n; i++)
	{
		fprintf(fp_2, "%-5d  ", a[i]);
	}
	fprintf(fp_2, "\n\n%s\n\n", "----------");
	
	free(a);
	a = NULL;
	
	printf("insertSort: %d ms.\n", (end_1 - start_1));
	printf("mergeSort:  %d ms.\n", (end_2 - start_2));
	printf("quickSort:  %d ms.\n", (end_3 - start_3));
	printf("countSort:  %d ms.\n", (end_4 - start_4));
	printf("radixSort:  %d ms.\n", (end_5 - start_5));
	
}
		
			

