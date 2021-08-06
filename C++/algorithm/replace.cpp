//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // 定义了greater<int>()

using namespace std;

template <class T>
struct display
{
	void operator()(const T&x) const
	{
		cout << x << " ";
	}
};

int main(int argc, char* argv[])
{
	int iarr[] = { 8, 10, 7, 8, 6, 6, 7, 8, 6, 7, 8 };
	vector<int> iv(iarr, iarr + sizeof(iarr) / sizeof(int));

	/*** replace: 将指定范围内所有等于vold的元素都用vnew代替。 ***/
	//  原型： void replace(_FwdIt _First, _FwdIt _Last, const _Ty& _Oldval, const _Ty& _Newval)
	// 将容器中6 替换为 3   
	replace(iv.begin(), iv.end(), 6, 3);
	cout << "replace(iv): ";
	for_each(iv.begin(), iv.end(), display<int>()); // 由于_X是static 所以接着 增长
	cout << endl; // iv:8 10 7 8 3 3 7 8 3 7 8   

	/*** replace_copy: 与replace类似，不过将结果写入另一个容器。 ***/
	//  原型： _OutIt replace_copy(_InIt _First, _InIt _Last, _OutIt _Dest, const _Ty& _Oldval, const _Ty& _Newval)
	vector<int> iv2(12);
	// 将容器中3 替换为 5，并将结果写入另一个容器。  
	replace_copy(iv.begin(), iv.end(), iv2.begin(), 3, 5);
	cout << "replace_copy(iv2): ";
	for_each(iv2.begin(), iv2.end(), display<int>());  
	cout << endl; // iv2:8 10 7 8 5 5 7 8 5 7 8 0（最后y一个残留元素）   

	/*** replace_if: 将指定范围内所有操作结果为true的元素用新值代替。 ***/
	//  原型： void replace_if(_FwdIt _First, _FwdIt _Last, _Pr _Pred, const _Ty& _Val)
	// 将容器中小于 5 替换为 2   
	replace_if(iv.begin(), iv.end(), bind2nd(less<int>(), 5), 2);
	cout << "replace_copy(iv): ";
	for_each(iv.begin(), iv.end(), display<int>());   
	cout << endl; // iv:8 10 7 8 2 5 7 8 2 7 8   

	/*** replace_copy_if: 与replace_if，不过将结果写入另一个容器。 ***/
	//  原型： _OutIt replace_copy_if(_InIt _First, _InIt _Last, _OutIt _Dest, _Pr _Pred, const _Ty& _Val)
	// 将容器中小于 5 替换为 2，并将结果写入另一个容器。  
	replace_copy_if(iv.begin(), iv.end(), iv2.begin(), bind2nd(equal_to<int>(), 8), 9);
	cout << "replace_copy_if(iv2): ";
	for_each(iv2.begin(), iv2.end(), display<int>()); 
	cout << endl; // iv2:9 10 7 8 2 5 7 9 2 7 8 0(最后一个残留元素)

	int iarr3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, };
	vector<int> iv3(iarr3, iarr3 + sizeof(iarr3) / sizeof(int));
	int iarr4[] = { 8, 10, 7, 8, 6, 6, 7, 8, 6, };
	vector<int> iv4(iarr4, iarr4 + sizeof(iarr4) / sizeof(int));

	/*** swap: 交换存储在两个对象中的值。 ***/
	//  原型： _OutIt replace_copy_if(_InIt _First, _InIt _Last, _OutIt _Dest, _Pr _Pred, const _Ty& _Val)
	// 将两个容器中的第一个元素交换  
	swap(*iv3.begin(), *iv4.begin());
	cout << "swap(iv3): ";
	for_each(iv3.begin(), iv3.end(), display<int>());  
	cout << endl;

	/*** swap_range: 将指定范围内的元素与另一个序列元素值进行交换。 ***/
	//  原型： _FwdIt2 swap_ranges(_FwdIt1 _First1, _FwdIt1 _Last1, _FwdIt2 _Dest)
	// 将两个容器中的全部元素进行交换  
	swap_ranges(iv4.begin(), iv4.end(), iv3.begin());
	cout << "swap_range(iv3): ";
	for_each(iv3.begin(), iv3.end(), display<int>());
	cout << endl;

	/*** unique: 清除序列中相邻的重复元素，和remove类似，它也不能真正删除元素。 ***/
	//  原型： _FwdIt unique(_FwdIt _First, _FwdIt _Last, _Pr _Pred) 
	unique(iv3.begin(), iv3.end());
	cout << "unique(iv3): ";
	for_each(iv3.begin(), iv3.end(), display<int>());
	cout << endl;

	/*** unique_copy: 与unique类似，不过把结果输出到另一个容器。 ***/
	//  原型： _OutIt unique_copy(_InIt _First, _InIt _Last, _OutIt _Dest, _Pr _Pred)
	unique_copy(iv3.begin(), iv3.end(), iv4.begin());
	cout << "unique_copy(iv4): ";
	for_each(iv4.begin(), iv4.end(), display<int>());
	cout << endl;

	return 0;
}
