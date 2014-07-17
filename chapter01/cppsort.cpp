/**
 * @file cppsort.cpp
 * @author darkwkt@gmail.com
 * @date 2014-07-13
 *
 * 利用C++的模版库对百万个不重复的数进行排序
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include "myrandom.h"

using namespace std;

#define SIZE 1000000

int main(void) 
{
	int arr[SIZE];
	int i = 0;
	clock_t start, end;
	set<int> S;
	set<int>::iterator j;
	
	myrand(arr, SIZE, 42, 1);
	
	start = time(NULL);
	for ( i = 0; i < SIZE; i++) {
		S.insert(arr[i]);
	}
	end = time(NULL);	
	printf("C++ sorting: %f seconds.\n",((double)(end-start))/1000000);
	
	start = time(NULL);
	for ( j = S.begin(); j != S.end(); j++) {
		std::cout << *j << "\n";
	}
	end = time(NULL);	
	printf("C++ output: %f seconds.\n",((double)(end-start))/1000000);

	return 0;
}