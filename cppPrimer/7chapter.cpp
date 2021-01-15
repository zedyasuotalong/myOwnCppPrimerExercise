#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "test.h"
using namespace std;

class Sales_data {
	public:
		Sales_data() = default;
		Sales_data(const string & s, int n, double p):bookNo_(s),nums_(n),money_(p) {}
		//explicit Sales_data(const string & s):bookNo_(s),nums_(0),money_(0) {}
		Sales_data(const string & s):bookNo_(s),nums_(0),money_(0) {}
//		Sales_data():Sales_data("", 0, 0){}	//delegating constructor, also OK
		Sales_data(istream &);
		string isbn() const {return bookNo_;}
		Sales_data & combine(const Sales_data &);
		friend Sales_data add(const Sales_data &, const Sales_data &);
		friend istream & read(istream &, Sales_data &);
		friend ostream & print(ostream &, const Sales_data &);
	private:
		string bookNo_;
		int nums_;
		double money_;
};
Sales_data::Sales_data(istream & is)
{
	read(is, *this);
}
Sales_data & Sales_data::combine(const Sales_data & r)
{
	nums_ += r.nums_;
	money_ += r.money_;
	return *this;
}
Sales_data add(const Sales_data & a, const Sales_data & b)
{
	Sales_data tmp = a;
	tmp.nums_ += b.nums_;
	tmp.money_ += b.money_;
	return tmp;
}
istream & read(istream & is, Sales_data & s)
{
	is>>s.bookNo_>>s.nums_>>s.money_;
	return is;
}
ostream & print(ostream & os, const Sales_data & s)
{
	os<<s.bookNo_<<' '<<s.nums_<<' '<<s.money_<<endl;
	return os;
}

void const_7_1_to_7_2()
{
	cout<<"test func>>>>>>>>>"<<__func__<<endl;
	Sales_data s1(cin);
	print(cout, s1);
	Sales_data s2(cin);
	print(cout, s2);
	s1.combine(s2);
	print(cout, s1);
	print(cout, add(s1,s2));
#if 0
	if (read(read(cin, s1), s2)) {
		cout<<"now print new s1 and new s2:\n";
		print(cout, s1);
		print(cout, s2);
	}
#endif
//	Sales_data s3 = "asd";	// ERROR
//	Sales_data s3("asd");	//OK
	Sales_data s3 = string("asd");
	print(cout, s3);
//	s1.combine(string("talong"));	//ERROR for  explicit constructor
}
class Window_mgr;
class Screen {
	public:
		friend Window_mgr;
//		friend Window_mgr::clear(ScreenIndex); //must declared before Screen, or compile error
		using pos = string::size_type;
		Screen(int h=0, int w=0, char c=' '):cursor_(0),height_(h),width_(w),content_(h*w, c){}
		char get() const {return content_[cursor_];}
		char get(pos r, pos c) const {return content_[r * width_ + c];}
		Screen & move(pos r, pos c) {cursor_ = r * width_ + c; return *this;}
		Screen & set(char c) {content_[cursor_] = c; return *this;}
		Screen & set(pos r, pos c, char ch) {content_[r*width_+height_] = c; return *this;}
		Screen & display() {
			cout<<content_<<endl;
			return *this;
		}
#if 1
		const Screen & display() const {
			cout<<content_<<endl;
			return *this;
		}
#endif
	private:
		pos cursor_;
		pos height_,width_;
		string content_;
};
class Window_mgr {
	public:
		using ScreenIndex = vector<Screen>::size_type;
		void clear(ScreenIndex);
		ScreenIndex addScreen(const Screen &);
	private:
		vector<Screen> screens{Screen(24, 80, ' ')};
};
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.content_ = string(s.height_ * s.width_, ' ');
}
//ScreenIndex Window_mgr::addScreen(Screen &s)	// ERROR
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size()-1;
}
class Y;
class X {
	Y *y;
	string name_;
};
class Y {
	X x;
	string name_;
};
void const_7_3_to_7_4()
{
	cout<<"test func>>>>>>>>>"<<__func__<<endl;
	Screen s1(24, 80, ' ');
	s1.move(4,0).set('#');
	cout<<s1.get()<<endl;
	Screen s2(5,3);
	s2.set('A').display();
	const Screen blank(5,3);
	blank.display();
}
class ConstRef {
	public:
	//	ConstRef(int x){ i = x; ci = x;ri = i;}	//ERROR
		ConstRef(int x):i(x),ci(x),ri(i){}	
		ConstRef(int x, int y):i(num),ci(i),ri(i){}	//OK
		static int num;
		static const int heights = 20;
//		static int get_num() {return i;}  // ERROR
		static int get_num() {return num;}
		static ConstRef a;	//OK
		ConstRef *pa; //OK
//		ConstRef b; //ERROR
	private:
		int i;
		const int ci;
		int &ri;
};
int ConstRef::num = get_num();
//const int ConstRef::heights = 30;	//ERROR duplicate initialization
const int ConstRef::heights;	//OK, just define without initializing
void const_7_5()
{
	cout<<"test func>>>>>>>>>"<<__func__<<endl;
	ConstRef(3);
	//const int a;	//ERROR
	//const int *pa;	//OK
}


int main()
{
	std::cout<<"*************************chapter 7.1~7.2****************************\n";
//	const_7_1_to_7_2();
	std::cout<<"*************************chapter 7.3~7.4****************************\n";
	const_7_3_to_7_4();
	std::cout<<"*************************chapter 7.5****************************\n";
	const_7_5();
	return 0;
}
