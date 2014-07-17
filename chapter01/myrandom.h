/**
 * @file 自定义随机数生成函数
 * @author darkwkt@gmail.com
 * @date 2014-07-13
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bitsort.h"

#define TRUE	1
#define FALSE	0
#define MAX_LIMIT 10000000

/**
 * myrand - generate a random array contains integers
 * @param arr pointer to an integer array
 * @param size the size of array
 * @param seed the seed to iniitialize the random number generator
 * @param flag the random integer generated can be repeated or not
 */
void myrand( int *arr, int size, unsigned int seed, int flag)
{
	int i = 0;
	int repeated = 0;
	char bitmap[BIT_NSLOT(MAX_LIMIT)];
	
	for ( i = 0; i < MAX_LIMIT; i++) {
		BIT_CLR( bitmap, i);
	}
	
	srand(seed);
	for ( i = 0; i < size;) {
		arr[i] = rand() % MAX_LIMIT;
		if ( flag ) {
			if ( BIT_TEST(bitmap, arr[i]) ) {
				continue;
			} else {
				BIT_SET(bitmap, arr[i]);
				i++;
			}
/**
 * 采用基本判断随机数是否重复
 			int j = 0;
			for ( j = 0; j < i; j++) {
				if ( arr[i] == arr[j] ) {
					repeated = 1;
					break;
				}
			}
			if (repeated) {
				repeated = 0;
			} else {
				i++;
			}
 */
		} else {
			i++;
		}
	}
	
	return;
}

/**
 * shuffle - 打乱数组值的顺序，完成洗牌
 * @param deck 指向一个整型数组
 * @param n_cards 数组的大小，即元素的个数
 * @param seed 自定义的随机数初始化种子，必须大于0
 */

void shuffle ( int *deck, int n_cards, unsigned int seed )
{
	int i;
	static int first_time = TRUE;
	/*
	 * 如果尚未进行初始化，用当天的当前时间作为随机数发生器。
	 */
	if ( first_time ) {
		first_time = FALSE;
		srand( (unsigned int)time( NULL ) );
	}
	/*
	 * 通过交换随机对的牌进行“洗牌”。
	 */
	if ( seed ) {
		srand(seed);
	}
	for ( i = n_cards-1; i > 0; i--) {
		int where;
		int temp;
		
		where = rand() % i;
		temp = deck[ where ];
		deck[ where ] = deck[ i ];
		deck[ i ] = temp;
	}	
}
