// Test2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;//����Std���ֿռ�;
 
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
	cout << "��ͣ���������..." << endl;
    getchar();
 

	return 0;
}


void ptrswap( int *&v1 , int*&v2) {
	int *tmp =v2 ;
	v2 = v1 ;
	v1 = tmp ;
}