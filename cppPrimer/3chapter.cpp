#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

void string_3_2_3_3_3_4()
{
	cout<<"test func>>>>>>>>>>>>"<<__func__<<endl;
	string a;
	getline(cin, a);
	cout<<"a = "<<a<<endl;
	auto len = a.size();	// len type is string::size_type
	cout<<"len = "<<len<<endl;
	// string a='a';	//Error
	// string a('a');	//Error
	// cout<<a + 'a'<<endl; //OK
	// cout<<'a' + a<<endl; //OK
	cout<<"isalnum(a) = "<<isalnum(a[0])<<endl;
	cout<<"isalpha(a) = "<<isalpha(a[0])<<endl;
	cout<<"isdiget(a) = "<<isdigit(a[0])<<endl;
	//int digitCnt = 0;
	decltype(a.size()) digitCnt=0; //digitCnt type is string::size_type
	for (auto c : a)
		if (isdigit(c))
			digitCnt++;
	cout<<"digitCnt = "<<digitCnt<<endl;
	for (auto & c : a)
		c = toupper(c);
	cout<<"after a = "<<a<<endl;

	const string tmp = "0123456789ABCDEF";
	string result;
	string::size_type n;
	cout<<"please input some nums:\n";
	while (cin>>n)
		if (n<tmp.size())
			result += tmp[n];
	cout<<"your hex is "<<result<<endl;

	vector<int> i_vec;
	for (int i=0; i<5; i++)
		i_vec.push_back(i);
	vector<int>::iterator it;
	for (it = i_vec.begin(); it != i_vec.end(); it++)
		cout<<"it = "<<*it<<endl;
	// cbegin and cend return vector<int>::const_iterator
	for (auto it2 = i_vec.cbegin(); it2 != i_vec.cend(); it2++)
		cout<<"it2 = "<<*it2<<endl;
	vector<int>::const_iterator c_it;
	for (c_it = i_vec.begin(); c_it != i_vec.end(); c_it++)
		cout<<"c_it = "<<*c_it<<endl;
	const vector<int> c_i_vec(10, 10);
	//for (it = c_i_vec.begin(); it != c_i_vec.end(); it++) // ERROR
	for (c_it = c_i_vec.begin(); c_it != c_i_vec.end(); c_it++)
		cout<<"c_it = "<<*c_it<<endl;

	int val = 6;
	vector<int> sorted_v;
	for (int i=0; i<20; i++)
		sorted_v.push_back(i);
	auto beg = sorted_v.begin(), end = sorted_v.end();
	auto mid = beg + (end-beg)/2;
	while (mid != end && *mid != val) {
		cout<<"*mid = "<<*mid<<endl;
		if (*mid > val)
			end = mid;
		else
			beg = mid+1;
		mid = beg + (end-beg)/2;
	}
		cout<<"last mid = "<<*mid<<endl;
}
void buf_3_5()
{
	cout<<"test func>>>>>>>>>>>>"<<__func__<<endl;
	//char buf[4] = "abcd"; //ERROR, too long initializer-string
	char buf1[4] = "abc";	//OK
	char buf2[] = "abc";	//OK

	int arr1[10], arr2[20];
	for (int i=0; i<10; i++) {
		arr1[i] = i;
	}
	for (int i=0; i<20; i++) {
		arr2[i] = i+100;
	}
//	int (*parr)[10] = arr1;	// ERROR
	int (*parr)[10] = &arr1;
	int (&rarr)[10] = arr1;
//	int *(&rparr)[10] = arr1; // rparr is reference, refer to a array, whick has 10 pointers
	cout<<"for arr1:\n";
	for (int i=0; i<10; i++) {
//		cout<<**(parr+i)<<endl; // ERROR
		cout<<*(*parr+i)<<endl;
	}
	for (int i=0; i<10; i++) {
		cout<<*(rarr+i)<<endl;
	}
	cout<<"for arr2:\n";
//	parr = &arr2;	// ERROR cannot convert ‘int (*)[20]’ to ‘int (*)[10]’ in assignment
//	for (int i=0; i<20; i++)
//		cout<<*(*parr+i)<<endl;

	int ia[] = {0, 1, 2, 3, 4, 5};
	int *be = begin(ia);
	int *en = end(ia);
	//for ( ; be != en; be++) // OK too
	for ( ; be < en; be++)
		cout<<" *be = "<<*be<<endl;

	string a("abcd");
	cout<<"a.size = "<<a.size()<<endl;
	const char *pa = a.c_str();

//	vector<int> sub_arr1(begin(arr1), begin(arr1)+4);	//OK
	vector<int> sub_arr1(arr1, arr1+4);
	for (auto & v : sub_arr1)
		cout<<"V = "<<v<<endl;

	int ia2[3][4];
	int (*pia2)[4] = ia2;
	pia2 = &ia2[2];

	int cnt=0;
	// initialize
	for (auto &row : ia2)
		for (auto &col : row) {
			col = cnt;
			cnt++;
		}
	// print way 1
	cout<<"print way 1:\n";
	for (auto &row : ia2)	//XXX
	{
		for (auto col : row) {
			cout<<col<<' ';
		}
		cout<<endl;
	}
	// print way 2 : pointer
	cout<<"print way 2:\n";
	for (auto p = ia2; p != ia2 + 3; p++) { //XXX
		for (auto q = *p; q != *p + 4; q++)
			cout<<*q<<' ';
		cout<<endl;
	}
	// print way 3
	cout<<"print way 3:\n";
	using int_array = int[4];	// OK, new format
//	typedef int int_array[4];	// OK, old format
	for (int_array *p = ia2; p != ia2 + 3; p++)
	{
		for (int *q = *p; q != *p + 4; q++)
			cout<<*q<<' ';
		cout<<endl;
	}
}

int main()
{
	std::cout<<"*************************chapter 3.2 3.3 3.4****************************\n";
//	string_3_2_3_3_3_4();
	std::cout<<"*************************chapter 3.5****************************\n";
	buf_3_5();
	return 0;
}
