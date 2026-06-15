#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
class Base{
public:
    Base(long base)
        :_base(base)
    {
        cout<<"Base(long)"<<endl;
    }
    void print(){
        cout<<"Base::base = "<<_base<<endl;
    }
private:
    long _base;
};
class Derived
:public Base
{
public:
    Derived(long base,long derived)
        :Base(base)
         ,_derived(derived)
    {
        cout<<"Derived(long,long)"<<endl;
    }
    void print(){
        cout<<"Derived::derived = "<<_derived<<endl;
    }

private:
    long _derived;
};


void test0(){
    Base base(1);
    base.print();
    Derived derived(10,100);
    derived.print();

    cout<<"==================================="
        <<endl<<"执行base = derived操作"<<endl;
    // base完成赋值操作
    base=derived;
    cout<<"base.print()";
    base.print();

}
int main()
{
    test0();
    return 0;
}

