#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "test.h"
using namespace std;

extern int common_a;
extern const int const_b;
const int const_c = 10;
// const int const_g = 2; //XXX redefinition of ‘const int const_g’, ‘const int const_g’ previously defined in test.h

const char * test_fun()
{
	char *p = new char[3];
	p[0] = '1';
	p[1] = '2';
	p[2] = '\0';

	return p;
}

void const_2_4()
{
	cout<<"test func>>>>>>>>>"<<__func__<<endl;
	cout<<"common variable = "<<common_a<<endl;
//	cout<<"const variable = "<<const_b<<endl;	//XXX	undefined reference to `const_b', const_b is in test.cpp
	int *pc = (int *)(&const_c);	
	//*pc = 8;	//XXX this will cause Segmentation fault in runTime
	
	const int const_d = 11;
	int *pd = (int *)&const_d;
	*pd = 12;
	cout<<"const_d = "<<const_d<<endl;	// output 11
	cout<<"*pd = "<<*pd<<endl;			// output 12

	const volatile int const_e = 13;	//XXX
	int *pe = (int *)&const_e;
	*pe = 14;
	cout<<"const_e = "<<const_e<<endl;	// output 14
	cout<<"*pe = "<<*pe<<endl;			// output 14

	cout<<"const_g = "<<const_g<<endl;	// const_g is in test.h
	
	cout<<"const_h = "<<const_h<<endl; // ‘const_h’ was not declared in this scope if there is no ''

	const char *pf = test_fun();
	cout<<"*pf = "<<pf<<endl;
	delete [] pf;
}

int main()
{
	std::cout<<"*************************chapter 2.4****************************\n";
	const_2_4();
	return 0;
}
