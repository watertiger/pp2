/**
 * @file chapter01.c
 * @author darkwkt@gmail.com
 * @date 2014-07-13
 *
 * 用多种方法解决一个100w调记录，每条记录都是一个7位数的整数的排序问题。
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myrandom.h"
#include "clibsort.h"

//#include "bitsort.h"

#define SIZE 1000000

int main (int argc, char** argv)
{
	int arr[SIZE];
	int i = 0;
	clock_t start, end;
	
	start = clock();
	myrand(arr, SIZE, 42, 1);
	end = clock();
	printf("Create Random numbers takes %f seconds.\n",((double)(end-start))/1000000);
//	for ( i = 0; i < SIZE; i++) {
//		printf("%07d\n", arr[i]);
//		if (!((i + 1) % 20))
//			putchar('\n');
//	}
//	printf("\n");
	
	clib_sort( arr, SIZE);
//	start = clock();
//	for ( i = 0; i < SIZE; i++) {
//		printf("%07d\n", arr[i]);
//		if (!((i + 1) % 20))
//			putchar('\n');
//	}
//	end = clock();
//	printf("\n");
//	printf("CLIBSORT output: %f seconds used.\n", ((double)(end-start))/1000000);
	
	myrand(arr, SIZE, 42, 1);
	bit_sort( arr, SIZE, MAX_LIMIT);
//	start = clock();
//	for ( i = 0; i < SIZE; i++) {
//		printf("%07d\n", arr[i]);
//		if (!((i + 1) % 20))
//			putchar('\n');
//	}
//	end = clock();
//	printf("BITCSORT output: %f seconds used.\n", ((double)(end-start))/1000000);
//	printf("\n");
	
	
	
	return 0;
}	
	
