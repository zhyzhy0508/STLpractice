#include "MyString.h"
#include <string.h>

MyString::MyString(const char* str)
{
    if(str == nullptr)  //一定要判断
    {
        _data = new char[1];  //得分点:对空字符串自动申请存放结束标志'\0'的内存, 也为了与delete[]配合使用
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
    if(this == &str)  //得分点：检查字符值
        return *this;
    delete[] _data;   //释放原有内存资源
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



