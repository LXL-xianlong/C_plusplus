#ifndef _COMMON_H_
#define _COMMON_H
//����ͷ�ļ��������Ҫ�õ�ͷ�ļ��Լ������ռ�
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;

typedef unsigned char u_char;
typedef unsigned long u_long;

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
