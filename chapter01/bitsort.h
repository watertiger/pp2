#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//方案1和方案2共用
#define BITCHAR 8

//位数组方案1（使用乘除法）
#define BITC_NSLOT(ni) ( (ni + BITCHAR -1) / BITCHAR )
#define BITC_SLOT(i) ( (i) / BITCHAR )
#define BITC_MASK(i) ( 1 << ( (i) % BITCHAR ) )
#define BITC_SET(a,i)	( (a)[BITC_SLOT(i)] |= BITC_MASK(i) )
#define BITC_CLR(a,i)	( (a)[BITC_SLOT(i)] &= ~BITC_MASK(i) )
#define BITC_TEST(a,i)	( (a)[BITC_SLOT(i)] & BITC_MASK(i) )

//位数组方案2（使用移位和与）
#define BITCHAR_SHIFT 3
#define CHAR_MASK 0x07
#define BITCHAR_NSLOT(ni) ( (ni + BITCHAR -1) >> BITCHAR_SHIFT )
#define BITCHAR_SLOT(i) ( (i) >> BITCHAR_SHIFT)
#define BITCHAR_MASK(i) ( 1 << ( (i) & CHAR_MASK ) )
#define BITCHAR_SET(a,i)	( (a)[BITCHAR_SLOT(i)] |= BITCHAR_MASK(i) )
#define BITCHAR_CLR(a,i)	( (a)[BITCHAR_SLOT(i)] &= ~BITCHAR_MASK(i) )
#define BITCHAR_TEST(a,i)	( (a)[BITCHAR_SLOT(i)] & BITCHAR_MASK(i) )
	
//方案3和方案4共用
#define BITINT 32

//位数组方案3（使用乘除法）
#define BITI_NSLOT(ni) ( (ni + BITINT -1) / BITINT )
#define BITI_SLOT(i) ( (i) / BITINT )
#define BITI_MASK(i) ( 1 << ( (i) % BITINT ) )
#define BITI_SET(a,i)	( (a)[BITI_SLOT(i)] |= BITI_MASK(i) )
#define BITI_CLR(a,i)	( (a)[BITI_SLOT(i)] &= ~BITI_MASK(i) )
#define BITI_TEST(a,i)	( (a)[BITI_SLOT(i)] & BITI_MASK(i) )

//位数组方案4（使用移位和与）
#define BITINT_SHIFT 5
#define INT_MASK 0x1F
#define BITINT_NSLOT(ni) ( (ni + BITINT -1) >> BITINT_SHIFT )
#define BITINT_SLOT(i) ( (i) >> BITINT_SHIFT)
#define BITINT_MASK(i) ( 1 << ( (i) & INT_MASK ) )
#define BITINT_SET(a,i)	( (a)[BITINT_SLOT(i)] |= BITINT_MASK(i) )
#define BITINT_CLR(a,i)	( (a)[BITINT_SLOT(i)] &= ~BITINT_MASK(i) )
#define BITINT_TEST(a,i)	( (a)[BITINT_SLOT(i)] & BITINT_MASK(i) )

void bitc_sort(int *arr, int size, int max)
{
	int i = 0;
	char bitarray[BITC_NSLOT(max)];
	
	for(i = 0; i < max; i++)
		BITC_CLR(bitarray, i);
	clock_t start, end; //单位是ms
	start = clock();
	for( i =0; i < size; i++)
		BITC_SET(bitarray, arr[i]);
	end = clock();
	printf("BITCSORT: %f seconds used.\n", ((double)(end-start))/1000000);
	
	return;
}	
	
