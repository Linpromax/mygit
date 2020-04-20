/***************************************************************************************
 *	File Name				:	head.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Date 			:	2020.4.19
 ***************************************************************************************/


#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

/**
 *  @name        : void swap(int a[], int i, int j)
 *  @description : 交换数值
 *  @param       : 数组指针a, 元素下标i, j
 */
void swap(int a[], int i, int j);

/**
 *  @name        : void insertSort(int a[], int n)
 *  @description : 插入排序法
 *  @param       : 数组指针a, 元素个数n
 */
void insertSort(int a[], int n);

/**
 *  @name        : void merge(int a[], int left, int mid, int right)
 *  @description : 合并已排好序的两个数组
 *  @param       : 数组指针a, 下标left,mid,right
 */
void merge(int a[], int left, int mid, int right);

/**
 *  @name        : void mergeSort(int a[], int left, int right)
 *  @description : 归并排序法
 *  @param       : 数组指针a, 下标
 */
void mergeSort(int a[], int left, int right);

/**
 *  @name        : int partition(int a[], int left, int right)
 *  @description : 划分函数
 *  @param       : 数组指针a, 下标
 *  @return		 : 基准的索引
 */
int partition(int a[], int left, int right);

/**
 *  @name        : void quickSort(int a[], int left, int right)
 *  @description : 快速排序法
 *  @param       : 数组指针a, 下标
 */
void quickSort(int a[], int left, int right);

/**
 *  @name        : void countSort(int a[], int n)
 *  @description : 计数排序法
 *  @param       : 数组指针a, 元素个数n
 */
void countSort(int a[], int n);

/**
 *  @name        : int getMaxBit(int a[], int n); 
 *  @description : 获取最高位数
 *  @param       : 数组指针a, 元素个数n
 *  @return		 : 最高位数maxBit
 */
int getMaxBit(int a[], int n); 

/**
 *  @name        : void radixSort(int a[], int n)
 *  @description : 基数排序法
 *  @param       : 数组指针a, 元素个数n
 */
void radixSort(int a[], int n);

/**
 *  @name        : void makeTestData(FILE *fp, int n)
 *  @description : 生成测试数据
 *  @param       : 文件指针fp, 数据个数n
 */
void makeTestData(FILE *fp, int n);

/**
 *  @name        : int * getTestData(FILE *fp_1, int n)
 *  @description : 读取测试数据
 *  @param       : 文件指针, 数据个数n
 */
int * getTestData(FILE *fp_1, int n);

/**
 *  @name        : void showTime(FILE *fp_1, FILE *fp_2, int n)
 *  @description : 显示排序时长
 *  @param       : 文件指针, 数据个数n
 */
void showTime(FILE *fp_1, FILE *fp_2, int n);

/**
 *  @name        : void showTime_2(FILE *fp_1, FILE *fp_2, int n)
 *  @description : 显示排序时长
 *  @param       : 文件指针, 数据个数n
 */
void showTime_2(FILE *fp_1, FILE *fp_2, int n);

#endif
