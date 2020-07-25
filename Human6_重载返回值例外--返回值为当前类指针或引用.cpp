#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human {
private:
	int a;
public:
	virtual void eating(void) { cout<<"use hand to eat"<<endl; }
	virtual ~Human() { cout<<"~Human()"<<endl; }
	virtual Human* test(void) {cout<<"Human's test"<<endl; return this; }
};

class Englishman : public Human {
public:
	void eating(void) { cout<<"use knife to eat"<<endl; }
	virtual ~Englishman() { cout<<"~Englishman()"<<endl; }
	virtual Englishman* test(void) {cout<<"Englishman's test"<<endl; return this; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
	virtual ~Chinese() { cout<<"~Chinese()"<<endl; }
	virtual Chinese* test(void) {cout<<"Chinese's test"<<endl; return this; }
};

void test_eating(Human& h)
{
	h.eating();
}

void test_return(Human& h)
{
	h.test();
}



int main(int argc, char **argv)
{
	Human h;
	Englishman e;
	Chinese c;

	//calm：多态虚函数返回值例外：父类和派生类的多态方法不允许有不同的返回值，除非返回值是当前类指针或类引用。
	test_return(h);
	test_return(e);
	test_return(c);


	return 0;
}


