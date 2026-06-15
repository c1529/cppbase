#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<ostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
class Base{
public:
    Base(const char * data)//普通构造函数
        :_data(new char[strlen(data)+1]())
    {
        cout<<"Base( const char* )"<<endl;
        strcpy(_data,data);
    }
    Base(const Base & rhs)//拷贝构造函数
        :_data(new char[strlen(rhs._data)+1]())
    {
        cout<<"Base(const Base & rhs)"<<endl;
        strcpy(_data,rhs._data);
    }
    Base & operator=(const Base & rhs){//赋值运算符号
        cout<<"Base & operator=(const Base & rhs)"<<endl;
        if(this!=&rhs){
            delete[] _data;
            _data=new char[strlen(rhs._data)+1]();
            strcpy(_data,rhs._data);
        }
        return *this;
    }
    friend ostream & operator<<(ostream &os,const Base &rhs);
private:
    char * _data;
};
ostream & operator<<(ostream &os,const Base &rhs){
    os<<rhs._data;
    return os;
}
class Derived
:public Base{
public:
    Derived(const char *data)
        :Base(data)
    {
        cout<<"Derived(const char *data)"<<endl;
    }
};

void test0(){
    Derived d1("hello");
    cout<<"d1 = "<<d1<<endl;
    Derived d2=d1;
    cout<<"d2 = "<<d2<<endl;
}
int main()
{
    test0();
    return 0;
}

