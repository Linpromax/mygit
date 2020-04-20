
#include "head.h"

void swap(int a[], int i, int j)  
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void insertSort(int a[], int n)
{
	assert(a != NULL);	//判断数组是否存在
	
	int i, current, preIndex;
	for (i = 1; i < n; i++)
	{
		current = a[i];
		preIndex = i - 1;	//获取a[i]前一个元素的索引
		while (preIndex >= 0 && a[preIndex] > current)	//当前一个元素大于current时
		{
			a[preIndex + 1] = a[preIndex];	//后移
			preIndex--;		//从后向前扫描
		}
		a[preIndex + 1] = current;	//插入合适的位置
	}
}


void merge(int a[], int left, int mid, int right)// 合并两个已排好序的数组a[left...mid]和a[mid+1...right]
{
    int len = right - left + 1;
    int * assist = (int *)malloc(len * sizeof(int));    // 辅助空间O(n)
    int index = 0;
	int k;
    int i = left;                   // 前一数组的起始元素下标
    int j = mid + 1;                // 后一数组的起始元素下标
    while (i <= mid && j <= right)
    {
        assist[index++] = (a[i] <= a[j] ? a[i++] : a[j++]);  
    }
    while (i <= mid)	//若后一数组先遍历，将前一数组剩余元素复制到temp[]
    {
        assist[index++] = a[i++];
    }
    while (j <= right)	//若前一数组先遍历,将后一数组剩余元素复制到temp[]
    {
        assist[index++] = a[j++];
    }
    for (k = 0; k < len; k++)
    {
        a[left++] = assist[k];	//合并后复制
    }
	free(assist);
	assist = NULL;
}

void mergeSort(int a[], int left, int right)    // 递归实现的归并排序
{
	assert(a != NULL);
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;	//拆分
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);		//合并
}


int partition(int a[], int left, int right)  // 划分函数
{
	int i;
    int pivot = a[right];               // 每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (i = left; i < right; i++)   // 遍历基准以外的其他元素
    {
        if (a[i] <= pivot)               // 把小于等于基准的元素放到前一个子数组末尾
			swap(a, i, ++tail);
    }
    swap(a, right, tail + 1);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        
    return tail + 1;                    // 返回基准的索引
}

void quickSort(int a[], int left, int right)	//递归快排
{
	assert(a != NULL);
    if (left >= right)
        return;
    int pivot_index = partition(a, left, right); // 基准的索引
    quickSort(a, left, pivot_index - 1);
    quickSort(a, pivot_index + 1, right);
}



void countSort(int a[], int n)
{
	assert(a != NULL);
	int i, j = 0, max = a[0], min = a[0];
	for (i = 0; i < n; i++)		//找出范围
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];	
	}
	int range = max - min + 1;							//通过max和min计算出临时数组所需要开辟的空间大小
	int * assist = (int *)calloc(range, sizeof(int));	//使用calloc将辅助数组元素都初始化为0
														//使用辅助数组记录原始数组中每个数的个数
	for (i = 0; i < n; i++)
		assist[a[i] - min] += 1;						//这里在存储上要在原始数组数值上减去min才不会出现越界问题
	
	for (i = 0; i < range; i++)						//根据统计结果，重新对元素进行回收
		while (assist[i]--)	
			a[j++] = i + min;
	
	free(assist);
	assist = NULL;
}

int getMaxBit(int a[], int n) 
{
    int maxBit = 1; //保存最大的位数
    int i, t = 10;
    for (i = 0; i < n; i++)
    {
        while (a[i] >= t)
        {
            t *= 10;
            ++maxBit;
        }
    }
    return maxBit;
}

void radixSort(int a[], int n) //基数排序
{
	assert(a != NULL);
	
    int maxBit = getMaxBit(a, n);	 //获取最大位数
    int * assist = (int *)malloc(n * sizeof(int));
    int count[10]; 					 //计数器数组
    int i, j, k;
    int radix = 1;
	
    for (i = 1; i <= maxBit; i++)	 //进行maxBit次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0;			 //每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (a[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
		for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将assist中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到assist中
        {
            k = (a[j] / radix) % 10;
            assist[count[k] - 1] = a[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //复制
            a[j] = assist[j];
        radix *= 10;
    }
}

