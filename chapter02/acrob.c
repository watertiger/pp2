/**
 * @file acrob.c
 * @author darkwkt@gmail.com
 * @date 2014-07-20
 *
 * 杂技算法实现数组循环左移。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int i, int j)
{
	for(; i != j;){
		if ( i > j ) {
			i -= j;
		} else {
			j -= i;
		}
	}
	
	return i;
}	

/**
 *
 * @param s 待处理的字符串数组
 * @param r 循环左移的位数
 * @param n 数组s的长度
 */
int acrob(char *s, int r, int n)
{
	int i = 0, j = 0, k = 0;
	char t = 0;
	int g = gcd(r, n);
	printf("gcd(r,n) = %d\n", g);
	for( ; i < g; i++) {
		t = s[i];
		j = i;
		printf("In loop i1: s=%s	j=%d k=%d i=%d\n\n", s, j, k,i);
		for (;;) {
			k = j + r;
			
			if ( k >= n) 
				k -= n;
			if ( k == i) {
				break;
			}
			printf("In loop j1: s=%s	j=%d k=%d i=%d\n", s, j, k,i);
			s[j] = s[k];
			j = k;
			//printf("In loop j2: s=%s	j=%d k=%d i=%d\n", s, j, k,i);
		}
		s[j] = t;
		printf("In loop i2: s=%s	j=%d k=%d i=%d\n\n", s, j, k,i);
	}
}
	
int main()
{
	
	//char *s="abcdefgh";
	char s[] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
	acrob(s, 3, strlen(s));
	printf("%s\n", s);
	
	return 0;
}