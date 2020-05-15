#include "MyString.h"
#include <string.h>

MyString::MyString(const char* str)
{
    if(str == nullptr)  //һ��Ҫ�ж�
    {
        _data = new char[1];  //�÷ֵ�:�Կ��ַ����Զ������Ž�����־'\0'���ڴ�, ҲΪ����delete[]���ʹ��
        _data[0] = '\0';
        _size = 0;
    }
    else{
        _size = strlen(str);
        _data = new char[_size + 1];
        strcpy(_data, str);
    }
}

MyString::MyString(const MyString& str)
{
    _size = str._size;
    _data = new char[str._size + 1];
    strcpy(_data, str._data);

}

MyString::~MyString()
{
    delete[] _data;
}

MyString& MyString::operator=(const MyString &str)
{
    if(this == &str)  //�÷ֵ㣺����ַ�ֵ
        return *this;
    delete[] _data;   //�ͷ�ԭ���ڴ���Դ
    _size = strlen(str._data);
    _data = new char[_size + 1];
    strcpy(_data, str._data);
    return *this;

}
//ostream& MyString::operator<<(ostream &os = cout, const MyString &str)
//{
 //   os << "String size "<<str._size << "String"<< str.data << endl;
 //   return os;
//}
void MyString::print() const
{

    for(int iter = 0; iter < _size ; iter++){
        cout <<  _data[iter] ;
    }


};



