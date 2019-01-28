#include <stdio.h>

/* 访问控制
 * public: 类外部程序可以使用
 * private：类成员和方法只能被类内部使用。类外部想要直接访问类的private成员编译就会报错。
 *         需要实现该类内部方法访问其private成员。
 * 注：不写权限就默认是private权限。
 * 
 */
/*c++规范
 * 类首字母大写
 * */
class Person {
private:
    char * name;
    int age;
    char * work;

public:
    /*类内部private成员变量必须通过类内部方法才能访问*/
    void setName(char *n)
    {
        name = n;
    }

    void printInfo(void)
    {
        printf("name = %s\n", name);
    }
};

int main()
{
    Person per;
    per.setName("zhangsan");
    return 0;
}