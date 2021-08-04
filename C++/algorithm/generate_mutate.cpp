#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
struct display
{
	void operator()(const T&x) const
	{
		cout << x << " ";
	}
};
//  作用类似于上面结构体，只不过只能显示int类型的数据
void printElem(int& elem)
{
	cout << elem << " ";
}

template<class T>
struct plus2
{
	void operator()(T&x)const
	{
		x += 2;
	}

};

class even_by_two
{
private:
	static int _x; //  注意静态变量   
public:
	int operator()()const
	{
		return _x += 2;
	}
};
int even_by_two::_x = 0; //  初始化静态变量

int main(int argc, char* argv[])
{
	int iarr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> iv(iarr, iarr + sizeof(iarr) / sizeof(int));

	/*** fill: 将输入值赋给标志范围内的所有元素。 ***/
	//  原型： void fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)  
	fill(iv.begin(), iv.end(),5);
	cout << "fill: ";
	for_each(iv.begin(), iv.end(), display<int>());
	cout << endl;

	/*** fill_n: 将输入值赋给first到first+n范围内的所有元素。 ***/
	//  原型： _OutIt fill_n(_OutIt _Dest, _Diff _Count, const _Ty& _Val)
	fill_n(iv.begin(), 4, 3); //  赋4个3给iv 
	cout << "fill_n: ";
	for_each(iv.begin(), iv.end(), display<int>());
	cout << endl;

	/*** for_each: 用指定函数依次对指定范围内所有元素进行迭代访问，返回所指定的函数类型。 ***/
	//  原型： _Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	for_each(iv.begin(), iv.end(), plus2<int>()); //  每个元素+2
	cout << "for_each: ";
	for_each(iv.begin(), iv.end(), printElem); //  输出
	cout << endl;

	/*** generate: 连续调用输入的函数来填充指定的范围。 ***/
	//  原型： void generate(_FwdIt _First, _FwdIt _Last, _Fn0 _Func)
	//  使用even_by_two()函数返回的值，来填充容器iv
	generate(iv.begin(), iv.end(), even_by_two());
	cout << "generate: ";
	for_each(iv.begin(), iv.end(), display<int>());
	cout << endl;

	/*** generate_n: 与generate函数类似，填充从指定iterator开始的n个元素。 ***/
	//  原型： _OutIt generate_n(_OutIt _Dest, _Diff _Count, _Fn0 _Func)
	//  使用even_by_two()函数返回的值，来填充容器iv的前三个值
	generate_n(iv.begin(), 3, even_by_two());
	cout << "generate_n: ";
	for_each(iv.begin(), iv.end(), display<int>()); //  由于_X是static 所以接着 增长
	cout << endl;

	/*** transform: 将输入的操作作用与指定范围内的每个元素，并产生一个新的序列。 ***/
	//  原型： _OutIt transform(_InIt _First, _InIt _Last, _OutIt _Dest, _Fn1 _Func)
	// 容器的所有值全部减2
	transform(iv.begin(), iv.end(), iv.begin(), bind2nd(minus<int>(), 2));
	cout << "transform: ";
	for_each(iv.begin(), iv.end(), display<int>()); //  由于_X是static 所以接着 增长
	cout << endl;

	return 0;
}