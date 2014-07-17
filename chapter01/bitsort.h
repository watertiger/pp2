#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//采用char乘除法的方案
//#define BIT_CHAR_MD
//采用char与或的方案
//#define BIT_CHAR_AO
//采用int乘除法的方案
//#define BIT_INT_MD
//采用int与或的方案
#define BIT_int_AO

#ifdef BIT_CHAR_MD
	//位数组方案1（使用乘除法）
	#define BITCHAR 8
	#define BIT_NSLOT(ni) ( (ni + BITCHAR -1) / BITCHAR )
	#define BIT_SLOT(i) ( (i) / BITCHAR )
	#define BIT_MASK(i) ( 1 << ( (i) % BITCHAR ) )
	#define BIT_SET(a,i)	( (a)[BIT_SLOT(i)] |= BIT_MASK(i) )
	#define BIT_CLR(a,i)	( (a)[BIT_SLOT(i)] &= ~BIT_MASK(i) )
	#define BIT_TEST(a,i)	( (a)[BIT_SLOT(i)] & BIT_MASK(i) )
#elif defined BIT_CHAR_AO
	//位数组方案2（使用移位和与）
	#define BITCHAR 8
	#define BITCHAR_SHIFT 3
	#define CHAR_MASK 0x07
	#define BIT_NSLOT(ni) ( (ni + BITCHAR -1) >> BITCHAR_SHIFT )
	#define BIT_SLOT(i) ( (i) >> BITCHAR_SHIFT)
	#define BIT_MASK(i) ( 1 << ( (i) & CHAR_MASK ) )
	#define BIT_SET(a,i)	( (a)[BIT_SLOT(i)] |= BIT_MASK(i) )
	#define BIT_CLR(a,i)	( (a)[BIT_SLOT(i)] &= ~BIT_MASK(i) )
	#define BIT_TEST(a,i)	( (a)[BIT_SLOT(i)] & BIT_MASK(i) )
#elif defined BIT_INT_MD	
	//位数组方案3（使用乘除法）
	#define BITINT 32
	#define BIT_NSLOT(ni) ( (ni + BITINT -1) / BITINT )
	#define BIT_SLOT(i) ( (i) / BITINT )
	#define BIT_MASK(i) ( 1 << ( (i) % BITINT ) )
	#define BIT_SET(a,i)	( (a)[BIT_SLOT(i)] |= BIT_MASK(i) )
	#define BIT_CLR(a,i)	( (a)[BIT_SLOT(i)] &= ~BIT_MASK(i) )
	#define BIT_TEST(a,i)	( (a)[BIT_SLOT(i)] & BIT_MASK(i) )
#else
	//位数组方案4（使用移位和与）
	#define BITINT 32
	#define BITINT_SHIFT 5
	#define INT_MASK 0x1F
	#define BIT_NSLOT(ni) ( (ni + BITINT -1) >> BITINT_SHIFT )
	#define BIT_SLOT(i) ( (i) >> BITINT_SHIFT)
	#define BIT_MASK(i) ( 1 << ( (i) & INT_MASK ) )
	#define BIT_SET(a,i)	( (a)[BIT_SLOT(i)] |= BIT_MASK(i) )
	#define BIT_CLR(a,i)	( (a)[BIT_SLOT(i)] &= ~BIT_MASK(i) )
	#define BIT_TEST(a,i)	( (a)[BIT_SLOT(i)] & BIT_MASK(i) )
#endif

void bit_sort(int *arr, int size, int max)
{
	int i = 0;
	char bitarray[BIT_NSLOT(max)];
	
	for(i = 0; i < max; i++)
		BIT_CLR(bitarray, i);
	clock_t start, end; //单位是ms
	start = clock();
	for( i =0; i < size; i++)
		BIT_SET(bitarray, arr[i]);
	end = clock();
	printf("BITSORT: %f seconds used.\n", ((double)(end-start))/1000000);
	start = clock();
	for( i =0; i < size; i++)
		if(BIT_TEST(bitarray,i))
			printf("%07d\n", i);
	end = clock();
	printf("BITSORT: %f seconds used.\n", ((double)(end-start))/1000000);
	
	return;
}	
	
