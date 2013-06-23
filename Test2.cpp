// Test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <memory>
//nclude <fstream.h>
#include <fstream>


using namespace std;//导入Std名字空间;
using std::allocator;
using std::count_if;
using std::count;

//#define allocator string
void ptrswap( int *&v1, int *&v2 );
typedef vector<string>::difference_type diff_type;
typedef vector<string> textwords;


void ptrswap( int *&v1 , int*&v2) {
	int *tmp =v2 ;
	v2 = v1 ;
	v1 = tmp ;
}


class GreaterThan {
	public:
	GreaterThan( int sz = 6 ) : _size( sz ){}
	int size()
	{ 
		return _size;
	}
	bool operator()( const string &s1 )
	{ 
		return s1.size() > _size;
	}
	private:
	int _size;
};


class PrintElem {
	public:
	PrintElem( int lineLen = 8 ): _line_length( lineLen ), _cnt( 0 )
	{}
	void operator()( const string &elem )
	{
		++_cnt;
		if ( _cnt % _line_length == 0 )
		{ cout << '\n'; }
		cout << elem << " ";
	}
	private:
	int _line_length;
	int _cnt;
};

class LessThan {
	public:
	bool operator()( const string & s1,
	const string & s2 )
	{ return s1.size() < s2.size(); }
};



void process_vocab( vector<textwords>*pvec )
{
	if ( ! pvec ) {
	// 给出警告消息
	return;
	}
	vector< string > texts;
	vector<textwords>::iterator iter;
	for ( iter = pvec->begin(); iter != pvec->end(); ++iter )
	copy( (*iter).begin(), (*iter).end(),back_inserter( texts ));
	// 排序 texts 的元素
	sort( texts.begin(), texts.end() );
	// ok, 我们来看一看我们有什么
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n"; // 只是分隔显示输出
	// 删除重复元素
	vector<string>::iterator it;
	it = unique( texts.begin(), texts.end() );
	texts.erase( it, texts.end() );
	// ok, 让我们来看一看现在我们有什么了
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n";
	// 根据缺省的长度 6 排序元素
	// stable_sort() 保留相等元素的顺序
	stable_sort( texts.begin(), texts.end(), LessThan() );
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n";
	// 计数长度大于6 的字符串的个数
	int cnt = 0;
	// count 的过时格式——标准 C++ 已经改变了它
#if 0
	count_if( texts.begin(), texts.end(), GreaterThan(), cnt );
	cout << "Number of words greater than length six are "
	<< cnt << endl;
	static string rw[] = { "and", "if", "or", "but", "the" };
	vector<string,allocator<string>> remove_words( rw, rw+5 );
	vector<string>::iterator it2 =
	remove_words.begin();
	for ( ; it2 != remove_words.end(); ++it2 )
	{
		int cnt = 0;
		// count 的过时格式——标准 C++ 已经改变了它
		count( texts.begin(), texts.end(), *it2, cnt );
		cout << cnt << " instances removed: "
		<< (*it2) << endl;
		texts.erase(
			remove(texts.begin(),texts.end(),*it2),
			texts.end()
			);
	}
#endif
	cout << "\n\n";
	for_each( texts.begin(), texts.end(), PrintElem() );
}

int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	int i = 10;
	int j = 100;
	int *pi = &i;
	int *pj = &j;

	cout << "Before ptrswap():\tpi: " << *pi << "\tpj: " << *pj << endl;
	ptrswap( pi, pj );
	cout << "After ptrswap():\tpi: "<< *pi << "\tpj: " << *pj << endl;
#endif

#if 1
		//vector<textwords> sample;
		//vector<string,allocator<string>> t1, t2;
		//string t1fn, t2fn;
		// 要求用户输入文件
		// 实际中的程序应该做错误检查
		//cout << "text file #1: "; cin >> t1fn;
		//cout << "text file #2: "; cin >> t2fn;
		// 打开文件
		//ifstream infile1( t1fn.c_str());
		//ifstream infile2( t2fn.c_str());

		//istream_iterator< string, diff_type> input_set1(infile1),eos;
		//vector <string> text;
		//copy(input_set1,eof,back_inserter(text));
		  ifstream in_file( "input_file.txt" );
		  ofstream out_file( "output_file.txt" );
		  if( !in_file || !out_file )
		  {
		  cout << "files open failed!\n" ;
		  cout << "暂停，按任意键..." << endl;
		  getchar();
		  return -1;
		  }
		  istream_iterator< string > is( in_file );
		  istream_iterator< string > eof;
		  vector< string > text;

		  
		  copy( is, eof, back_inserter(text) );

		// 排序 texts 的元素
		//sort( texts.begin(), texts.end() );
		// ok, 我们来看一看我们有什么
		for_each( text.begin(), text.end(), PrintElem() );
		cout << "\n\n"; // 只是分隔显示输出

		sort( text.begin(), text.end() );
		cout << "after sort \n\n"; // 只是分隔显示输出
		for_each( text.begin(), text.end(), PrintElem() );
		cout << "\n\n"; // 只是分隔显示输出


		     // getchar();
		  ostream_iterator< string > os( out_file, " " );
		  copy( text.begin(), text.end(), os );
			//int cnt = 0;
		  //count_if(text.begin(),text.end(),GreaterThan(), cnt );

		  //return 0;

		// iterator 的特殊形式
		// 通常, diff_type 被缺省提供
		//istream_iterator< string, diff_type > 
		//	input_set1( infile1 ),eos;
		//istream_iterator< string, diff_type > 
		//	input_set2( infile2 );// iterator 的特殊形式
		//copy( input_set1, eos, back_inserter( t1 ));
		//copy( input_set2, eos, back_inserter( t2 ));
		//sample.push_back( t1 ); sample.push_back( t2 );
		//process_vocab( &sample );
#endif
	cout << "暂停，按任意键..." << endl;
    getchar();
 


	return 0;
}

