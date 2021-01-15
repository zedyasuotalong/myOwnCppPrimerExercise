#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

void generic_algorithm_10_1()
{
	cout<<">>>>>>>>>>>>>>>test func"<<__func__<<endl;
	vector<int> vi = {1, 2, 3, 4, 4, 4, 5, 6, 4, 4, 5, 5, 10};
	cout<<"print the vector<int>:\n";
	for (auto & i : vi)
		cout<<i<<' ';
	cout<<endl;
	int cnt = count(vi.begin(), vi.end(), 4);
	cout<<"the val 4 exists "<<cnt<<" times\n";
	cnt = count(vi.begin(), vi.end(), 5);
	cout<<"the val 5 exists "<<cnt<<" times\n";

	list<string> ls = {"abc", "def", "hij", "123", "456", "abc", "abc", "def", "def", "def"};
	cout<<"print the list<string>:\n";
	for (auto & s : ls)
		cout<<s<<' ';
	cout<<endl;
	int cntl = count(ls.begin(), ls.end(), "abc");
	cout<<"the string \"abc\" exists "<<cntl<<" times\n";
	cntl = count(ls.begin(), ls.end(), "def");
	cout<<"the string \"def\" exists "<<cntl<<" times\n";
}
bool isShorter(const string &s1, const string &s2)
{
	return s1.size()<s2.size();
}
void generic_algorithm_10_3_1()
{
	cout<<">>>>>>>>>>>>>>>test func"<<__func__<<endl;
	vector<int> vi = {1, 2, 3, 4, 4, 4, 5, 6, 4, 4, 5, 5, 10};
	cout<<"print the vector<int>:\n";
	for (auto & i : vi)
		cout<<i<<' ';
	cout<<endl;
	sort(vi.begin(), vi.end());
	cout<<"after sort print the vector<int>:\n";
	for (auto & i : vi)
		cout<<i<<' ';
	cout<<endl;

//	list<string> ls = {"abc", "d", "hi", "123", "456", "abcabc", "dedef", "def"};	//no random access for list
	vector<string> vs = {"abc", "d", "hi", "123", "456", "abcabc", "dedef", "def"};
	cout<<"print the list<string>:\n";
	for (auto & s : vs)
		cout<<s<<' ';
	cout<<endl;
//	sort(vs.begin(), vs.end(), isShorter);
	sort(vs.begin(), vs.end());
	cout<<"after sort print the list<string>:\n";
	for (auto & s : vs)
		cout<<s<<' ';
	cout<<endl;
}
static void display_func(int a, float b, string c, char d)
{
	cout<<"int a: "<<a<<endl;
	cout<<"float b: "<<b<<endl;
	cout<<"string c: "<<c<<endl;
	cout<<"char d: "<<d<<endl;
}
void generic_algorithm_10_3_4()
{
	cout<<">>>>>>>>>>>>>>>test func"<<__func__<<endl;
	auto g = std::bind(display_func, _2, 1.0, _1, 'C');

	g("xyz", 99);
	//g(100, "100");
}
void generic_algorithm_10_3()
{
	generic_algorithm_10_3_1();
	generic_algorithm_10_3_4();
}

int main()
{
	std::cout<<"*************************chapter 10.1****************************\n";
	generic_algorithm_10_1();
	std::cout<<"*************************chapter 10.3****************************\n";
	generic_algorithm_10_3();
	return 0;
}
