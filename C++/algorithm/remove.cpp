#include "stdafx.h"
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
	int iarr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> iv1(iarr1, iarr1 + sizeof(iarr1) / sizeof(int));
	vector<int> iv2(9);

	/*** copy: 复制序列 ***/
	//  原型： _OutIt copy(_InIt _First, _InIt _Last,_OutIt _Dest)
	copy(iv1.begin(), iv1.end(), iv2.begin());
	cout << "copy(iv2): ";
	for_each(iv2.begin(), iv2.end(), display<int>());
	cout << endl;

	/*** copy_backward: 与copy相同，不过元素是以相反顺序被拷贝。 ***/
	//  原型： _BidIt2 copy_backward(_BidIt1 _First, _BidIt1 _Last,_BidIt2 _Dest)
	copy_backward(iv1.begin(), iv1.end(), iv2.rend());
	cout << "copy_backward(iv2): ";
	for_each(iv2.begin(), iv2.end(), display<int>());
	cout << endl;

	/*** remove: 删除指定范围内所有等于指定元素的元素。 ***/
	//  原型： _FwdIt remove(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
	remove(iv1.begin(), iv1.end(), 5); // 删除元素5
	cout << "remove(iv1): ";
	for_each(iv1.begin(), iv1.end(), display<int>());
	cout << endl;

	/*** remove_copy: 将所有不匹配元素复制到一个制定容器，返回OutputIterator指向被拷贝的末元素的下一个位置。 ***/
	//  原型： 	_OutIt remove_copy(_InIt _First, _InIt _Last,_OutIt _Dest, const _Ty& _Val)
	vector<int> iv3(8);
	remove_copy(iv1.begin(), iv1.end(), iv3.begin(), 4); // 去除4 然后将一个容器的元素复制到另一个容器
	cout << "remove_copy(iv3): ";
	for_each(iv3.begin(), iv3.end(), display<int>());
	cout << endl;

	/*** remove_if: 删除指定范围内输入操作结果为true的所有元素。 ***/
	//  原型： _FwdIt remove_if(_FwdIt _First, _FwdIt _Last, _Pr _Pred)
	remove_if(iv3.begin(), iv3.end(), bind2nd(less<int>(), 6)); //  将小于6的元素 "删除"
	cout << "remove_if(iv3): ";
	for_each(iv3.begin(), iv3.end(), display<int>());
	cout << endl;

	/*** remove_copy_if: 将所有不匹配元素拷贝到一个指定容器。 ***/
	// 原型： _OutIt remove_copy_if(_InIt _First, _InIt _Last,_OutIt _Dest, _Pr _Pred)
	//  将iv1中小于6的元素 "删除"后，剩下的元素再复制给iv3
	remove_copy_if(iv1.begin(), iv1.end(), iv2.begin(), bind2nd(less<int>(), 4));
	cout << "remove_if(iv2): ";
	for_each(iv2.begin(), iv2.end(), display<int>());
	cout << endl;

	return 0;
}