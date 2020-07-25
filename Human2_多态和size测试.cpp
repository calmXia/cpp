#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human {
private:
	int a; //calm���������Զ���ָ���麯�����ָ�뵼��size����
public:
	virtual void eating(void) { cout<<"use hand to eat"<<endl; }
};

class Englishman : public Human {
public:
	//calm: �������е�eating����д�����eating���Ӳ��� virtual��һ��������virtual��
	void eating(void) { cout<<"use knife to eat"<<endl; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
};
//calm������/ָ�봫�β��ж�̬
void test_eating(Human& h)
{
	//calm:��̬��ʹ����ͬ�ĵ��÷��������ڲ�ͬ���������ò�ͬ�ķ���
	h.eating();
}

int main(int argc, char **argv)
{
	Human h;
	Englishman e;
	Chinese c;

	test_eating(h);
	//calm���ֱ����������Englishman��Chinese�е�eating������
	//	���ƣ�����������Ϊ����/ָ��ʱ���ã���̬����(��������и�ָ���麯�����ָ��)
	test_eating(e);
	test_eating(c);

	cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
	cout<<"sizeof(Englishman) = "<<sizeof(e)<<endl;
	cout<<"sizeof(Chinese) = "<<sizeof(c)<<endl;

	return 0;
}


