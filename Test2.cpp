// Test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;//导入Std名字空间;
 
void ptrswap( int *&v1, int *&v2 );
int _tmain(int argc, _TCHAR* argv[])
{
	int i = 10;
	int j = 100;
	int *pi = &i;
	int *pj = &j;

	cout << "Before ptrswap():\tpi: " << *pi << "\tpj: " << *pj << endl;
	ptrswap( pi, pj );
	cout << "After ptrswap():\tpi: "<< *pi << "\tpj: " << *pj << endl;
	cout << "暂停，按任意键..." << endl;
    getchar();
 

	return 0;
}


void ptrswap( int *&v1 , int*&v2) {
	int *tmp =v2 ;
	v2 = v1 ;
	v1 = tmp ;
}