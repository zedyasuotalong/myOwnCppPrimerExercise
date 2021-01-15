#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;
typedef std::function<int(int, int)> Functor;

int sum_func(int a, int b, int c) {return a+b+c;}
int add_func(int a, int b) {return a+b;}
struct divide {
	int operator() (int a, int b) {
		return a/b;
	}
};
void generic_algorithm_14_8_3()
{
	cout<<">>>>>>>>>>>>>test func"<<__func__<<endl;
	auto f = [] (int i, int j) {
		return i*j;
	};
	auto b = std::bind(sum_func, _1, _2, 100);

	Functor f1 = add_func;
	Functor f2 = divide();
	Functor f3 = f;
	Functor f4 = b;

	cout<<f1(4, 2)<<endl;
	cout<<f2(4, 2)<<endl;
	cout<<f3(4, 2)<<endl;
	cout<<f4(4, 2)<<endl;
}
typedef std::function<void()> T_Functor;
class A {
	public:
		void setCallBack(const T_Functor & cb) {functor_ = cb;}
		void printFunctor() { functor_();}
	private:
		T_Functor functor_;
};
class B {
	public:
		B(int x):x_(x){
//			a_.setCallBack(std::bind(&B::add, this, x, 10));	// bind non-static member-function
			a_.setCallBack((std::bind(&B::addStatic, x, 10)));	// bind static member-function
		}
		void print() {
			a_.printFunctor();
		}
		static void addStatic(int a, int b) {
			cout<<"addStatic result: "<<a+b<<endl;
		}
	private:
		void add(int a, int b) {
			cout<<"add result: "<<a+b<<endl;
		}
		A a_;
		int x_;
};
void test_1()
{
	cout<<">>>>>>>>>>>>>test func"<<__func__<<endl;
	B local_b(10);
	local_b.print();
	B::addStatic(1, 2);
}
void generic_algorithm_14_8()
{
	generic_algorithm_14_8_3();
	test_1();
}

int main()
{
	std::cout<<"*************************chapter 14.8****************************\n";
	generic_algorithm_14_8();
	return 0;
}
