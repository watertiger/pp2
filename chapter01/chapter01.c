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
	FILE *fp = NULL;
	clock_t start, end;
	
	start = clock();
	myrand(arr, SIZE, 42, 1);
	end = clock();
	printf("Create Random numbers takes %f seconds.\n",((double)(end-start))/1000000);
//	for ( i = 0; i < SIZE; i++) {
//		printf("%07d\t", arr[i]);
//		if (!((i + 1) % 20))
//			putchar('\n');
//	}
//	printf("\n");
	clib_sort( arr, SIZE);
//	for ( i = 0; i < SIZE; i++) {
//		printf("%07d\t", arr[i]);
//		if (!((i + 1) % 20))
//			putchar('\n');
//	}
	myrand(arr, SIZE, 42, 1);
	bitc_sort( arr, SIZE, MAX_LIMIT);

	
	
	
	return 0;
}	
	
