#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human {
private:
	int a; //calm：用来测试多了指向虚函数表的指针导致size增大。
public:
	virtual void eating(void) { cout<<"use hand to eat"<<endl; }
};

class Englishman : public Human {
public:
	//calm: 派生类中的eating（覆写基类的eating）加不加 virtual都一样，都是virtual的
	void eating(void) { cout<<"use knife to eat"<<endl; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
};
//calm：引用/指针传参才有多态
void test_eating(Human& h)
{
	//calm:多态：使用相同的调用方法，对于不同的类对象调用不同的方法
	h.eating();
}

int main(int argc, char **argv)
{
	Human h;
	Englishman e;
	Chinese c;

	test_eating(h);
	//calm：分别调用派生类Englishman和Chinese中的eating方法。
	//	机制：（函数传参为引用/指针时采用）动态联编(类对象中有个指向虚函数表的指针)
	test_eating(e);
	test_eating(c);

	cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
	cout<<"sizeof(Englishman) = "<<sizeof(e)<<endl;
	cout<<"sizeof(Chinese) = "<<sizeof(c)<<endl;

	return 0;
}


