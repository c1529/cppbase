#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <ostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
class CowString{
public:
    CowString()
        :_pstr(new char[1+4]()+4)// 让_pstr指向第5个char ,前4个属于int类型的计数
    {
        cout<<"CowString()"<<endl;
        //初始化引用计数
        initRefcount();
    }
    CowString(const char * pstr)
        :_pstr(new char[strlen(pstr)+1+4]()+4)
    {
        cout<<"CowString(const char * pstr)"<<endl;
        strcpy(_pstr,pstr);
        initRefcount();
    }
    CowString(const CowString & rhs)
        :_pstr(rhs._pstr)//浅拷贝
    {
        cout<<"CowString(const CowString & rhs)"<<endl;
        increaseRefcount();
    }
    CowString & operator=(const CowString &rhs){//赋值运算符的重载    
        cout<<"CowString & operator=(const CowString &rhs)"<<endl;
        if(this!=&rhs){
            release();//这一步跟析构函数差不多
                      //浅拷贝同时引用计数加1
            _pstr=rhs._pstr;
            increaseRefcount();
        }
        return *this;
    }

    const char * c_str() const {return _pstr;}
    int size() const {return strlen(_pstr);}
    int getRefcount() const {return *(int*)(_pstr-4);}
    //下标运算符无法区分是读操作还是写操作
    char & operator[](size_t idx){//读的的时候会修改_pstr地址导致refcoun=1
        if((int)idx<size()){
            if(getRefcount()>=2){
                decreaseRefcount();
                char * ptmp = new char[size()+4+1]()+4;
                strcpy(ptmp,_pstr);
                _pstr=ptmp;
                initRefcount();
            }
            return _pstr[idx];
        }else{
            static char nullchar = '\0';
            return nullchar;
        }
    }
    friend ostream & operator<<(ostream & os,const CowString &rhs);
    //析构函数
    ~CowString(){
        release();
    }
private:
    void release(){
        decreaseRefcount();
        if(getRefcount()==0){
            delete[] (_pstr-4);
            cout<<"heap data is free"<<endl;
        }
    }
    void initRefcount(){
        *(int *)(_pstr-4)=1;
    }
    void increaseRefcount(){
        (*(int*)(_pstr-4))++;
    }
    void decreaseRefcount(){
        (*(int*)(_pstr-4))--;
    }
private:
    char * _pstr;
};
ostream & operator<<(ostream & os,const CowString &rhs)
{
    os<<rhs._pstr;
    return os;
}
void test0(){
    CowString s0;
    cout<<"s0 = "<<s0<<endl;
    CowString s1("hello");
    cout<<"s1 = "<<s1<<endl;
    cout<<"s1 ' refcount = "<<s1.getRefcount()<<endl;
    CowString s2=s1;
    cout<<"s2 = "<<s2<<endl;
    cout<<"s1 ' refcount = "<<s1.getRefcount()<<endl;
    cout<<"s2 ' refcount = "<<s2.getRefcount()<<endl;
    CowString s3("world");
    cout<<"s3 = "<<s3<<endl;
    cout<<"s3 ' refcount = "<<s3.getRefcount()<<endl;
    s3=s1;
    cout<<"s3 = "<<s3<<endl;
    cout<<"s1 ' refcount = "<<s1.getRefcount()<<endl;
    cout<<"s2 ' refcount = "<<s2.getRefcount()<<endl;
    cout<<"s3 ' refcount = "<<s3.getRefcount()<<endl;
    s3[0]='H';
    cout<<"s3 = "<<s3<<endl;
    cout<<"s1 ' refcount = "<<s1.getRefcount()<<endl;
    cout<<"s2 ' refcount = "<<s2.getRefcount()<<endl;
    cout<<"s3 ' refcount = "<<s3.getRefcount()<<endl;

}
int main()
{
    test0();
    return 0;
}

