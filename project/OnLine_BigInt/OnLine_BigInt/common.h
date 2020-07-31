#ifndef _COMMON_H_
#define _COMMON_H
//公共头文件引入基本要用的头文件以及命名空间
#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;


#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

template<class Type>
void Swap(Type &a, Type &b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}
#endif /*_COMMON_H_*/
