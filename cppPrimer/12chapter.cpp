#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <stdio.h>
using namespace std;

class StrBlob {
	public:
		typedef vector<string>::size_type size_type;
		StrBlob();
		explicit StrBlob(initializer_list<string> ls);
		size_type size() const {return data_->size();}
		bool empty() const {return data_->empty();}
		// add/del
		void push_back(const string & s) {data_->push_back(s);}
		int pop();
		// access
		string & front();
		string & end();
		void display() const;
	private:
		shared_ptr<vector<string>> data_;
		int check(size_type i);		// zero is OK, non-zero is Error
};

StrBlob::StrBlob():data_(make_shared<vector<string>>())
{
}
StrBlob::StrBlob(initializer_list<string> ls):data_(make_shared<vector<string>>(ls))
{
}
void StrBlob::display() const
{
	if(data_->empty())
		cout<<"this is an empty string.\n";
	else {
		cout<<"now print the StrBlob:\n";
		for (const auto & s : *data_)
			cout<<s<<' ';
		cout<<endl;
	}
}
int StrBlob::pop()
{
	if (check(0) != 0)
		return 1;
	data_->pop_back();

	return 0;
}
string & StrBlob::front()
{
//	if (check(0) != 0)
//		return s;

	return data_->front();
}
string & StrBlob::end()
{
//	if (check(0) != 0)
//		return string;

	return data_->back();
}
int StrBlob::check(size_type i)
{
	if (i >= data_->size())
		return 1;
	return 0;
}

void smart_pointer_12_1_1()
{
	cout<<">>>>>>>>test func "<<__func__<<endl;
	StrBlob s1;
	{
		StrBlob s2({"abc", "def", "123"});
		s2.display();
		s1 = s2;
		s1.display();
		s2.push_back("XXX");
		s2.push_back("YYY");
		s2.display();
	}
	s1.display();
}
vector<int> * v_init()
{
	vector<int> *p = new vector<int>;

	return p;
}
void v_input(vector<int> *p)
{
	int tmp;
	cout<<"please input the int vector:\n";
	while(cin>>tmp)
		p->push_back(tmp);
}
void v_display(const vector<int> *p)
{
	cout<<"display the vector<int>:\n";
	for (const auto & i : *p)
		cout<<i<<' ';
	cout<<endl;
}
void smart_pointer_12_1_2()
{
	cout<<">>>>>>>>test func "<<__func__<<endl;
	auto p = v_init();
	v_input(p);
	v_display(p);
	delete p;
}
shared_ptr<vector<int>> shared_v_init()
{
	return make_shared<vector<int>>();
}
void shared_v_input(shared_ptr<vector<int>> &sp)
{
	int tmp;
	cout<<"internal sp.use_count() = "<<sp.use_count()<<endl;
	cout<<"please input the int vector:\n";
	while(cin>>tmp)
		sp->push_back(tmp);
}
void shared_v_display(const shared_ptr<vector<int>> sp)
{
	cout<<"internal sp.use_count() = "<<sp.use_count()<<endl;
	cout<<"display the vector<int>:\n";
	for (const auto & i : *sp)
		cout<<i<<' ';
	cout<<endl;
}
void smart_pointer_12_1_3()
{
	cout<<">>>>>>>>test func "<<__func__<<endl;
	auto sp = shared_v_init();
	cout<<"sp.use_count() = "<<sp.use_count()<<endl;
	shared_v_input(sp);
	cout<<"sp.use_count() = "<<sp.use_count()<<endl;
	shared_v_display(sp);
}
void smart_pointer_12_1_4()
{
	cout<<">>>>>>>>test func "<<__func__<<endl;
	unique_ptr<int> u1;
	unique_ptr<int> u2(new int(10));
	cout<<*u2<<endl;
//	u1 = u2;
}
void allocate_memory(char **p)
{
	*p = new char[10];
	char *pp = *p;
	pp[0] = 'H';
	pp[1] = 'e';
	pp[2] = 'l';
	pp[3] = 'l';
	pp[4] = 'o';
	pp[5] = '\0';
}
void test_1()
{
	cout<<">>>>>>>>test func "<<__func__<<endl;
	char *str;
	string *ps;
	printf("ps addr = %p\n", ps);
	auto l = [](char *a) {	// the a address is which when the shared_ptr is initialized
		printf("a addr = %p\n", a);
		cout<<"now delete a which is at "<<a<<endl;
		delete [] a;
	};
//	shared_ptr<char> p(str, l);		// ERROR, this will corruption
	printf("before allocate str addr %p\n", str);
	allocate_memory(&str);
	printf("after allocate str addr %p\n", str);
	shared_ptr<char> p(str, l);
	cout<<"p.use_count() = "<<p.use_count()<<endl;
	cout<<"str = "<<str<<endl;
}
void smart_pointer_12_1()
{
	smart_pointer_12_1_1();	// implement an StrBlob class;
//	smart_pointer_12_1_2();	// use new/delete;
	smart_pointer_12_1_3(); // use shared_ptr;
	smart_pointer_12_1_4(); // use unique_ptr;
	test_1();
}

int main()
{
	std::cout<<"*************************chapter 12.1****************************\n";
	smart_pointer_12_1();
	return 0;
}
