#include <iostream>
#include <string.h>
#include <unistd.h>

/*15 抽象类
 * 纯虚函数：函数体设置为0（连空函数都不是）的虚函数。
 *		     Ex: virtual void eating(void) = 0;
 * 抽象类：含纯虚函数的类。
 * 抽象类作用：向下（派生类）定义好框架（也就是说，派生类必须要实现抽象类的纯虚函数）；
			   向上提供统一的接口（上层的应用程序可以根据抽象类的统一的函数来操作底下抽象类的派生类的对象）
 * 注：
 *  1. 抽象类不能实例化对象（编译就会出错）。也就说当意图要创建抽象类相关的对象的话，
 *     必须先实现派生类（派生类中实现抽象类中的纯虚函数），然后通过派生类创建对象。
 *  2. 派生类如果没有或者少实现抽象类中的某个纯虚函数，那么该派生类依然是个抽象类。
 */

using namespace std;

class Human {
private:
	int a;
public:
	virtual void eating(void) = 0;
	virtual void wearing(void) = 0;
	virtual void driving(void) = 0;
	virtual ~Human() { cout<<"~Human()"<<endl; }
	virtual Human* test(void) {cout<<"Human's test"<<endl; return this; }
};

class Englishman : public Human {
public:
	void eating(void) { cout<<"use knife to eat"<<endl; }
	void wearing(void) {cout<<"wear english style"<<endl; }
	void driving(void) {cout<<"drive english car"<<endl; }
	virtual ~Englishman() { cout<<"~Englishman()"<<endl; }
	virtual Englishman* test(void) {cout<<"Englishman's test"<<endl; return this; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
	void wearing(void) {cout<<"wear chinese style"<<endl; }
	//void driving(void) {cout<<"drive chinese car"<<endl; }
	virtual ~Chinese() { cout<<"~Chinese()"<<endl; }
	virtual Chinese* test(void) {cout<<"Chinese's test"<<endl; return this; }
};

class Guangximan : public Chinese {
	void driving(void) {cout<<"drive guangxi car"<<endl; }
};

int main(int argc, char **argv)
{
	//Human h;
	Englishman e;
	Guangximan g;

	return 0;
}