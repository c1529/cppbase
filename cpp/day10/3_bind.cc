#include <iostream>
#include <vector>
#include <string>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
void func0(int x,int y,int & z){
    cout<<"("<<x<<" ,"<<y<<" ,"<<z<<")"<<endl;
}
void test0(){
    int a=1,b=2;
    // std::ref是一个引用包装器
    using namespace std::placeholders;
    // bind提前绑定参数时，采用值传递
    auto f = std::bind(func0,a,_1,std::ref(a));
    a=10;
    f(b);
}
int main()
{
    test0();
    return 0;
}

