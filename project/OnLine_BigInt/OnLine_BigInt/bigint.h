#ifndef _BIGINT_H_
#define _BIGINT_H_

#include"seqlist.h"

class BigInt;
ostream& operator<<(ostream &out, const BigInt &bt);

//大数据运算类
class BigInt
{
	friend ostream& operator<<(ostream &out, const BigInt &bt);
public:
	BigInt(u_long value = 0);
public:
	void LoadData(int sz);//加载数据
	void ShowData()const;
public:
	void push_back(u_char x);
	size_t size()const;
public:
	static u_char AddItem(u_char a, u_char b, u_char &sign);
	static void Add(BigInt &bt,const BigInt &bt1, const BigInt &bt2);//加法
	static void Sub(BigInt &bt,const BigInt &bt1, const BigInt &bt2);//减法
	static void Mul(BigInt &bt,const BigInt &bt1, const BigInt &bt2);//乘法
	static void Div(BigInt &bt,const BigInt &bt1, const BigInt &bt2);//除法
	static void Mod(BigInt &bt,const BigInt &bt1, const BigInt &bt2);//取模
public:
	u_char operator[](size_t pos)const;
public:
	bool operator<(const BigInt &bt)const;
	bool operator>=(const BigInt &bt)const;
	bool operator>(const BigInt &bt)const;
	bool operator<=(const BigInt &bt)const;
	bool operator==(const BigInt &bt)const;
	bool operator!=(const BigInt &bt)const;
private:
	SeqList<u_char> big;
};

#endif/*_BIGINT_H_*/
