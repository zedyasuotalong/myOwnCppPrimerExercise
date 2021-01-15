#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <initializer_list>
using namespace std;

void print_msg(initializer_list<string> ls)
{
	cout<<"print the input string: ";
	for (auto &s : ls) {
		cout<<s<<' ';
	}
	cout<<endl;
}
void smart_pointer_6_2_6()
{
	print_msg({"abcd", "xyz"});
	print_msg({"1234", "567", "8989"});
}
void smart_pointer_6_2()
{
	smart_pointer_6_2_6();	//for initializer_list
}

int main()
{
	std::cout<<"*************************chapter 6.2****************************\n";
	smart_pointer_6_2();
	return 0;
}
