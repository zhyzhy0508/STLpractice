#include <iostream>
using namespace std;
class MyString
{
public:
    MyString(const char* str = nullptr); //Ĭ�Ϲ���
    MyString(const MyString &str); //��������
    ~MyString();
    MyString& operator=(const MyString &str); //��ֵ����
    void print() const;

private:
    char* _data;
    int _size;
};
