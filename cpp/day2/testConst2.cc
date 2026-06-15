#include<iostream>
using std::cout;
using std::endl;

void test0(){
    int number=1,number2=2;
    // const 在*左边，代表常量指针，指向一个常量的指针，不能够修改其值
    const int* p1=&number;
    p1 = &number2;
    cout<<"*p1 = "<<*p1<<endl;
    cout<<"p1 = "<<p1<<", &number2 = "<<&number2<<endl;
    // const 在*右边，代表指针常量，const point ,它的const属性体现在指针的属性上
    // 不能修改其指向，大可以修改其所指的值
    int *const p3 = &number;
    *p3=100;
    cout<<"*p3 = "<<*p3<<endl;

}
int main(){
    test0();
    return 0;
}

