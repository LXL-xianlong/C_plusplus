#ifndef _SEQ_LIST_H
#define _SEQ_LIST_H

//引入公共头文件
#include"common.h"

template<class Type>
class SeqList
{
public:
	SeqList(int sz = SEQLIST_DEFAULT_SIZE);//构造函数的声明
	SeqList(const SeqList<Type> &bt);
	SeqList& operator = (const SeqList<Type> &st);
	~SeqList();//析构声明
public:
	bool isfull()const;
	bool isempty()const;

public: 
	typedef Type& reference; 
	typedef const Type& const_reference;
public:
	void push_back(const Type &x); 
	void push_front(const Type &x); 
	void pop_back(); 
	void pop_front(); 
	reference front(); 
	reference back(); 
	const_reference back()const; 
	const_reference front()const; 
	size_t size()const; 
	void reverse(); 
	void clear(); 
	void sort(); 
	int find(const Type &key); 
	void erase(const Type &key); 
public: 
	reference operator[](int pos); 
	const_reference operator[](int pos)const;
private:
	enum {SEQLIST_DEFAULT_SIZE = 20};
private:
	Type       *base;
	size_t     capacity;
	size_t     len;
};

//////////////////////////////////////////////////////////////////////
//顺序表的实现
template<class Type>
bool SeqList<Type>::isfull()const
{
	return len >= capacity;
}
template<class Type>
bool SeqList<Type>::isempty()const
{
	return len == 0;
}
template<class Type>
SeqList<Type>::SeqList(int sz)
{
	capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	base = new Type[capacity + 1];//第一个空间暂时不存储任何数据
	len = 0;
}
template<class Type>
SeqList<Type>::~SeqList()
{
	delete []base;
	base = NULL;
	capacity = len = 0;
}

template<class Type>
void SeqList<Type>::push_back(const Type &x)//尾插
{
	if (isfull())
		ERR_EXIT("push_back");
	base[++len] = x;
}
template<class Type>
void SeqList<Type>::push_front(const Type &x)//头插
{
	if (isfull())
		ERR_EXIT("push_front");
	for (size_t i = len; i >= 1; --i)
		base[i + 1] = base[i];
	base[1] = x;
	len++;
}
template<class Type>
void SeqList<Type>::pop_back()//尾删
{
	if (isempty())
		ERR_EXIT("pop_back");
	len--;
}
template<class Type>
void SeqList<Type>::pop_front()//头删
{
	if (isempty())
		ERR_EXIT("pop_back");
	for (size_t i = 1; i < len; ++i)
		base[i] = base[i + 1];
	len--;
}
template<class Type>
typename SeqList<Type>::reference SeqList<Type>::front()//取表头元素
{
	if (isempty())
		ERR_EXIT("front");
	return base[1];
}
template<class Type>
typename SeqList<Type>::reference SeqList<Type>::back()//取表尾元素
{
	if (isempty())
		ERR_EXIT("back");
	return base[len];
}
template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::back()const
{
	if (isempty())
		ERR_EXIT("front");
	return base[1];
}
template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::front()const
{
	if (isempty())
		ERR_EXIT("back");
	return base[len];
}
template<class Type>
void SeqList<Type>::reverse()
{
	if (size() <= 1)
		return;
	size_t start = 1, end = len;
	while (start<end)
	{
		Swap(base[start],base[end]);
		start++;
		end--;
	}
}
template<class Type>
void SeqList<Type>::clear()
{len = 0;}
template<class Type>
void SeqList<Type>::sort()
{
	if (size() < 1)
		return;
	for (size_t i = 0; i <len; ++i)
	{
		for (size_t j = 1; j <=len - i - 1; ++j)
		{
			if (base[j] > base[j + 1])
			{
				Swap(base[j],base[j+1]);
			}
		}
	}
}
template<class Type>
int SeqList<Type>::find(const Type &key)
{
	for (size_t i = 1; i <= len; ++i)
	{
		if (base[i] == key)
			return i;
	}
	return -1;
}
template<class Type>
void SeqList<Type>::erase(const Type &key)
{
	int pos = find(key);
	if (pos == -1)
		return;

}
template<class Type>
size_t SeqList<Type>::size()const
{return len;}

	
template<class Type>
typename SeqList<Type>::reference SeqList<Type>::operator[](int pos)
{
	assert(pos >= 1 && pos <= len);
	return base[pos];
}
template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::operator[](int pos)const
{
	assert(pos >= 1 && pos <= len);
	return base[pos];
}
#endif /*_SEQ_LIST_H*/
