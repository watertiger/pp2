#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp_int(void *a, void *b)
{
	return ( *((int *)a) - *((int *)b) );
}

void clib_sort(int *arr, int size)
{
	int i = 0;
	clock_t start, end; //单位是ms
	start = clock();
	qsort( arr, size, sizeof(int), cmp_int);
	end = clock();
	printf("CLIBSORT: %f seconds used.\n", ((double)(end-start))/1000000);
	
	return;
}