#include <iostream>
using namespace std;
class MyString
{
public:
    MyString(const char* str = nullptr); //默认构造
    MyString(const MyString &str); //拷贝构造
    ~MyString();
    MyString& operator=(const MyString &str); //赋值构造
    void print() const;

private:
    char* _data;
    int _size;
};
